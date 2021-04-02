// #include "Person.cpp"

class Brocks : public Person
{
    public:
        Brocks(std::string n, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Person(n, RaceEnumerator::BROCKS, f, c, y)
        {
            // Attributes Values
            vitality = 10;
            dexterity = 5;
            strength = 14;
            agility = 5;
            intelligence = 6;
            resistence = 16;
            luck = 6;
            psychic = 0;

            // Body values
            hitpoints = 28;
            manapoints = 4;
            staminapoints = 10;
            armor = 9;
            evasion = 1;
            magicdamage = 0;
            psychicdamage = 0;
            physicaldamage = 8;
            critical = 1;
            precision = 8;

            ApplyBackgroundBuffs();
        }
};