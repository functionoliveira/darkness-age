#include <iostream>
#include "Person.cpp"
#include "RaceEnumerator.cpp"

class PersonTest
{
    public:
        bool run()
        {
            Person* person = new Person("Human Test", RaceEnumerator::HUMAN);
            
            std::cout << "Player Token" << std::endl;
            std::cout << person->GetName() << " - " << person->GetRace() << " - level: " << person->GetLevel() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl;
            std::cout << "HP: " << person->GetHitpoints() << std::endl;
            std::cout << "MP: " << person->GetManapoints() << std::endl;
            std::cout << "SP: " << person->GetStaminapoints() << std::endl;
            std::cout << "Armor: " << person->GetArmor() << std::endl;
            std::cout << "Magic Damage: " << person->GetMagicdamage() << std::endl;
            std::cout << "Psychic Damage: " << person->GetPsychicdamage() << std::endl;
            std::cout << "Physical Damage: " << person->GetPhysicaldamage() << std::endl;
            std::cout << "Critical: " << person->GetCritical() << std::endl;
            std::cout << "Precision: " << person->GetPrecision() << std::endl << std::endl;
            std::cout << "ATTRIBUTES" <<  std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl;
            std::cout << "Agility: " << person->GetAgility() << std::endl;
            std::cout << "Vitality: " << person->GetVitality() << std::endl;
            std::cout << "Strength: " << person->GetStrength() << std::endl;
            std::cout << "Dexterity: " << person->GetDexterity() << std::endl;
            std::cout << "Resistence: " << person->GetResistence() << std::endl;
            std::cout << "Intelligence: " << person->GetIntelligence() << std::endl;
            std::cout << "Psychic: " << person->GetPsychic() << std::endl;
            std::cout << "Luck: " << person->GetLuck() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;

            return true;
        }
};