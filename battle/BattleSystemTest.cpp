#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "../RaceEnumerator.cpp"
#include "../BackgroundEnumerator.cpp"
#include "../Background.cpp"
#include "../Person.cpp"
#include "../races/Human.cpp"
#include "../races/Orc.cpp"
#include "../races/Brocks.cpp"
#include "../races/Dwarf.cpp"
#include "../races/Elf.cpp"
#include "../monsters/Wolf.cpp"
#include "../Interface.cpp"
#include "Action.cpp"
#include "BattleSystem.cpp"
#include "BattleSystemInterface.cpp"


class BattleSystemTest
{
    public:
        void Run()
        {
            Interface interface;
            Person* player = new Human("Jogador Humano", BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR);
            Person* ai = new Orc("AI Orc", BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR);
            Person* brocks = new Brocks("AI Brocks", BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR);
            Person* dwarf = new Dwarf("AI Dwarf", BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR);
            Person* elf = new Elf("AI Elf", BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR, BackgroundEnumerator::WARRIOR);
            Person* wolf = new Wolf(1);

            interface.ClearScreen();
            interface.PrintPersonToken(player);
            interface.ClearScreen();
            interface.PrintPersonToken(wolf);

            BattleSystemInterface battle = BattleSystemInterface(player, wolf);

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