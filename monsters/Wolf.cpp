// #include "../Person.cpp"

using namespace std;

class Wolf : public Person
{
    public:
        Wolf(int lvl) : Person("Wolf", lvl, RaceEnumerator::WOLF)
        {
            // Attributes Values
            vitality = 6;
            dexterity = 10 + lvl;
            strength = 7;
            agility = 9 + lvl;
            intelligence = 4;
            resistence = 6;
            luck = 8 + (2 * lvl);
            psychic = 0;

            // Body values
            hitpoints = 14 + (lvl * 2);
            manapoints = 0;
            staminapoints = 10;
            armor = 3;
            evasion = 8;
            magicdamage = 0;
            psychicdamage = 0;
            physicaldamage = 4;
            critical = 1;
            precision = 8;
        }
};