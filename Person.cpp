#include "Attributes.cpp"
#include "Body.cpp"
#include <iostream>
#include <cmath>

class Person : public Body, public Attributes, public Background
{
    public:
        Person(std::string n, RaceEnumerator r, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Body(), Attributes(), Background(f, c, y)
        {
            name = n;
            level = 1;
            race = r;
        }

        std::string GetName()
        {
            return name;
        }

        RaceEnumerator GetRace()
        {
            return race;
        }

        int GetLevel()
        {
            return level;
        }

        int GetHitpoints() const
        {
            return hitpoints + (2 * vitality) - damage;
        }

        float GetHitpointsPercent() const
        {
            return (float)GetHitpoints() / (hitpoints + (2 * vitality));
        }

        int GetManapoints() const
        {
            return manapoints + psychic;
        }

        int GetStaminapoints() const
        {
            return staminapoints + resistence;
        }

        int GetArmor() const
        {
            return ceil(armor + (resistence / 0.75));
        }

        int GetEvasion() const
        {
            return evasion + agility;
        }

        int GetMagicdamage() const
        {
            return magicdamage + intelligence;
        }

        int GetPsychicdamage() const
        {
            return psychicdamage + psychic;
        }

        int GetPhysicaldamage() const
        {
            return ceil(physicaldamage + strength + (0.5 * dexterity) + (rand() % 7));
        }

        float GetCritical() const
        {
            return critical + (luck * 0.005);
        }

        float GetCriticaldamage() const
        {
            return criticaldamage + (luck * 0.002);
        }

        int GetPrecision() const
        {
            return precision + dexterity;
        }

        void BuffVitality(int value)
        {
            vitality += value;
        }

        void BuffDexterity(int value)
        {
            dexterity += value;
        }

        void BuffStrength(int value)
        {
            strength += value;
        }

        void BuffAgility(int value)
        {
            agility += value;
        }

        void BuffIntelligence(int value)
        {
            intelligence += value;
        }

        void BuffResistence(int value)
        {
            resistence += value;
        }

        void BuffLuck(int value)
        {
            luck += value;
        }

        void BuffPsychic(int value)
        {
            psychic += value;
        }

        void SetHitpoints(int value)
        {
            
        }

        void UpdateAttributesFromFamily ()
        {
            switch (GetFamily().GetEnumValue())
            {
                case BackgroundEnumerator::UNKNOW:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::NOBLE:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WILD:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WARRIOR:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WANDERER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::COMMONER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::MERCHANT:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::GODLY:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::OCCULTIST:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                default: "???";
            }
        }

        void UpdateAttributesFromChildren ()
        {
            switch (GetChildren().GetEnumValue())
            {
                case BackgroundEnumerator::UNKNOW:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::NOBLE:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WILD:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WARRIOR:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WANDERER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::COMMONER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::MERCHANT:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::GODLY:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::OCCULTIST:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                default: "???";
            }
        }

        void UpdateAttributesFromYoung ()
        {
            switch (GetYoung().GetEnumValue())
            {
                case BackgroundEnumerator::UNKNOW:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::NOBLE:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WILD:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WARRIOR:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WANDERER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::COMMONER:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::MERCHANT:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::GODLY:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::OCCULTIST:
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    BuffVitality(1);
                    break;
                default: "???";
            }
        }

        void SetDamage(int value)
        {
            damage = damage + value;
        }

    protected:
        int level;
        std::string name;
        RaceEnumerator race;
        int damage = 0;
};