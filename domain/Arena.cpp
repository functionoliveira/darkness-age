
using namespace std;

class Arena
{
    protected:
        Person* player;
        Person* enemy;
        int arenalvl = 1;
        int xpfrombattle = 0;
        Equipment* reward;
    
        void SetEnemy()
        {
            string tmp = to_string(((rand() % 5) + 1));
            char const *option = tmp.c_str();
            pair<Person*, int> pair = EnemyFactory(*option, arenalvl);
            enemy = get<0>(pair);
            xpfrombattle = get<1>(pair);
        }

        void Win()
        {
            reward = NULL;
            int chance = rand() % 100;
            int key = (rand() % 5) + 1;
            player->GainExperience(xpfrombattle);
            arenalvl = player->GetLevel();

            map<int, Sword*> onehanded = GetMapOneHandedSword();
            map<int, Sword*> twohanded = GetMapTwoHandedSword();
            map<int, Armor*> heavyarmors = GetMapHeavyArmor();
            map<int, Armor*> lightarmors = GetMapHeavyArmor();
            map<int, Shield*> shields = GetMapShield();

            if (chance < 10)
            {
                reward = onehanded.find(key)->second;
                player->Equip(onehanded.find(key)->second);
            }

            if (chance >= 90 && chance < 100)
            {
                reward = twohanded.find(key)->second;
                player->Equip(twohanded.find(key)->second);
            }

            if (chance >= 40 && chance < 45)
            {
                reward = lightarmors.find(key)->second;
                player->ArmorEquip(lightarmors.find(key)->second);
            }

            if (chance >= 70 && chance < 75)
            {
                reward = heavyarmors.find(key)->second;
                player->ArmorEquip(heavyarmors.find(key)->second);
            }

            if (chance == 60 && chance == 62)
            {
                reward = shields.find(key)->second;
                player->EquipShield(shields.find(key)->second);
            }
        }
};