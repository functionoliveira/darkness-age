#include "../RaceEnumerator.cpp"
#include "../BackgroundEnumerator.cpp"
#include "../Background.cpp"
#include "../Person.cpp"
#include "../Interface.cpp"
#include "Wolf.cpp"

class Test
{
    public:
        void Run()
        {
            Person* wolflvl1 = new Wolf(1);
            Person* wolflvl5 = new Wolf(5);
            Person* wolflvl10 = new Wolf(10);
            Interface interface;
            interface.ClearScreen();
            interface.PrintPersonToken(wolflvl1);
            interface.ClearScreen();
            interface.PrintPersonToken(wolflvl5);
            interface.ClearScreen();
            interface.PrintPersonToken(wolflvl10);
        }
};

int main()
{
    Test test;
    test.Run();
    return -1;
}