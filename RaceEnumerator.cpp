enum class RaceEnumerator
{
    HUMAN = 1,
    ORC = 2,
    ELF = 3,
    DWARF = 4
};

std::string GetRaceEnumName(RaceEnumerator value)
{
    switch (value)
    {
        case RaceEnumerator::HUMAN: return "Human";
        case RaceEnumerator::ORC: return "Orc";
        case RaceEnumerator::ELF: return "Elf";
        case RaceEnumerator::DWARF: return "Dwarf";
        default: return "Unknown";
    }
}