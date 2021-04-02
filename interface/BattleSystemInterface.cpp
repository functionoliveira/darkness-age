#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include "../battle/BattleSystem.cpp"

using namespace std;
class BattleSystemInterface : public Interface, public BattleSystem
{
    private:
        list<Action> actions = {
            Action(1, "Run", 3),
            Action(2, "Atacar", 3),
            Action(3, "Ataque especial", 3),
            Action(4, "Usar Pocao", 2),
            Action(5, "Esperar", 1),
        };
    public:
        BattleSystemInterface(Person* p, Person* e) : BattleSystem(p, e) { }

        void Start()
        {
            if (!CheckSomeoneHasAction()) NextTurn();
            NextMove();
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("TURNO " + std::to_string(turn));
            PrintLife(player);
            PrintTextAndNewLine("            ", 0);
            PrintLife(enemy);
            NewLine();
            PrintTextAndNewLine(attacker->GetName() + " ira realizar a acao... ", 0);

            if (isPlayerTurn)
            {
                MenuPlayerChoices();
                HandleAction(Continue("-> "));
            }
            else
            {
                HandleAction(2);
            }

            NewLine();
            CheckIsGameOver();
            PrintResultOfBattle();

            Continue("Proximo turno... ");
        }

        void PrintResultOfBattle()
        {
            if (Result == BattleResult::Win)
            {
                NewLine();
                PrintTextAndNewLine("A vitoria e sua!");
                return;
            }

            if (Result == BattleResult::Loose)
            {
                NewLine();
                PrintTextAndNewLine("A batalha foi dura demais e voce nao suportou!");
                return;
            }

            if (Result == BattleResult::Run)
            {
                NewLine();
                PrintTextAndNewLine("Voce conseguiu escapar da batalha!");
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
                PrintTextAndNewLine("Sua tentativa foi muito demorada e seu adversario toma a iniciativa...");
                RemoveActionPoint(3);
                return;
            }

            switch (static_cast<ActionType>(option))
            {
            case ActionType::RUN:
                Run();
                PrintTextAndNewLine(attacker->GetName() + " resolve fugir...");
                RemoveActionPoint(3);
                break;
            case ActionType::ATTACK:
                attack = Attack();
                if (attack > 0)
                {
                    PrintTextAndNewLine(attacker->GetName() + " acertou o golpe!");
                }
                else if(attack == -1000)
                {
                    PrintTextAndNewLine(attacker->GetName() + " errou o golpe!");
                }
                else
                {
                    PrintTextAndNewLine(attacker->GetName() + " acertou o golpe mas nao causou dano!");
                }
                RemoveActionPoint(3);
                break;
            case ActionType::SPECIAL_ATTACK:
                SpecialAttack();
                PrintTextAndNewLine(attacker->GetName() + " dispara um missel magico...");
                RemoveActionPoint(3);
                break;
            case ActionType::ITEM:
                UseItem();
                PrintTextAndNewLine(attacker->GetName() + " vai usar uma pocao de cura...");
                RemoveActionPoint(2);
                break;
            case ActionType::AWAIT:
                PrintTextAndNewLine(attacker->GetName() + " resolve esperar por seu adversario...");
                RemoveActionPoint(1);
                break;
            default:
                PrintTextAndNewLine(attacker->GetName() + " resolve esperar por seu adversario...");
                break;
            }
        }
};