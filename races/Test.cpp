#include "../RaceEnumerator.cpp"
#include "../BackgroundEnumerator.cpp"
#include "../Background.cpp"
#include "../Person.cpp"
#include "../Interface.cpp"
#include "Human.cpp"
#include "Elf.cpp"
#include "Orc.cpp"
#include "Dwarf.cpp"
#include "Brocks.cpp"

class Test
{
    public:
        void Run()
        {
            Person* human = new Human("Humano 1", BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW);
            Person* elf = new Elf("Elf 1", BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW);
            Person* orc = new Orc("Orc 1", BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW);
            Person* dwarf = new Dwarf("Dwarf 1", BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW);
            Person* brocks = new Brocks("Brocks 1", BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW);
            Interface interface;
            interface.ClearScreen();
            interface.PrintPersonToken(human);
            interface.NewLine();
            interface.NewLine();
            interface.PrintPersonToken(elf);
            interface.NewLine();
            interface.NewLine();
            interface.PrintPersonToken(orc);
            interface.NewLine();
            interface.NewLine();
            interface.PrintPersonToken(dwarf);
            interface.NewLine();
            interface.NewLine();
            interface.PrintPersonToken(brocks);
        }
};

int main()
{
    Test test;
    test.Run();
    return -1;
}