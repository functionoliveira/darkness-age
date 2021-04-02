#include "../BackgroundEnumerator.cpp"
#include "../RaceEnumerator.cpp"
#include "../Background.cpp"
#include "EquipmentEnum.cpp"
#include "Equipment.cpp"
#include "Weapon.cpp"
#include "Armor.cpp"
#include "ArmorFactory.cpp"
#include "Shield.cpp"
#include "ShieldFactory.cpp"
#include "../Person.cpp"
#include "../races/Human.cpp"
#include "../races/Orc.cpp"
#include "../races/Elf.cpp"
#include "../races/Dwarf.cpp"
#include "../races/Brocks.cpp"
#include "../monsters/Wolf.cpp"
#include "../factories/PersonFactory.cpp"
#include "../interface/Interface.cpp"
#include "../interface/PersonInterface.cpp"
#include "./swords/Sword.cpp"
#include "WeaponFactory.cpp"

using namespace std;

class EquipmentTest : Interface
{
    public:
        void Run()
        {
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("TESTE DE EQUIPAMENTO");
            Continue();
            // OneHandedSwordTest();
            // TwoHandedSwordTest();
            // LightArmorTest();
            // HeavyArmorTest();
            // ShieldTest();
            TestEmptyInventoryInterface();
            TestInventoryInterface();
        }

        void OneHandedSwordTest()
        {
            map<Sword*, int> weapons = GetMapOneHandedSword();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Espadas de uma mao.");
            for(const auto& a : weapons)
            {
                PrintTextAndNewLine(to_string(a.second) + " -> " + a.first->GetName() + " dano: " + to_string(a.first->GetBaseDamage()) + "-" + to_string(a.first->GetBonusDamage()));
                human->Equip(a.first);
            }
            Continue();
            ClearScreen();
            PersonInterface::PrintPersonToken(human);
        }

        void TwoHandedSwordTest()
        {
            map<Sword*, int> weapons = GetMapTwoHandedSword();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Espadas de uma mao.");
            for(const auto& a : weapons)
            {
                PrintTextAndNewLine(to_string(a.second) + " -> " + a.first->GetName() + " dano: " + to_string(a.first->GetBaseDamage()) + "-" + to_string(a.first->GetBonusDamage()));
                human->Equip(a.first);
            }
            Continue();
            ClearScreen();
            PersonInterface::PrintPersonToken(human);
        }

        void LightArmorTest()
        {
            map<Armor*, int> armors = GetMapLightArmor();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Armadura Leve");
            for(const auto& a : armors)
            {
                PrintTextAndNewLine(to_string(a.second) + " -> " + a.first->GetName() + " evasion +" + to_string(a.first->GetBonus()));
                human->ArmorEquip(a.first);
            }
            Continue();
            ClearScreen();
            PersonInterface::PrintPersonToken(human);
        }

        void HeavyArmorTest()
        {
            map<Armor*, int> armors = GetMapHeavyArmor();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Armadura Pesada");
            for(const auto& a : armors)
            {
                PrintTextAndNewLine(to_string(a.second) + " -> " + a.first->GetName() + " armor +" + to_string(a.first->GetBonus()));
                human->ArmorEquip(a.first);
            }
            Continue();
            ClearScreen();
            PersonInterface::PrintPersonToken(human);
        }

        void ShieldTest()
        {
            map<Shield*, int> shields = GetMapShield();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Escudos");
            for(const auto& a : shields)
            {
                PrintTextAndNewLine(to_string(a.second) + " -> " + a.first->GetName() + " armor +" + to_string(a.first->GetBonus()));
                human->EquipShield(a.first);
            }
            Continue();
            ClearScreen();
            PersonInterface::PrintPersonToken(human);
        }

        void TestEmptyInventoryInterface()
        {
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Inventario");
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            PersonInterface::PrintPersonInventory(human);
            Continue();
        }

        void TestInventoryInterface()
        {
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Inventario");
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            map<Armor*, int> armors = GetMapHeavyArmor();
            for(const auto& a : armors)
            {
                human->ArmorEquip(a.first);
            }
            PersonInterface::PrintPersonInventory(human);
            // Continue();
        }
};

int main()
{
    EquipmentTest test;
    test.Run();
    return -1;
};