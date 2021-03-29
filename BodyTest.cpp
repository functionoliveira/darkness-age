#include <iostream>
#include "Body.cpp"

class BodyTest
{
    public:
        bool run()
        {
            Body body = Body(100, 40, 50, 10, 26, 0, 10, 1.01, 30);

            std::cout << "Body One" <<  std::endl << std::endl;
            std::cout << "HP: " << body.GetHitpoints() << std::endl;
            std::cout << "MP: " << body.GetManapoints() << std::endl;
            std::cout << "SP: " << body.GetStaminapoints() << std::endl;
            std::cout << "Armor: " << body.GetArmor() << std::endl;
            std::cout << "Magic Damage: " << body.GetMagicdamage() << std::endl;
            std::cout << "Psychic Damage: " << body.GetPsychicdamage() << std::endl;
            std::cout << "Physical Damage: " << body.GetPhysicaldamage() << std::endl;
            std::cout << "Critical: " << body.GetCritical() << std::endl;
            std::cout << "Precision: " << body.GetPrecision() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;

            return true;
        }
    
};