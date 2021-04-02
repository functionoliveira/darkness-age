// #include "Person.cpp"

class Orc : public Person
{
    public:
        Orc(std::string n, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Person(n, RaceEnumerator::ORC, f, c, y)
        {
            // Attributes Values
            vitality = 11;
            dexterity = 8;
            strength = 12;
            agility = 8;
            intelligence = 5;
            resistence = 10;
            luck = 8;
            psychic = 0;

            // Body values
            hitpoints = 24;
            manapoints = 6;
            staminapoints = 15;
            armor = 8;
            evasion = 2;
            magicdamage = 0;
            psychicdamage = 0;
            physicaldamage = 8;
            critical = 1;
            precision = 5;

            ApplyBackgroundBuffs();
        }
};