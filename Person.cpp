#include "Attributes.cpp"
#include "Body.cpp"
#include <iostream>
#include <cmath>

using namespace std;

class Person : public Body, public Attributes, public Background
{
    public:
        Person(string n, int lvl, RaceEnumerator r) : Body(), Attributes(), Background(BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW, BackgroundEnumerator::UNKNOW) {
            name = n;
            level = lvl;
            race = r;
        }

        Person(string n, RaceEnumerator r, BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y) : Body(), Attributes(), Background(f, c, y)
        {
            name = n;
            level = 1;
            race = r;
            levelbuff = 1;
            experiencetonextlevel = 9;
            amountexperience = 0;
        }

        string GetName()
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

        int GetLevelBuff()
        {
            return levelbuff;
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
            return armor + resistence;
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

        int GetBasePhysicaldamage() const
        {
            if(righthandslot == NULL)
            {
                return ceil(strength + (0.5 * dexterity));
            }
            else
            {
                return ceil(strength + (0.5 * dexterity)) + righthandslot->GetBaseDamage();
            }
        }

        int GetFullPhysicaldamage() const
        {
            if(righthandslot == NULL)
            {
                return GetBasePhysicaldamage() + physicaldamage;
            }
            else
            {
                return GetBasePhysicaldamage() + righthandslot->GetBonusDamage();
            }
        }

        int GetPhysicaldamage() const
        {
            if(righthandslot == NULL) {
                return GetBasePhysicaldamage() + (rand() % physicaldamage);
            }
            else
            {
                return GetBasePhysicaldamage() + righthandslot->GetDamage();
            }
        }

        float GetCritical() const
        {
            return critical + (luck * 0.01);
        }

        float GetCriticaldamage() const
        {
            return criticaldamage + (luck * 0.0075);
        }

        int GetPrecision() const
        {
            return precision + dexterity;
        }

        int GetAmountExperience() const
        {
            return amountexperience;
        }

        int GetExpirenceToNextLevel() const
        {
            return experiencetonextlevel;
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

        void BuffEvasion(int value)
        {
            evasion += value;
        }

        void DebuffEvasion(int value)
        {
            evasion -= value;
        }

        void BuffIntelligence(int value)
        {
            intelligence += value;
        }

        void BuffResistence(int value)
        {
            resistence += value;
        }

        void BuffArmor(int value)
        {
            armor += value;
        }

        void DebuffArmor(int value)
        {
            armor -= value;
        }

        void BuffLuck(int value)
        {
            luck += value;
        }

        void BuffPsychic(int value)
        {
            psychic += value;
        }

        void ApplyBackgroundBuffs()
        {
            HandleBuffs(GetFamily().GetEnumValue());
            HandleBuffs(GetChildren().GetEnumValue());
            HandleBuffs(GetYoung().GetEnumValue());
        }

        void HandleBuffs(BackgroundEnumerator phase)
        {
            switch (phase)
            {
                case BackgroundEnumerator::UNKNOW:
                    BuffVitality(4);
                    break;
                case BackgroundEnumerator::NOBLE:
                    BuffIntelligence(1);
                    BuffDexterity(1);
                    BuffStrength(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WILD:
                    BuffResistence(1);
                    BuffAgility(1);
                    BuffDexterity(1);
                    BuffVitality(1);
                    break;
                case BackgroundEnumerator::WARRIOR:
                    BuffStrength(1);
                    BuffDexterity(1);
                    BuffVitality(1);
                    BuffResistence(1);
                    break;
                case BackgroundEnumerator::WANDERER:
                    BuffVitality(2);
                    BuffResistence(2);
                    break;
                case BackgroundEnumerator::COMMONER:
                    BuffDexterity(2);
                    BuffLuck(2);
                    break;
                case BackgroundEnumerator::MERCHANT:
                    BuffLuck(2);
                    BuffIntelligence(2);
                    break;
                case BackgroundEnumerator::GODLY:
                    BuffIntelligence(2);
                    BuffVitality(1);
                    BuffResistence(1);
                    break;
                case BackgroundEnumerator::OCCULTIST:
                    BuffIntelligence(2);
                    BuffPsychic(1);
                    BuffAgility(1);
                    break;
                default: "???";
            }
        }

        void SetLevel(int lvl)
        {
            level = lvl;
        }

        void SetDamage(int value)
        {
            damage = damage + value;
            if (damage < 0) damage = 0;
        }

        void GainExperience(int value)
        {
            if (level >= 20) return;

            amountexperience = amountexperience + value;

            if (amountexperience >= experiencetonextlevel)
            {
                amountexperience = amountexperience - experiencetonextlevel;
                level++;
                experiencetonextlevel = experiencetonextlevel + (3 * level);
                Rest();
                GainExperience(0);
            }
        }

        void Up(BackgroundEnumerator background)
        {
            if (levelbuff < level)
            {
                HandleBuffs(background);
                levelbuff++;
            }
            else
            {
                cout << "Voce nao tem experiencia suficiente!" << endl;
            }
        }

        void Rest()
        {
            damage = 0;
        }

        void EquipShield(Shield* shield)
        {
            UnequipShield(shield);
            lefthandslot = shield;
            BuffArmor(shield->GetBonus());
        }

        void UnequipShield(Shield* shield)
        {
            if(lefthandslot != NULL) DebuffArmor(lefthandslot->GetBonus());
            lefthandslot = NULL;
        }

        void ArmorEquip(Armor* armor)
        {
            UnequipArea(armor->GetType());
            EquipArea(armor->GetType(), armor);
        }

        void EquipArea(EquipmentEnum area, Armor* equip)
        {
            EquipBonusTypeBuffOrDebuff(equip);
            switch (area)
            {
            case EquipmentEnum::HEAD_ARMOR:
                headslot = equip;
                break;
            case EquipmentEnum::BODY_ARMOR:
                bodyslot = equip;
                break;
            case EquipmentEnum::LEGS_ARMOR:
                legsslot = equip;
                break;
            case EquipmentEnum::ARMS_ARMOR:
                armsslot = equip;
                break;
            case EquipmentEnum::FOOTS_ARMOR:
                footsslot = equip;
                break;
            case EquipmentEnum::HANDS_ARMOR:
                handsslot = equip;
                break;
            default:
                break;
            }
        }

        void UnequipArea(EquipmentEnum area)
        {
            switch (area)
            {
            case EquipmentEnum::HEAD_ARMOR:
                if (headslot != NULL) EquipBonusTypeBuffOrDebuff(headslot, false);
                headslot = NULL;
                break;
            case EquipmentEnum::BODY_ARMOR:
                if (bodyslot != NULL) EquipBonusTypeBuffOrDebuff(bodyslot, false);
                bodyslot = NULL;
                break;
            case EquipmentEnum::LEGS_ARMOR:
                if (legsslot != NULL) EquipBonusTypeBuffOrDebuff(legsslot, false);
                legsslot = NULL;
                break;
            case EquipmentEnum::ARMS_ARMOR:
                if (armsslot != NULL) EquipBonusTypeBuffOrDebuff(armsslot, false);
                armsslot = NULL;
                break;
            case EquipmentEnum::FOOTS_ARMOR:
                if (footsslot != NULL) EquipBonusTypeBuffOrDebuff(footsslot, false);
                footsslot = NULL;
                break;
            case EquipmentEnum::HANDS_ARMOR:
                if (handsslot != NULL) EquipBonusTypeBuffOrDebuff(handsslot, false);
                handsslot = NULL;
                break;
            default:
                break;
            }
        }

        void EquipBonusTypeBuffOrDebuff(Armor* equip, bool isBuff=true)
        {
            if (equip->GetBonusType() == 0 && isBuff)
            {
                BuffEvasion(equip->GetBonus());
            }
            else if (equip->GetBonusType() == 0 && !isBuff)
            {
                DebuffEvasion(equip->GetBonus());
            }
            else if (equip->GetBonusType() == 1 && isBuff)
            {
                BuffArmor(equip->GetBonus());
            }
            else if (equip->GetBonusType() == 1 && !isBuff)
            {
                DebuffArmor(equip->GetBonus());
            }
        }

    protected:
        int level;
        int levelbuff; 
        int experiencetonextlevel;
        int amountexperience;
        string name;
        RaceEnumerator race;
        int damage = 0;
};
