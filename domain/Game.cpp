// #include "Scene.cpp"
#include <conio.h>

class Game
{
    protected:
        Person* player;
        Person* enemy;
        int arenalvl = 1;
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
        // char input = '0';
        // while (input != '1')
        // {
        //     interface.ClearScreen();
        //     startinterface.PrintMainMenu();
        //     interface.PrintTextAndNewLine("-> ", 0);
        //     interface.CharInput(input);
        //     if (input == '3') return;
        //     if (input == '2') Arena();
        //     if (input == '1') Start();
        // }
        
    }

    void Start()
    {
        // std::string name;
        // RaceEnumerator race;
        // BackgroundEnumerator family, children, young;
        // interface.ClearScreen();
        // interface.CreateNewPerson(name, race);
        // interface.CreateBackground(family, children, young);
    
        // person = new Human(name, family, children, young);
        // interface.ClearScreen();
        // interface.PrintPersonLore(person);
        // interface.ClearScreen();
        // interface.PrintPersonToken(person);
        // interface.ClearScreen();
        // Scene scene = Scene(person, interface);
        // scene.FirstScene();
    }

    void Arena()
    {

    }

    private:
        // Person* person;
};