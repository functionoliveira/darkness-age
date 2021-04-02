#include <iostream>

using namespace std;

class HeavyArmor : Armor
{
    private:
        int bonus;
    public:
        HeavyArmor(string n, EquipmentEnum t, int b) : Armor(n, t) {
            bonus = b;
        }
        
        void ApplyBonus(Person* person) {
            person->BuffArmor(b);
        }

        void RemoveBonus(Person* person) {
            person->DebuffArmor(b);
        }
};