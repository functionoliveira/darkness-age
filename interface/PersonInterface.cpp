#include <map>
#include <iostream>

using namespace std;

class PersonInterface : public Interface
{
    private:
        string name;
        RaceEnumerator race;
        BackgroundEnumerator family;
        BackgroundEnumerator children;
        BackgroundEnumerator young;
        map<int, string> races = {
            { 1, "Humano" },
            { 2, "Orc" },
            { 3, "Elfo" },
            { 4, "Anao" },
            { 5, "Brocks" }
        };

        map<int, string> background = {
            { 1, "Desconhecido" },
            { 2, "Nobre" },
            { 3, "Selvagem" },
            { 4, "Guerreiro" },
            { 5, "Andarilho" },
            { 6, "Plebeu" },
            { 7, "Mercante" },
            { 8, "Religioso" },
            { 9, "Ocultista" }
        };
    public:
        Person* Steps()
        {
            NewLine();
            PrintTextAndNewLine("Criar personagem:", 0);
            NewLine();
            GetNameForPerson();
            GetRaceChoice();
            GetBackgroundFromFamily();
            GetBackgroundWhenWasChildren();
            GetBackgroundWhenWasYoung();
            return PersonFactory(name, race, family, children, young);
        }

        void GetNameForPerson()
        {
            PrintTextAndNewLine("Qual o nome do personagem? ", 0);
            StringInput(name);
        }

        void GetRaceChoice()
        {
            char input = '0';
            BuildAndPrintMenu("  Escolha a raca...", races);
            PrintTextAndNewLine("-> ", 0);
            CharInput(input, false);
            HandleRaceOption(input);
            
        }

        void GetBackgroundFromFamily()
        {
            NewLine();
            char input = '0';
            BuildAndPrintMenu("Sobre sua familia...", background);
            PrintTextAndNewLine("-> ", 0);
            CharInput(input, false);
            HandleBackgroundFromFamily(input);
        }

        void GetBackgroundWhenWasChildren()
        {
            NewLine();
            char input = '0';
            BuildAndPrintMenu("Sobre sua infancia...", background);
            PrintTextAndNewLine("-> ", 0);
            CharInput(input, false);
            HandleBackgroundWhenChildren(input);
        }

        void GetBackgroundWhenWasYoung()
        {
            NewLine();
            char input = '0';
            BuildAndPrintMenu("Sobre sua juventude...", background);
            PrintTextAndNewLine("-> ", 0);
            CharInput(input, false);
            HandleBackgroundWhenYoung(input);
        }

