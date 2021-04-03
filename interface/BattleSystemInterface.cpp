#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include "../battle/BattleSystem.cpp"

using namespace std;
class BattleSystemInterface : public Interface, public BattleSystem
{
    private:
        string scapetext = "Proximo turno...";
        string action;
        string actionoption;
        list<Action> actions = {
            Action(1, "Fugir", 3),
            Action(2, "Atacar", 3),
            Action(3, "Ataque Magico", 3),
            Action(4, "Usar Pocao", 2),
            Action(5, "Esperar", 1),
        };
    public:
        BattleSystemInterface(Person* p, Person* e) : BattleSystem(p, e) { }

        void Start()
        {
            action = "";
            if (!CheckSomeoneHasAction()) NextTurn();
            NextMove();

            if (isPlayerTurn)
            {
                PrintAction();
                NewLine(2);
                MenuPlayerChoices();
                HandleAction(Continue("-> "));
            }
            else
            {
                HandleAction(((rand() % 3) + 2));
            }

            PrintAction();
            CheckIsGameOver();
            PrintResultOfBattle();
            NewLine(2);
            Continue(scapetext);
        }

        void PrintAction()
        {
            int playerbarsize, enemybarsize;
            ClearScreen();
            NewLine();
            PrintSumLine("", -1);
            PrintSumLine("TURNO " + to_string(turn), 45);
            PrintSumLine("", -1);
            PrintTextAndNewLine("+{ ", 0);
            playerbarsize = PrintPersonLifeBarWithoutFormat(player);
            PrintTextAndNewLine(" }", 0);
            PrintSumLine("", -1, (100 - playerbarsize - 5));
            PrintTextAndNewLine("+{ ", 0);
            enemybarsize = PrintPersonLifeBarWithoutFormat(enemy);
            PrintTextAndNewLine(" }", 0);
            PrintSumLine("", -1, (100 - enemybarsize - 5));
            if (action != "")
            {
                PrintSumLine(attacker->GetName() + " se prepara para " + actionoption, 1);
                PrintSumLine(action, 1);
            }
            PrintSumLine("", -1);
        }

        void PrintResultOfBattle()
        {
            if (Result == BattleResult::Win)
            {
                PrintSumLine("", -1);
                PrintSumLine("A VITORIA E SUA!", 40);
                PrintSumLine("", -1);
                scapetext = "Sair... ";
                return;
            }

            if (Result == BattleResult::Loose)
            {
                PrintSumLine("", -1);
                PrintSumLine("VOCE NAO SUPORTOU!", 40, 100, 12);
                PrintSumLine("", -1);
                scapetext = "Sair... ";
                return;
            }

            if (Result == BattleResult::Run)
            {
                PrintSumLine("", -1);
                PrintSumLine("VOCE CONSEGUIU FUGIR!", 38, 100, 14);
                PrintSumLine("", -1);
                scapetext = "Sair... ";
                return;
            }
        }

        void MenuPlayerChoices()
        {
            list<Action> availables = MappingActionsAvailable(actions);
            map<int, string> items;
            // Mapping list of Action object to list of string
            for(const Action &a : availables) { items.insert(make_pair(a.id, a.name)); }
            BuildAndPrintMenu("Suas opcoes sao:", items, false);
            NewLine();
        }

        void HandleAction(int option)
        {
            int attack;
            list<Action>::iterator it = actions.begin();
            advance(it, option-1);
            if(!HasPointsToDoAction(*it))
            {
                action = "sua tentativa demora demais e seu adversario toma a iniciativa";
                RemoveActionPoint(3);
                return;
            }

            switch (static_cast<ActionType>(option))
            {
            case ActionType::RUN:
                Run();
                actionoption = "fugir";
                action = "sua fuga foi bem sucedida";
                RemoveActionPoint(3);
                break;
            case ActionType::ATTACK:
                attack = Attack();
                actionoption = "atacar";
                if (attack > 0)
                {
                    action = "ele acerta o golpe!";
                }
                else if(attack == -1000)
                {
                    action = "ele erra o golpe!";
                }
                else
                {
                    action = "ele acerta o golpe mas nao causa dano";
                }
                RemoveActionPoint(3);
                break;
            case ActionType::SPECIAL_ATTACK:
                SpecialAttack();
                actionoption = "usar ataque magico";
                action = "ele dispara um missel magico";
                RemoveActionPoint(3);
                break;
            case ActionType::ITEM:
                UseItem();
                actionoption = "usar uma pocao de cura";
                action = "apos bebe-la sente sua vida revigorada";
                RemoveActionPoint(2);
                break;
            case ActionType::AWAIT:
                actionoption = "aguardar";
                action = "ele resolve esperar por seu adversario";
                Await();
                break;
            default:
                actionoption = "aguardar";
                action = "ele resolve esperar por seu adversario";
                break;
            }
        }
};