#include <iostream>

class Shield : public Equipment
{
    private:
        int bonus;
    public:
        Shield(string n, EquipmentEnum t, int b) : Equipment(n, t)
        {
            bonus = b;
        }
        int GetBonus()
        {
            return bonus;
        }
};