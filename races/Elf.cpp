// #include "Person.cpp"

class Elf : public Person
{
    public:
        Elf(std::string n, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Person(n, RaceEnumerator::ELF, f, c, y)
        {
            // Attributes Values
            vitality = 7;
            dexterity = 11;
            strength = 7;
            agility = 11;
            intelligence = 12;
            resistence = 4;
            luck = 6;
            psychic = 4;

            // Body values
            hitpoints = 17;
            manapoints = 14;
            staminapoints = 12;
            armor = 4;
            evasion = 7;
            magicdamage = 3;
            psychicdamage = 1;
            physicaldamage = 4;
            critical = 1;
            precision = 8;

            ApplyBackgroundBuffs();
        }
};