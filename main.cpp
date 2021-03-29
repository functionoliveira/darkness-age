// #include "./AttributesTest.cpp"
// #include "./BodyTest.cpp"
// #include "./PersonTest.cpp"
#include <iostream>
#include <string>
#include "BackgroundEnumerator.cpp"
#include "RaceEnumerator.cpp"
#include "Background.cpp"
#include "Person.cpp"
#include "Human.cpp"
#include "Game.cpp"
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

    Game game;
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