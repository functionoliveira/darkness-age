#include <iostream>

using namespace std;

class MagicMissel : public SpecialAttack
{
    private:
       int type = 2;
       string name = "Misel magico";
       int basedamage = 6;

    public:
        int damage(Person* p)
        {
            return (basedamage * p->GetLevel()) + p->GetIntelligence();
        }
};