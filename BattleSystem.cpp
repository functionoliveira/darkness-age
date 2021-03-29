#include <list>
#include <iterator>
#include <cmath>
#include <iostream>

class BattleSystem
{
    public:
        BattleSystem(Person* p, Person* e)
        {
            player = p;
            enemy = e;
            turn = 0;
        }

        enum class AttackType
        {
            PHYSICAL,
            MAGIC,
            PSYCHIC
        };

        enum class BattleResult
        {
            NotOver,
            Win,
            Loose,
            Run
        };

        void NextTurn()
        {
            playeraction += 3 + (player->GetAgility() * 0.05);
            enemyaction += 3 + (enemy->GetAgility() * 0.05);
            turn++;
        }

        int NextMove()
        {            
            int damage = 0;

            if (CheckWhoIsTheAction())
            {
                attacker = player;
                defender = enemy;
                damage = Attack();
                playeraction -= 3;
            }
            else
            {
                attacker = enemy;
                defender = player;
                damage = Attack();
                enemyaction -= 3;
            }

            CheckIsGameOver();
            return damage;
        }

        BattleResult GetResult() const
        {
            return Result;
        }
    
    protected:
        int playeraction = 0;
        int enemyaction = 0;
        Person* player;
        Person* enemy;
        Person* attacker;
        Person* defender;
        bool isPlayerTurn = true;
        int turn;
        BattleResult Result = BattleResult::NotOver;

        int Attack ()
        {
            bool dodge = Dodge();

            if (!dodge)
            {
                int damage = CalcDamage(AttackType::PHYSICAL);
                ApplyDamage(damage);
                return damage;
            }

            return -1;
        }

        bool Dodge()
        {
            int evasionbonus = rand() % 10;
            int precisionbonus = rand() % 10;
            float multiply[] = { 0.0, 1.6, 1.65, 1.7, 1.75, 1.8, 1.85, 1.9, 1.95, 2.0 };

            int dodge = (defender->GetEvasion() * multiply[evasionbonus]) - (attacker->GetPrecision() * multiply[precisionbonus]);

            return dodge > 0 ? true : false;
        }

        int CalcDamage(AttackType attacktype)
        {
            switch (attacktype)
            {
                case AttackType::PHYSICAL:
                    return attacker->GetPhysicaldamage() - (defender->GetArmor() * 0.6);
                    break;
                case AttackType::MAGIC:
                    return attacker->GetMagicdamage();
                    break;
                case AttackType::PSYCHIC:
                    return attacker->GetPsychicdamage();
                    break;
                default:
                    return attacker->GetPhysicaldamage() - (defender->GetArmor() * 0.6);
                    break;
            }
            
        }

        void ApplyDamage(int damage)
        {
            defender->SetDamage(damage);
        }

        void CheckIsGameOver()
        {
            if (player->GetHitpoints() <= 0)
            {
                Result = BattleResult::Loose;
            }
            
            if (enemy->GetHitpoints() <= 0)
            {
                Result = BattleResult::Win;
            }
        }

        bool CheckWhoIsTheAction()
        {
            float playerinitiative = (rand() % 10);
            float enemyinitiative = (rand() % 10);

            if (enemyaction == playeraction)
            {
                return (playerinitiative * player->GetAgility())
                    >= (enemyinitiative * enemy->GetAgility());
            } 

            return playeraction > enemyaction;
        }

        bool CheckSomeoneHasAction()
        {
            if (playeraction > 0 || enemyaction > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};