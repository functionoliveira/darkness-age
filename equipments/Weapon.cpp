#include <iostream>

using namespace std;

class Weapon : public Equipment
{
    protected:
        int basedamage;
        int bonusdamage;
        string weapontype;
    public:
        Weapon(string n, EquipmentEnum t, int base, int bonus, string wt) : Equipment(n, t)
        {
            basedamage = base;
            bonusdamage = bonus;
            weapontype = wt;
        };

        int GetDamage() const
        {
            return (rand() % bonusdamage);
        }

        int GetBaseDamage() const
        {
            return basedamage;
        }

        int GetBonusDamage() const
        {
            return bonusdamage;
        }
};