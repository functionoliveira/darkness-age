#include <cmath>

class BattleSystemInterface : public Interface, public BattleSystem
{
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
            PrintTextAndNewLine("Suas opcoes sao:");
            PrintTextAndNewLine("1 -> Correr", 0);
            PrintTextAndNewLine("        ", 0);
            PrintTextAndNewLine("2 -> Atacar", 0);
            PrintTextAndNewLine("        ", 0);
            PrintTextAndNewLine("3 -> Ataque Especial", 0);
            PrintTextAndNewLine("        ", 0);
            PrintTextAndNewLine("4 -> Usar Item", 0);
            PrintTextAndNewLine("        ", 0);
            PrintTextAndNewLine("5 -> Esperar");
        }

        void PrintLife(Person* p)
        {
            int life = ceil(p->GetHitpointsPercent() * 10);
            PrintTextAndNewLine(p->GetName() + " => [", 0);
            for(int i = 0; i < 10; i++)
            {
                if (i < life)
                {
                    PrintTextAndNewLine("#", 0);
                }
                else
                {
                    PrintTextAndNewLine(" ", 0);
                }
            }
            PrintTextAndNewLine("]", 0);
        }

        void HandleAction(int option)
        {
            switch (static_cast<ActionType>(option))
            {
            case ActionType::RUN:
                Run();
                PrintTextAndNewLine(attacker->GetName() + " resolve fugir...");
                RemoveActionPoint(3);
                break;
            case ActionType::ATTACK:
                if (Attack() > 0)
                {
                    PrintTextAndNewLine(attacker->GetName() + " acertou o golpe!");
                }
                else
                {
                    PrintTextAndNewLine(attacker->GetName() + " errou o golpe!");
                }
                RemoveActionPoint(3);
                break;
            case ActionType::SPECIAL_ATTACK:
                SpecialAttack();
                PrintTextAndNewLine(attacker->GetName() + " dispara um ataque especial");
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
                break;
            }
        }
};