#include <iostream>

using namespace std;

class Equipment
{
    private:
        string name;
        EquipmentEnum type;
    public:
        Equipment() {}
        Equipment(string n, EquipmentEnum t)
        {
            name = n;
            type = t;
        }
        string GetName() const
        {
            return name;
        }
        EquipmentEnum GetType() const
        {
            return type;
        }

        bool IsArmor()
        {
            return type == EquipmentEnum::ONE_HANDED ||
                   type == EquipmentEnum::TWO_HANDED ||
                   type == EquipmentEnum::RANGED;
        }

        bool IsWeapon()
        {
            return type == EquipmentEnum::HEAD_ARMOR ||
                   type == EquipmentEnum::BODY_ARMOR ||
                   type == EquipmentEnum::LEGS_ARMOR ||
                   type == EquipmentEnum::FOOTS_ARMOR ||
                   type == EquipmentEnum::ARMS_ARMOR ||
                   type == EquipmentEnum::HANDS_ARMOR;
        }
};