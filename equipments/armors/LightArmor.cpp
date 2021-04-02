#include <iostream>

using namespace std;

class LightArmor : public Armor
{
    private:
        int bonus;
    public:
        LightArmor(string n, EquipmentEnum t, int b) : Armor(n, t) {
            bonus = b;
        }

        virtual int GetBonus() {
            return bonus;
        }
        virtual int GetBonusType() {
            return 0;
        }
        
        // void ApplyBonus(Person* person) {
        //     person->BuffEvasion(bonus);
        // }

        // void RemoveBonus(Person* person) {
        //     person->DebuffEvasion(bonus);
        // }
};