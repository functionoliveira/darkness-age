#include <map>
#include <iostream>
#include "BattleSystemInterface.cpp"
#include "../domain/Arena.cpp"

using namespace std;

class ArenaInterface : Interface, public Arena
{
    private:
        PersonInterface npi;
        char input = '0';
        map<int, string> menu = {
            { 1, "Sair" },
            { 2, "Personagem" },
            { 3, "Batalhar" },
            { 4, "Descansar" }
        };
    public:
        void Start()
        {
            string name;
            RaceEnumerator race;
            BackgroundEnumerator family, children, young;
            
            // do 
            // {
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("DARKNESS AGE - MODO ARENA");
            PrintTextAndNewLine("No modo arena voce luta por sua vida nas arenas de batalha");
            PrintTextAndNewLine("do continente de Strolia em busca de dinheiro, liberdade e");
            player = npi.Steps();
            ClearScreen();
            PersonInterface::PrintPersonToken(player);
        }

        void PrintArenaHeader()
        {
            while(input != '1')
            {
                ClearScreen();
                NewLine();
                BuildAndPrintMenu("ARENA NIVEL " + to_string(arenalvl), menu, false);
                NewLine();
                PrintTextAndNewLine("Escolha -> ", 0);
                CharInput(input, false);
                HandleMainMenuOption(input);
                NewLine();
            }
        }

        void Battle()
        {
            SetEnemy();
            ClearScreen();
            NewLine();
            NewLine();
            PrintTextAndNewLine("ARENA DE BATALHA");
            PrintTextAndNewLine("Seu openente sera um " + GetRaceEnumName(enemy->GetRace()));
            Continue("A batalha ja vai comecar...");
            BattleSystemInterface battle = BattleSystemInterface(player, enemy);
            ClearScreen();
            while (battle.GetResult() == BattleSystem::BattleResult::NotOver)
            {
                battle.Start();
            }

            if(battle.GetResult() == BattleSystem::BattleResult::Loose)
            {
                ClearScreen();
                NewLine();
                NewLine();
                NewLine();
                PrintTextAndNewLine("       GAME OVER");
                Continue("Mais sorte na proxima vez!");
                input = '1';
            }

            if(battle.GetResult() == BattleSystem::BattleResult::Win)
            {
                ClearScreen();
                NewLine();
                NewLine();
                NewLine();
                PrintTextAndNewLine("                     VITORIA");
                Continue("Voce sai mais forte, descanse para a proxima batalha...");
                Win();
            }

            if(battle.GetResult() == BattleSystem::BattleResult::Run)
            {
                ClearScreen();
                NewLine();
                NewLine();
                NewLine();
                PrintTextAndNewLine("                                  VERGONHOSO");
                Continue("Ao som de covarde voce deixa a arena, isso ficara marcado para sempre em sua mente..");
            }
        }

        void HandleMainMenuOption(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Sair");
                break;
            case '8':
                PrintTextAndNewLine("Mochila");
                Battle();
                break;
            case '9':
                PrintTextAndNewLine("Mercado");
                Battle();
                break;
            case '2':
                PrintTextAndNewLine("Personagem");
                ClearScreen();
                if(player->GetLevelBuff() < player->GetLevel()) 
                {
                    PrintTextAndNewLine("Voce tem ganhou um nivel escolha seu background: ");
                    npi.UpgradeAttributes(player);
                }
                PersonInterface::PrintPersonToken(player);
                break;
            case '3':
                PrintTextAndNewLine("Batalhar");
                Battle();
                break;
            case '4':
                PrintTextAndNewLine("Descansar");
                Color(2);
                ClearScreen();
                NewLine();
                PrintTextAndNewLine("Voce se deita ao lado da fogueira para descansar");
                player->Rest();
                PrintTextAndNewLine("Ao raiar do dia voce sente seu corpo revigorado");
                Continue("esta pronto para os novos desafios...");
                Color(7);
                break;
            default:
                PrintTextAndNewLine("Batalhar");
                Battle();
            }
        }
};