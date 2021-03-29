class Attributes
{
    public:
        Attributes() {}
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

        int GetVitality() const
        {
            return vitality;
        }

        int GetDexterity() const
        {
            return dexterity;
        }

        int GetStrength() const
        {
            return strength;
        }

        int GetAgility() const
        {
            return agility;
        }

        int GetIntelligence() const
        {
            return intelligence;
        }

        int GetResistence() const
        {
            return resistence;
        }

        int GetLuck() const
        {
            return luck;
        }

        int GetPsychic() const
        {
            return psychic;
        }
    
    protected:
        int vitality = 0;
        int dexterity = 0;
        int strength = 0;
        int agility = 0;
        int intelligence = 0;
        int resistence = 0;
        int luck = 0;
        int psychic = 0;
};