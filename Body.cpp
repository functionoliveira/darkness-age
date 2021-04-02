class Body
{
    public:
        Body() {}
        Body(int hp, int mp, int sp, int ar, int mad, int pyd, int phd, int c, int p)
        {
            hitpoints = hp;
            manapoints = mp;
            staminapoints = sp;
            armor = ar;
            magicdamage = mad;
            psychicdamage = pyd;
            physicaldamage = phd;
            critical = c;
            precision = p;
        }

    protected:
        int hitpoints = 0;
        int manapoints = 0;
        int staminapoints = 0;
        int armor = 0;
        int evasion = 0;
        int magicdamage = 0;
        int psychicdamage = 0;
        int physicaldamage = 0;
        float critical = 0;
        float criticaldamage = 1.5;
        int precision = 0;
        int size = 1;

        Shield* lefthandslot = NULL;
        Weapon* righthandslot = NULL;
        Armor* handsslot = NULL;
        Armor* armsslot = NULL;
        Armor* legsslot = NULL;
        Armor* bodyslot = NULL;
        Armor* headslot = NULL;
        Armor* footsslot = NULL;

        public:
            void Equip(Weapon* equipment)
            {
                Unequip();
                righthandslot = equipment;
            }

            void Unequip()
            {
                righthandslot = NULL;
            }
};