#include <iostream>

class Attributes
{
    public:
        Attributes()
        {
            vitality = 0;
            dexterity = 0;
            strength = 0;
            agility = 0;
            intelligence = 0;
            resistence = 0;
            luck = 0;
            psychic = 0;
        }

        Attributes(int v, int d, int s, int a, int i, int r, int l, int p)
        {
            vitality = v;
            dexterity = d;
            strength = s;
            agility = a;
            intelligence = i;
            resistence = r;
            luck = l;
            psychic = p;
        }

        void SetVitality(int value)
        {
            vitality = value;
        }

        int GetVitality() const
        {
            return vitality;
        }

        void SetDexterity(int value)
        {
            dexterity = value;
        }

        int GetDexterity() const
        {
            return dexterity;
        }

        void SetStrength(int value)
        {
            strength = value;
        }

        int GetStrength() const
        {
            return strength;
        }

        void SetAgility(int value)
        {
            agility = value;
        }

        int GetAgility() const
        {
            return agility;
        }

        void SetIntelligence(int value)
        {
            intelligence = value;
        }

        int GetIntelligence() const
        {
            return intelligence;
        }

        void SetResistence(int value)
        {
            resistence = value;
        }

        int GetResistence() const
        {
            return resistence;
        }

        void SetLuck(int value)
        {
            luck = value;
        }

        int GetLuck() const
        {
            return luck;
        }

        void SetPsychic(int value)
        {
            psychic = value;
        }

        int GetPsychic() const
        {
            return psychic;
        }
    
    private:
        int vitality;
        int dexterity;
        int strength;
        int agility;
        int intelligence;
        int resistence;
        int luck;
        int psychic;
};

class AttributesTest
{
    public:
        bool run()
        {
            Attributes attributes = Attributes(10, 10, 10, 10, 10, 10, 10, 10);
            Attributes attributes2;

            std::cout << "Player One" <<  std::endl << std::endl;
            std::cout << "Agility: " << attributes.GetAgility() << std::endl;
            std::cout << "Vitality: " << attributes.GetVitality() << std::endl;
            std::cout << "Strength: " << attributes.GetStrength() << std::endl;
            std::cout << "Dexterity: " << attributes.GetDexterity() << std::endl;
            std::cout << "Resistence: " << attributes.GetResistence() << std::endl;
            std::cout << "Intelligence: " << attributes.GetIntelligence() << std::endl;
            std::cout << "Psychic: " << attributes.GetPsychic() << std::endl;
            std::cout << "Luck: " << attributes.GetLuck() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;

            std::cout << "Player Two" <<  std::endl << std::endl;
            std::cout << "Agility: " << attributes2.GetAgility() << std::endl;
            std::cout << "Vitality: " << attributes2.GetVitality() << std::endl;
            std::cout << "Strength: " << attributes2.GetStrength() << std::endl;
            std::cout << "Dexterity: " << attributes2.GetDexterity() << std::endl;
            std::cout << "Resistence: " << attributes2.GetResistence() << std::endl;
            std::cout << "Intelligence: " << attributes2.GetIntelligence() << std::endl;
            std::cout << "Psychic: " << attributes2.GetPsychic() << std::endl;
            std::cout << "Luck: " << attributes2.GetLuck() << std::endl;
            std::cout << "---------------------------------------------------------------" <<  std::endl << std::endl;

            return true;
        }
};