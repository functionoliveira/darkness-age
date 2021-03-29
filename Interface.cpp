#include <iostream>
#include <string>
#include <conio.h>


class Interface
{
    public:
        void NewLine()
        {
            std::cout << std::endl << "  ";
        }

        void PrintTextAndNewLine(std::string text, int times = 1)
        {
            std::cout << text;
            for(int i = 0; i < times; i++)
            {
                NewLine();
            }
        }

        void ClearScreen()
        {
            system("CLS");
        }

        void PrintHeader()
        {
            NewLine();
            std::cout << "WELCOME TO DARKNESS AGE";
            NewLine();
        }

        void PrintMenu()
        {
            NewLine();
            std::cout << "Choose options...";
            NewLine();
            std::cout << "1 - Start";
            NewLine();
            std::cout << "2 - Continue" ;
            NewLine();
            std::cout << "3 - Exit";
        }

        void CreateNewPerson(std::string &name, RaceEnumerator &race)
        {
            char a;
            NewLine();
            std::cout << "Create a new person...";
            NewLine();
            NewLine();
            std::cout << "What is your name? ";
            std::getline(std::cin >> std::ws, name);
            NewLine();
            std::cout << "How race you wanna play (1 -> human, 2 -> elf, 3 -> orc, 4 -> dwarf, 5 -> Brocks)? ";
            a = getch();
            std::cout << a;
            race = static_cast<RaceEnumerator>(a);
        }

        void CreateBackground(BackgroundEnumerator &family, BackgroundEnumerator &children, BackgroundEnumerator &young)
        {
            char f, c, y;
            std::string options = "1 -> Unknow, 2 -> Noble, 3 -> Wild, 4 -> Warrior, 5 -> Wanderer, 6 -> Commoner, 7 -> Merchant, 8 -> Godly, 9 -> Occultist";
            NewLine();
            NewLine();
            PrintTextAndNewLine("About your family choice a option:");
            PrintTextAndNewLine(options);
            PrintTextAndNewLine("Your choice was... ", 0);
            CharInput(f);
            NewLine();
            NewLine();
            PrintTextAndNewLine("In your childhood");
            PrintTextAndNewLine(options);
            PrintTextAndNewLine("Your choice was... ", 0);
            CharInput(c);
            NewLine();
            NewLine();
            PrintTextAndNewLine("When you growth and went in young");
            PrintTextAndNewLine(options);
            PrintTextAndNewLine("Your choice was... ", 0);
            CharInput(y);
            NewLine();
            NewLine();
            family = static_cast<BackgroundEnumerator>(((int)f) - 48);
            children = static_cast<BackgroundEnumerator>(((int)c) - 48);
            young = static_cast<BackgroundEnumerator>(((int)y) - 48);
        }

        void PrintBodyValues(Person* person)
        {
            std::cout << "Body" <<  std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl;
            std::cout << "HP: " << person->GetHitpoints() << std::endl;
            std::cout << "MP: " << person->GetManapoints() << std::endl;
            std::cout << "SP: " << person->GetStaminapoints() << std::endl;
            std::cout << "Armor: " << person->GetArmor() << std::endl;
            std::cout << "Evasion: " << person->GetEvasion() << std::endl;
            std::cout << "Magic Damage: " << person->GetMagicdamage() << std::endl;
            std::cout << "Psychic Damage: " << person->GetPsychicdamage() << std::endl;
            std::cout << "Physical Damage: " << person->GetPhysicaldamage() << std::endl;
            std::cout << "Critical: " << person->GetCritical() << std::endl;
            std::cout << "Critical Damage: " << person->GetCriticaldamage() << std::endl;
            std::cout << "Precision: " << person->GetPrecision() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;
        }

        void PrintAttibutesValues(Person* person)
        {
            std::cout << "ATTRIBUTES" <<  std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl;
            std::cout << "Agility: " << person->GetAgility() << std::endl;
            std::cout << "Vitality: " << person->GetVitality() << std::endl;
            std::cout << "Strength: " << person->GetStrength() << std::endl;
            std::cout << "Dexterity: " << person->GetDexterity() << std::endl;
            std::cout << "Resistence: " << person->GetResistence() << std::endl;
            std::cout << "Intelligence: " << person->GetIntelligence() << std::endl;
            std::cout << "Psychic: " << person->GetPsychic() << std::endl;
            std::cout << "Luck: " << person->GetLuck() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;
        }

        void PrintPersonLore(Person* person)
        {
            NewLine();
            PrintTextAndNewLine(person->GetFamily().GetLore());
            PrintTextAndNewLine(person->GetChildren().GetLore());
            PrintTextAndNewLine(person->GetYoung().GetLore());
            Continue();
        }

        void PrintPersonToken(Person* person)
        {
            std::cout << "Name: " << person->GetName() << "     Race: " << GetRaceEnumName(person->GetRace()) << "     Level: " << person->GetLevel() << std::endl;
            PrintBodyValues(person);
            PrintAttibutesValues(person);
            Continue();
        }

        int Continue(std::string text = "Press enter key to continue... ", bool showchoice = false)
        {
            char choice;
            PrintTextAndNewLine(text, 0);
            choice = getch();
            if (showchoice) std::cout << choice;
            return ((int)choice) - 48;
        }

        void CharInput(char &value)
        {
            value = getch();
            std::cout << value;
        }
};