        static void PrintPersonToken(Person* person)
        {
            Interface i;
            i.NewLine();
            i.PrintTextAndNewLine("Nome: " + person->GetName(), 0);
            i.PrintTextAndNewLine("    Raca: " + GetRaceEnumName(person->GetRace()), 0);
            i.PrintTextAndNewLine("    Nivel: " + to_string(person->GetLevel()), 0);
            i.PrintTextAndNewLine("    XP: " + to_string(person->GetAmountExperience()) + "/" + to_string(person->GetExpirenceToNextLevel()));
            i.PrintTextAndNewLine("---------------------------------------------------------------");
            i.PrintTextAndNewLine("AGL: " + to_string(person->GetAgility()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("HP: " + to_string(person->GetHitpoints()));

            i.PrintTextAndNewLine("VIT: " + to_string(person->GetVitality()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("MP: " + to_string(person->GetManapoints()));

            i.PrintTextAndNewLine("FOR: " + to_string(person->GetStrength()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("SP: " + to_string(person->GetStaminapoints()));

            i.PrintTextAndNewLine("DES: " + to_string(person->GetDexterity()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("Armadura: " + to_string(person->GetArmor()));

            i.PrintTextAndNewLine("RES: " + to_string(person->GetResistence()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("Evasao: " + to_string(person->GetEvasion()));

            i.PrintTextAndNewLine("INT: " + to_string(person->GetIntelligence()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("Dano Magico: " + to_string(person->GetMagicdamage()));

            i.PrintTextAndNewLine("PSY: " + to_string(person->GetPsychic()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("Dano fisico: " + to_string(person->GetBasePhysicaldamage()) + "-" + to_string(person->GetFullPhysicaldamage()));

            i.PrintTextAndNewLine("SOR: " + to_string(person->GetLuck()), 0);
            i.PrintTextAndNewLine("\t\t\t\t", 0);
            i.PrintTextAndNewLine("Dano psiquico: " + to_string(person->GetPsychicdamage()));

            i.PrintTextAndNewLine("", 0);
            i.PrintTextAndNewLine("\t\t\t\t\t", 0);
            i.PrintTextAndNewLine("Critico: " + to_string((person->GetCritical() - 1) * 100) + "%");

            i.PrintTextAndNewLine("", 0);
            i.PrintTextAndNewLine("\t\t\t\t\t", 0);
            i.PrintTextAndNewLine("Acerto: " + to_string(person->GetPrecision()));
            i.NewLine();
            i.PrintTextAndNewLine("---------------------------------------------------------------");
            i.Continue("Pressione qualquer tecla para sair...");
        }

        void UpgradeAttributes(Person* person)
        {
            char input;
            BuildAndPrintMenu("Qual linha voce ira seguir:", background);
            PrintTextAndNewLine("-> ", 0);
            CharInput(input);
            person->Up(HandleUpgradeOption(input));
        }

        BackgroundEnumerator HandleUpgradeOption(char option)
        {
            switch (option)
            {
            case '1':
                return BackgroundEnumerator::UNKNOW;
            case '2':
                return BackgroundEnumerator::NOBLE;
            case '3':
                return BackgroundEnumerator::WILD;
            case '4':
                return BackgroundEnumerator::WARRIOR;
            case '5':
                return BackgroundEnumerator::WANDERER;
            case '6':
                return BackgroundEnumerator::COMMONER;
            case '7':
                return BackgroundEnumerator::MERCHANT;
            case '8':
                return BackgroundEnumerator::GODLY;
            case '9':
                return BackgroundEnumerator::OCCULTIST;
            default:
                return BackgroundEnumerator::UNKNOW;
            }
        }

        void HandleRaceOption(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Humano");
                race = RaceEnumerator::HUMAN;
                break;
            case '2':
                PrintTextAndNewLine("Orc");
                race = RaceEnumerator::ORC;
                break;
            case '3':
                PrintTextAndNewLine("Elf");
                race = RaceEnumerator::ELF;
                break;
            case '4':
                PrintTextAndNewLine("Anao");
                race = RaceEnumerator::DWARF;
                break;
            case '5':
                PrintTextAndNewLine("Brocks");
                race = RaceEnumerator::BROCKS;
                break;
            default:
                race = RaceEnumerator::HUMAN;
            }
        }

        void HandleBackgroundFromFamily(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Voce nao conheceu ninguem dela");
                family = BackgroundEnumerator::UNKNOW;
                break;
            case '2':
                PrintTextAndNewLine("E muita conhecida, voce tem renome e fama por isso muitas pessoas o amam e outras querem o seu sangue.");
                family = BackgroundEnumerator::NOBLE;
                break;
            case '3':
                PrintTextAndNewLine("Possui caracteristicas tribais e selvagens.");
                family = BackgroundEnumerator::WILD;
                break;
            case '4':
                PrintTextAndNewLine("Tem um legado de honra e bravura, lutando em diversas guerras para provar seu valor.");
                family = BackgroundEnumerator::WARRIOR;
                break;
            case '5':
                PrintTextAndNewLine("Costumam vagar por todo o mundo conhecendo novas racas e lugares.");
                family = BackgroundEnumerator::WANDERER;
                break;
            case '6':
                PrintTextAndNewLine("Leva uma vida simples servindo a realeza.");
                family = BackgroundEnumerator::COMMONER;
                break;
            case '7':
                PrintTextAndNewLine("Possui diversas rotas de comercio e tem muita influência em Strolia.");
                family = BackgroundEnumerator::MERCHANT;
                break;
            case '8':
                PrintTextAndNewLine("Segue a palavra e o cominho do divino em busca de paz e prosperidade.");
                family = BackgroundEnumerator::GODLY;
                break;
            case '9':
                PrintTextAndNewLine("Fundou a ceito de adoração ao sombrio.");
                family = BackgroundEnumerator::OCCULTIST;
                break;
            default:
                PrintTextAndNewLine("Opaco invalida.");
                family = BackgroundEnumerator::UNKNOW;
            }
        }

        void HandleBackgroundWhenChildren(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Voce nao conheceu ninguem dela");
                children = BackgroundEnumerator::UNKNOW;
                break;
            case '2':
                PrintTextAndNewLine("E muita conhecida, voce tem renome e fama por isso muitas pessoas o amam e outras querem o seu sangue.");
                children = BackgroundEnumerator::NOBLE;
                break;
            case '3':
                PrintTextAndNewLine("Possui caracteristicas tribais e selvagens.");
                children = BackgroundEnumerator::WILD;
                break;
            case '4':
                PrintTextAndNewLine("Tem um legado de honra e bravura, lutando em diversas guerras para provar seu valor.");
                children = BackgroundEnumerator::WARRIOR;
                break;
            case '5':
                PrintTextAndNewLine("Costumam vagar por todo o mundo conhecendo novas racas e lugares.");
                children = BackgroundEnumerator::WANDERER;
                break;
            case '6':
                PrintTextAndNewLine("Leva uma vida simples servindo a realeza.");
                children = BackgroundEnumerator::COMMONER;
                break;
            case '7':
                PrintTextAndNewLine("Possui diversas rotas de comercio e tem muita influência em Strolia.");
                children = BackgroundEnumerator::MERCHANT;
                break;
            case '8':
                PrintTextAndNewLine("Segue a palavra e o cominho do divino em busca de paz e prosperidade.");
                children = BackgroundEnumerator::GODLY;
                break;
            case '9':
                PrintTextAndNewLine("Fundou a ceito de adoração ao sombrio.");
                children = BackgroundEnumerator::OCCULTIST;
                break;
            default:
                PrintTextAndNewLine("Opaco invalida.");
                children = BackgroundEnumerator::UNKNOW;
            }
        }

        void HandleBackgroundWhenYoung(char option)
        {
            switch (option)
            {
            case '1':
                PrintTextAndNewLine("Voce nao conheceu ninguem dela");
                young = BackgroundEnumerator::UNKNOW;
                break;
            case '2':
                PrintTextAndNewLine("E muita conhecida, voce tem renome e fama por isso muitas pessoas o amam e outras querem o seu sangue.");
                young = BackgroundEnumerator::NOBLE;
                break;
            case '3':
                PrintTextAndNewLine("Possui caracteristicas tribais e selvagens.");
                young = BackgroundEnumerator::WILD;
                break;
            case '4':
                PrintTextAndNewLine("Tem um legado de honra e bravura, lutando em diversas guerras para provar seu valor.");
                young = BackgroundEnumerator::WARRIOR;
                break;
            case '5':
                PrintTextAndNewLine("Costumam vagar por todo o mundo conhecendo novas racas e lugares.");
                young = BackgroundEnumerator::WANDERER;
                break;
            case '6':
                PrintTextAndNewLine("Leva uma vida simples servindo a realeza.");
                young = BackgroundEnumerator::COMMONER;
                break;
            case '7':
                PrintTextAndNewLine("Possui diversas rotas de comercio e tem muita influência em Strolia.");
                young = BackgroundEnumerator::MERCHANT;
                break;
            case '8':
                PrintTextAndNewLine("Segue a palavra e o cominho do divino em busca de paz e prosperidade.");
                young = BackgroundEnumerator::GODLY;
                break;
            case '9':
                PrintTextAndNewLine("Fundou a ceito de adoração ao sombrio.");
                young = BackgroundEnumerator::OCCULTIST;
                break;
            default:
                PrintTextAndNewLine("Opaco invalida.");
                young = BackgroundEnumerator::UNKNOW;
            }
        }
};