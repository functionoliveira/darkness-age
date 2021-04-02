
using namespace std;

class Arena
{
    protected:
        Person* player;
        Person* enemy;
        int arenalvl = 1;
        int xpfrombattle = 0;

    
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
            player->GainExperience(xpfrombattle);
        }
};