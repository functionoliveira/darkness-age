// #include "Person.cpp"

class Dwarf : public Person
{
    public:
        Dwarf(std::string n, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Person(n, RaceEnumerator::DWARF, f, c, y)
        {
            // Attributes Values
            vitality = 10;
            dexterity = 9;
            strength = 11;
            agility = 5;
            intelligence = 6;
            resistence = 8;
            luck = 13;
            psychic = 0;

            // Body values
            hitpoints = 22;
            manapoints = 6;
            staminapoints = 17;
            armor = 6;
            evasion = 3;
            magicdamage = 0;
            psychicdamage = 0;
            physicaldamage = 6;
            critical = 1;
            precision = 8;

            ApplyBackgroundBuffs();
        }
};