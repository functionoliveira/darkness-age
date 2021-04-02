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

            string GetHeadEquipName()
            {
                return headslot != NULL ? headslot->GetName() : "Vazio";
            }

            string GetHeadEquipBonus()
            {
                return headslot != NULL ? "+" + to_string(headslot->GetBonus()) : "";
            }

            string GetChestEquipName()
            {
                return bodyslot != NULL ? bodyslot->GetName() : "Vazio";
            }

            string GetChestEquipBonus()
            {
                return bodyslot != NULL ? "+" + to_string(bodyslot->GetBonus()) : "";
            }

            string GetLegsEquipName()
            {
                return legsslot != NULL ? legsslot->GetName() : "Vazio";
            }

            string GetLegsEquipBonus()
            {
                return legsslot != NULL ? "+" + to_string(legsslot->GetBonus()) : "";
            }

            string GetBootsEquipName()
            {
                return footsslot != NULL ? footsslot->GetName() : "Vazio";
            }

            string GetBootsEquipBonus()
            {
                return footsslot != NULL ? "+" + to_string(footsslot->GetBonus()) : "";
            }

            string GetHandsEquipName()
            {
                return handsslot != NULL ? handsslot->GetName() : "Vazio";
            }

            string GetHandsEquipBonus()
            {
                return handsslot != NULL ? "+" + to_string(handsslot->GetBonus()) : "";
            }

            string GetRightHandEquipName()
            {
                return righthandslot != NULL ? righthandslot->GetName() : "Vazio";
            }

            string GetRightHandEquipBonus()
            {
                int base;
                int full;
                if (righthandslot != NULL) 
                {
                    base = righthandslot->GetBaseDamage();
                    full = righthandslot->GetBaseDamage() + righthandslot->GetBonusDamage();
                }
                return righthandslot != NULL ? "+" + to_string(base) + "-" + to_string(full) : "";
            }

            string GetLeftHandEquipName()
            {
                return lefthandslot != NULL ? lefthandslot->GetName() : "Vazio";
            }

            string GetLeftHandEquipBonus()
            {
                return lefthandslot != NULL ? "+" + to_string(lefthandslot->GetBonus()) : "";
            }
};