#include "Interface.cpp"
#include "Scene.cpp"
#include <conio.h>

class Game
{
public:

    enum class GameResult
    {
        NotOver,
        Die,
        Win,
        Save
    };

    Game () { }

    void Run()
    {
        char input = '0';
        while (input != '1')
        {
            interface.ClearScreen();
            interface.PrintHeader();
            interface.PrintMenu();
            input = getch();
            if (input == '3') return;
            if (input == '1') Start();
        }
        
    }

    void Start()
    {
        std::string name;
        RaceEnumerator race;
        BackgroundEnumerator family, children, young;
        interface.ClearScreen();
        interface.CreateNewPerson(name, race);
        interface.CreateBackground(family, children, young);
    
        person = new Human(name, race, family, children, young);
        interface.ClearScreen();
        interface.PrintPersonLore(person);
        interface.ClearScreen();
        interface.PrintPersonToken(person);
        interface.ClearScreen();
        Scene scene = Scene(person, interface);
        scene.FirstScene();
    }

    private:
        Person* person;
        Interface interface;
};