#include <iostream>

enum class RaceEnumerator
{
    HUMAN = 1,
    ORC = 2,
    ELF = 3,
    DWARF = 4,
    BROCKS = 5,
    WOLF = 6
};

using namespace std;

string GetRaceEnumName(RaceEnumerator value)
{
    switch (value)
    {
        case RaceEnumerator::HUMAN: return "Human";
        case RaceEnumerator::ORC: return "Orc";
        case RaceEnumerator::ELF: return "Elf";
        case RaceEnumerator::DWARF: return "Dwarf";
        case RaceEnumerator::BROCKS: return "Brocks";
        case RaceEnumerator::WOLF: return "Lobo";
        default: return "Unknown";
    }
}