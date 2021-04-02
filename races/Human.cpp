// #include "Person.cpp"

class Human : public Person
{
    public:
        Human(std::string n, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Person(n, RaceEnumerator::HUMAN, f, c, y)
        {
            // Attributes Values
            vitality = 8;
            dexterity = 10;
            strength = 8;
            agility = 10;
            intelligence = 10;
            resistence = 6;
            luck = 8;
            psychic = 2;

            // Body values
            hitpoints = 20;
            manapoints = 10;
            staminapoints = 15;
            armor = 5;
            evasion = 5;
            magicdamage = 2;
            psychicdamage = 0;
            physicaldamage = 6;
            critical = 1;
            precision = 5;

            ApplyBackgroundBuffs();
        }
};