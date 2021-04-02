// #include "./AttributesTest.cpp"
// #include "./BodyTest.cpp"
// #include "./PersonTest.cpp"
#include <iostream>
#include <string>
#include <time.h>
#include "BackgroundEnumerator.cpp"
#include "RaceEnumerator.cpp"
#include "Background.cpp"
#include "./equipments/EquipmentEnum.cpp"
#include "./equipments/Equipment.cpp"
#include "./equipments/Weapon.cpp"
#include "./equipments/Armor.cpp"
#include "./equipments/ArmorFactory.cpp"
#include "./equipments/Shield.cpp"
#include "./equipments/ShieldFactory.cpp"
#include "./equipments/swords/Sword.cpp"
#include "./equipments/WeaponFactory.cpp"
#include "Person.cpp"
#include "./battle/Action.cpp"
#include "./races/Human.cpp"
#include "./races/Orc.cpp"
#include "./races/Dwarf.cpp"
#include "./races/Elf.cpp"
#include "./races/Brocks.cpp"
#include "./factories/PersonFactory.cpp"
#include "./monsters/Wolf.cpp"
#include "./factories/EnemyFactory.cpp"
#include "./interface/Interface.cpp"
#include "./interface/PersonInterface.cpp"
#include "./interface/ArenaInterface.cpp"
#include "./interface/GameInterface.cpp"
#include <windows.h>
#include <cwchar>
// #include <future>

// void music()
// {
//     Beep(523,2000);
//     Beep(428,2000);
//     Beep(328,2000);
//     Beep(128,2000);
// }

int main()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    srand (time(NULL));
    GameInterface game;
    game.Run();
    // BackgroundTest bt;
    // bt.run();
    // PersonTest person;
    // person.run();
    // AttributesTest attributeTest;
    // BodyTest bodyTest;

    // attributeTest.run();
    // bodyTest.run();
};