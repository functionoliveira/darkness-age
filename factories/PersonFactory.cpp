Person* PersonFactory(string name, RaceEnumerator race, BackgroundEnumerator family, BackgroundEnumerator children, BackgroundEnumerator young)
{
    switch (race)
    {
    case RaceEnumerator::HUMAN:
        return new Human(name, family, children, young);
    case RaceEnumerator::ORC:
        return new Orc(name, family, children, young);
    case RaceEnumerator::ELF:
        return new Elf(name, family, children, young);
    case RaceEnumerator::DWARF:
        return new Dwarf(name, family, children, young);
    case RaceEnumerator::BROCKS:
        return new Brocks(name, family, children, young);
    default:
        return new Human(name, family, children, young);
    }
}