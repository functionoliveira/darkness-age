#include <iostream>
#include <conio.h>
#include <list>
#include <map>
#include <windows.h>

using namespace std;

class Interface
{
    public:
        void NewLine(int qty=1)
        {
            for(int i = 0; i < qty; i++)
            {
                cout << endl << "  ";
            }
        }

        void Color(int color)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }

        string FillWithWhitespace(string text, int lenght)
        {
            int end = lenght - text.length();
            for(int i = 0; i < end; i++)
            {
                text += " ";
            }
            return text;
        }

        void PrintSumLine(string text, int index=0, int linesize=100, int txtcolor=2, int linecolor=7)
        {
            int textlenght = text.length();
            int linelenght = textlenght > 0 ? (linesize - 4) - textlenght : linesize;
            Color(linecolor);
            for(int i = 0; i < linelenght; i++)
            {
                if (index == i)
                {
                    Color(txtcolor);
                    cout << "{ " << text << " }";
                    Color(linecolor);
                    cout << "+";
                }
                else
                {
                    cout << "+";
                }
            }

            cout << endl << "  ";
        }

        void PrintTextAndNewLine(string text, int times = 1, int textcolor=7)
        {
            Color(textcolor);
            cout << text;
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
            cout << "WELCOME TO DARKNESS AGE";
            NewLine();
        }

        void BuildAndPrintMenu(string header, map<int, string> items, bool vertical=true)
        {
            PrintTextAndNewLine(header);
            int i = 1;
            map<int, string>::iterator it;
            for(it = items.begin(); it!=items.end(); ++it)
            {
                if(vertical)
                {
                    PrintTextAndNewLine(to_string(it->first) + " -> " + it->second);
                }
                else
                {
                    PrintTextAndNewLine(to_string(it->first) + " -> " + it->second, 0);
                    PrintTextAndNewLine("        ", 0);
                }
                i++;
            }
        }

        void PrintMenu()
        {
            NewLine();
            cout << "Choose options...";
            NewLine();
            cout << "1 - Start";
            NewLine();
            cout << "2 - Continue" ;
            NewLine();
            cout << "3 - Exit";
        }

        void CreateNewPerson(string &name, RaceEnumerator &race)
        {
            char a;
            NewLine();
            cout << "Create a new person...";
            NewLine();
            NewLine();
            cout << "What is your name? ";
            getline(cin >> ws, name);
            NewLine();
            cout << "How race you wanna play (1 -> human, 2 -> elf, 3 -> orc, 4 -> dwarf, 5 -> Brocks)? ";
            a = getch();
            cout << a;
            race = static_cast<RaceEnumerator>(a);
        }

        void CreateBackground(BackgroundEnumerator &family, BackgroundEnumerator &children, BackgroundEnumerator &young)
        {
            char f, c, y;
            string options = "1 -> Unknow, 2 -> Noble, 3 -> Wild, 4 -> Warrior, 5 -> Wanderer, 6 -> Commoner, 7 -> Merchant, 8 -> Godly, 9 -> Occultist";
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

        void PrintPersonLore(Person* person)
        {
            NewLine();
            PrintTextAndNewLine(person->GetFamily().GetLore());
            PrintTextAndNewLine(person->GetChildren().GetLore());
            PrintTextAndNewLine(person->GetYoung().GetLore());
            Continue();
        }

        int PrintPersonLifeBarWithoutFormat(Person* p)
        {
            string lifebar = "";
            int life = ceil(p->GetHitpointsPercent() * 20);
            Color(5);
            lifebar += p->GetName() + " [";
            cout << p->GetName() + " [";
            for(int i = 0; i < 20; i++)
            {
                if (life < 10) { Color(12); }
                else { Color(2); }

                if (i < life)
                {
                    lifebar += "#";
                    cout << "#";
                }
                else
                {
                    lifebar += " ";
                    cout << " ";
                }
            }
            lifebar += "]";
            Color(5);
            cout << "]";
            Color(7);
            return lifebar.length();
        }

        void PrintLife(Person* p)
        {
            int life = ceil(p->GetHitpointsPercent() * 20);
            PrintTextAndNewLine(p->GetName() + " [", 0);
            for(int i = 0; i < 20; i++)
            {
                if (i < life)
                {
                    PrintTextAndNewLine("#", 0);
                }
                else
                {
                    PrintTextAndNewLine(" ", 0);
                }
            }
            PrintTextAndNewLine("]", 0);
        }

        int Continue(string text = "Press enter key to continue... ", bool showchoice = false)
        {
            char choice;
            PrintTextAndNewLine(text, 0);
            choice = getch();
            if (showchoice) cout << choice;
            return ((int)choice) - 48;
        }

        void CharInput(char &value, bool show=true)
        {
            value = getch();
            if (show) cout << value;
        }

        void StringInput(string &text)
        {
            getline(cin >> ws, text);
        }
};