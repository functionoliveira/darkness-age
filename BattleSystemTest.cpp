#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "RaceEnumerator.cpp"
#include "BackgroundEnumerator.cpp"
#include "Background.cpp"
#include "Person.cpp"
#include "Human.cpp"
#include "Interface.cpp"
#include "BattleSystem.cpp"
#include "BattleSystemInterface.cpp"


class BattleSystemTest
{
    public:
        void Run()
        {
            Person* player = new Human("Teste Human", RaceEnumerator::HUMAN, BackgroundEnumerator::MERCHANT, BackgroundEnumerator::MERCHANT, BackgroundEnumerator::MERCHANT);
            Person* ai = new Human("AI Human", RaceEnumerator::HUMAN, BackgroundEnumerator::MERCHANT, BackgroundEnumerator::MERCHANT, BackgroundEnumerator::MERCHANT);
        
            BattleSystemInterface battle = BattleSystemInterface(player, ai);

            while (battle.GetResult() == BattleSystem::BattleResult::NotOver)
            {
                battle.Start();
            }
        }
};

int main()
{
    BattleSystemTest test;
    srand (time(NULL));
    test.Run();
};