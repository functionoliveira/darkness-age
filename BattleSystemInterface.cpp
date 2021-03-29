#include <cmath>

class BattleSystemInterface : public Interface, public BattleSystem
{
    public:
        BattleSystemInterface(Person* p, Person* e) : BattleSystem(p, e) { }

        void StartTurn()
        {
            if (!CheckSomeoneHasAction()) NextTurn();
            int damage = NextMove();
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("TURNO " + std::to_string(turn));
            PrintLife(player);
            PrintTextAndNewLine("            ", 0);
            PrintLife(enemy);
            NewLine();
            PrintTextAndNewLine(attacker->GetName() + " esta pronto para realizar a acao...", 0);  
            PrintTextAndNewLine(" deu " + std::to_string(damage) + " de dano!");
            Continue("Proximo turno...");

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
};