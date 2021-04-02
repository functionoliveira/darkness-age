#include <iostream>

class Armor : public Equipment
{
    private:
        int bonustype;
        int bonus;
        int size;
    public:
        Armor(string n, EquipmentEnum t, int b, int bt) : Equipment(n, t)
        {
            bonus = b;
            bonustype = bt;
        }
        int GetBonus()
        {
            return bonus;
        }
        int GetBonusType()
        {
            return bonustype;
        }
};