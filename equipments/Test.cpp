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
#include "Bag.cpp"

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
            // TestEmptyInventoryInterface();
            // TestInventoryInterface();
            BagAndEquipTest();
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
            map<int, Sword*> weapons = GetMapTwoHandedSword();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Espadas de uma mao.");
            for(const auto& a : weapons)
            {
                PrintTextAndNewLine(to_string(a.first) + " -> " + a.second->GetName() + " dano: " + to_string(a.second->GetBaseDamage()) + "-" + to_string(a.second->GetBonusDamage()));
                human->Equip(a.second);
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
            map<int, Armor*> armors = GetMapHeavyArmor();
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Armadura Pesada");
            for(const auto& a : armors)
            {
                PrintTextAndNewLine(to_string(a.first) + " -> " + a.second->GetName() + " armor +" + to_string(a.second->GetBonus()));
                human->ArmorEquip(a.second);
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
            map<int, Armor*> armors = GetMapHeavyArmor();
            for(const auto& a : armors)
            {
                human->ArmorEquip(a.second);
            }
            PersonInterface::PrintPersonInventory(human);
            // Continue();
        }

        void BagTest()
        {
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Bag");
            map<int, Armor*> armors = GetMapHeavyArmor();
            Bag* smallbag = new Bag("Mochila Pequena", 5);

            PrintTextAndNewLine(to_string(smallbag->GetBusy()) + "/" + to_string(smallbag->GetSize()));

            smallbag->AddItem(armors.find(1)->second, 1);
            smallbag->AddItem(armors.find(2)->second, 1);
            smallbag->AddItem(armors.find(3)->second, 3);
            smallbag->AddItem(armors.find(4)->second, 1);
            smallbag->AddItem(armors.find(5)->second, 2);

            for(const auto& item : smallbag->GetItems())
            {
                PrintTextAndNewLine(to_string(item.first) + " -> ", 0);
                PrintTextAndNewLine(item.second.first->GetName(), 0);
                PrintTextAndNewLine(" x" + to_string(item.second.second));
            }

            NewLine();

            smallbag->RemoveItem(2);
            smallbag->AddItem(armors.find(6)->second, 5);

            for(const auto& item : smallbag->GetItems())
            {
                PrintTextAndNewLine(to_string(item.first) + " -> ", 0);
                PrintTextAndNewLine(item.second.first->GetName(), 0);
                PrintTextAndNewLine(" x" + to_string(item.second.second));
            }
        }

        void BagAndEquipTest()
        {
            Equipment* save;
            ClearScreen();
            NewLine();
            PrintTextAndNewLine("Bag and equip");
            map<int, Armor*> armors = GetMapHeavyArmor();
            Bag* smallbag = new Bag("Mochila Pequena", 5);
            BackgroundEnumerator BCKG = BackgroundEnumerator::WARRIOR;
            Person* human = new Human("John Snow", BCKG, BCKG, BCKG);
            // Guardando item na bag e gravando a key
            save = armors.find(1)->second;
            save->SetKey(1);
            smallbag->AddItem(armors.find(1)->second, 1);
            save = armors.find(2)->second;
            save->SetKey(2);
            smallbag->AddItem(armors.find(2)->second, 1);
            save = armors.find(3)->second;
            save->SetKey(3);
            smallbag->AddItem(armors.find(3)->second, 1);
            save = armors.find(4)->second;
            save->SetKey(4);
            smallbag->AddItem(armors.find(4)->second, 1);
            
            // Equipando
            human->ArmorEquip(ArmorFactory(smallbag->GetItemsByKey(1)->GetKey()));
            human->ArmorEquip(ArmorFactory(smallbag->GetItemsByKey(2)->GetKey()));
            human->ArmorEquip(ArmorFactory(smallbag->GetItemsByKey(3)->GetKey()));
            human->ArmorEquip(ArmorFactory(smallbag->GetItemsByKey(4)->GetKey()));
            PersonInterface::PrintPersonInventory(human);
        }
};

int main()
{
    EquipmentTest test;
    test.Run();
    return -1;
};