#include <list>
#include <iterator>
#include <cmath>
#include <iostream>
#include <list>

using namespace std;
class BattleSystem
{
    public:
        enum class BattleResult
        {
            NotOver,
            Win,
            Loose,
            Run
        };

        BattleResult GetResult() const
        {
            return Result;
        }

    protected:
        enum class AttackType
        {
            PHYSICAL,
            MAGIC,
            PSYCHIC
        };

        enum class ActionType
        {
            RUN = 1,
            ATTACK = 2,
            SPECIAL_ATTACK = 3,
            ITEM = 4,
            // RTTE = 5, /* Run to the enemy */
            // KAFTE = 6, /* Keep away from the enemy */
            AWAIT = 5
        };

        int playerextraaction = 0;
        int enemyextraaction = 0;
        int playeraction = 0;
        int enemyaction = 0;
        float multiply[20];
        Person* player;
        Person* enemy;
        Person* attacker;
        Person* defender;
        bool isPlayerTurn = true;
        int turn;
        BattleResult Result = BattleResult::NotOver;

        BattleSystem(Person* p, Person* e)
        {
            player = p;
            enemy = e;
            turn = 0;
            multiply[0] = 0.0;
            multiply[1] = 1.0;
            multiply[19] = 5.0;
            for (int i = 2; i < 19; i++)
            {
                multiply[i] = 1.1 + (i * 0.05);
            }
        }

        void NextTurn()
        {
            playeraction += 3 + (player->GetAgility() * 0.05) + playerextraaction;
            enemyaction += 3 + (enemy->GetAgility() * 0.05) + enemyextraaction;
            playerextraaction = 0;
            enemyextraaction = 0;
            turn++;
        }

        void NextMove()
        {
            if (CheckIsPlayerAction())
            {
                isPlayerTurn = true;
                attacker = player;
                defender = enemy;
            }
            else
            {
                isPlayerTurn = false;
                attacker = enemy;
                defender = player;
            }
        }

        bool Dodge()
        {
            int evasionbonus = rand() % 20;
            int precisionbonus = rand() % 20;
            float dodge = (defender->GetEvasion() * multiply[evasionbonus]) - (attacker->GetPrecision() * multiply[precisionbonus]);
            return dodge > 0.0 ? true : false;
        }

        int CalcDamage(AttackType attacktype)
        {
            switch (attacktype)
            {
                float critical;
                int dmg;
                case AttackType::PHYSICAL:
                    critical = CalcCritical();
                    dmg = ceil(attacker->GetPhysicaldamage() * critical);
                    return dmg - (defender->GetArmor() * 0.6);
                case AttackType::MAGIC:
                    critical = CalcCritical();
                    dmg = ceil(((rand() % 8) + (2* attacker->GetLevel()) + attacker->GetMagicdamage()) * critical);
                    return dmg - (defender->GetArmor() * 0.2);
                case AttackType::PSYCHIC:
                    return attacker->GetPsychicdamage();
                    break;
                default:
                    return attacker->GetPhysicaldamage() - (defender->GetArmor() * 0.6);
                    break;
            }   
        }

        float CalcCritical()
        {
            float random = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) + 1.0;
            return attacker->GetCritical() > random ? attacker->GetCriticaldamage() : 1;
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

        bool CheckIsPlayerAction()
        {
            int playerinitiative = (rand() % 20);
            int enemyinitiative = (rand() % 20);

            if (enemyaction == playeraction)
            {
                return (playerinitiative + player->GetAgility())
                    >= (enemyinitiative + enemy->GetAgility());
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

        // ACTIONS HANDLERS
        int Attack()
        {
            if (!Dodge())
            {
                int damage = CalcDamage(AttackType::PHYSICAL);
                ApplyDamage(damage);
                return damage;
            }

            return -1000;
        }

        int SpecialAttack()
        {
            bool dodge = Dodge();

            if (!dodge)
            {
                int damage = CalcDamage(AttackType::MAGIC);
                ApplyDamage(damage);
                return damage;
            }

            return -1;
        }

        void Run()
        {
            Result = BattleResult::Run;
        }

        void UseItem()
        {
            attacker->SetDamage(-16);
        }

        void Await()
        {
            if (isPlayerTurn)
            {
                playerextraaction = playeraction;
                playeraction = 0;
            }
            else
            {
                enemyextraaction = enemyaction;
                enemyaction = 0;
            }
        }

        list<Action> MappingActionsAvailable(list<Action> actions)
        {
            int points = isPlayerTurn ? playeraction : enemyaction;
            list<Action> mapped;
            for(const Action action : actions)
            {
                if(points >= action.cost)
                {
                    mapped.push_back(action);
                } 
            }

            return mapped;
        }

        bool HasPointsToDoAction(Action action)
        {
            int points = isPlayerTurn ? playeraction : enemyaction;
            return action.cost <= points;
        }

        void RemoveActionPoint(int value)
        {
            if (isPlayerTurn)
            {
                playeraction -= value;
                playeraction = playeraction < 0 ? 0 : playeraction;
            }
            else
            {
                enemyaction -= value;
                enemyaction = enemyaction < 0 ? 0 : enemyaction;
            }
        }
};