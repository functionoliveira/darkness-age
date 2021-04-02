#include <iostream>
#include <map>
#include "../domain/Game.cpp"

using namespace std;

class GameInterface : public Game, public Interface
{
    private:
        map<int, string> mainmenu = {
            { 1, "Modo historia" },
            { 2, "Modo arena" },
            { 3, "Sair" }
        };

        map<int, string> races = {
            { 1, "Humano" },
            { 2, "Orc" },
            { 3, "Elfo" },
            { 4, "Anao" },
            { 5, "Brocks" }
        };
    public:
        void Run()
        {
            char input = '0';
            do 
            {
                ClearScreen();
                PrintHeader();
                BuildAndPrintMenu("Menu Principal...", mainmenu);
                PrintTextAndNewLine("-> ", 0);
                CharInput(input, false);
            } while (HandleMainMenuOption(input));
        }

        void Arena()
        {
            // string name;
            // RaceEnumerator race;
            // BackgroundEnumerator family, children, young;
            // PersonInterface npi = PersonInterface(name, race, family, children, young);
            // do 
            // {
            // ClearScreen();
            // NewLine();
            // PrintTextAndNewLine("DARKNESS AGE - MODO ARENA");
            // PrintTextAndNewLine("No modo arena voce luta por sua vida nas arenas de batalha");
            // PrintTextAndNewLine("do continente de Strolia em busca de dinheiro, liberdade e");
            // npi.Steps();
            // ClearScreen();
            // Person* wolflvl1 = new Wolf(1);
            // player = PersonFactory(name, race, family, children, young);
            // PersonInterface::PrintPersonToken(player);
            // } while (HandleRaceOption(input));

            ArenaInterface ainterface;
            ainterface.Start();
            ainterface.PrintArenaHeader();
        }

        void HistoryModeInterface()
        {
            ClearScreen();
            PrintTextAndNewLine("Modo historia ");
            Continue();
        }

        bool HandleMainMenuOption(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Modo Historia");
                HistoryModeInterface();
                return false;
            case '2':
                PrintTextAndNewLine("Modo Arena");
                Arena();
                return false;
            case '3':
                PrintTextAndNewLine("Sair");
                return false;
            default:
                return true;
            }
        }

        void HandleOptionNotFounError()
        {
            ClearScreen();
            PrintTextAndNewLine("Opcao nao e valida!");
            Continue();
            ClearScreen();
        }
};