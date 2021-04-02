#include <iostream>

using namespace std;

class Sword : public Weapon
{
    public:
        Sword(string n, EquipmentEnum t, int ba, int bo) : Weapon(n, t, ba, bo, "Espada") { };
};