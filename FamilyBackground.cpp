class FamilyBackground
{
    public:
        FamilyBackground() {}
        FamilyBackground(BackgroundEnumerator f)
        {
            family = f;
        }

        std::string GetLore()
        {
            switch (family)
            {
                case BackgroundEnumerator::UNKNOW: return "Family not found.";
                case BackgroundEnumerator::NOBLE: return "Your family has very loyality and influence with the goverment.";
                case BackgroundEnumerator::WILD: return "Your family is known wild and living in forest hunt and murder your prey.";
                case BackgroundEnumerator::WARRIOR: return "A legendary family of warriors that fight in any battles.";
                case BackgroundEnumerator::WANDERER: return "Walk for the world its the slogan of your family.";
                case BackgroundEnumerator::COMMONER: return "A commoners the live day after day.";
                case BackgroundEnumerator::MERCHANT: return "Navigation and money move the world, your family move the world. The merchant blood run in your veins.";
                case BackgroundEnumerator::GODLY: return "Your life for your god, the sanctuary is the house of your family and yous living to server the god.";
                case BackgroundEnumerator::OCCULTIST: return "Hungry for the unkown, the darkness its so interest so why not navigate in the sea of knowladge. The occultist put you in this way.";
                default: return "?????";
            }
        }

        std::string GetInfoAboutAttributesUpdate() const
        {
            switch (family)
            {
                case BackgroundEnumerator::UNKNOW: return "+1 random, +1 random, +1 random and +1 random";
                case BackgroundEnumerator::NOBLE: return "+1 intelligence, +1 dexterity, +1 strength, +1 vitality";
                case BackgroundEnumerator::WILD: return "+1 resistence, +1 agility, +1 dexterity, +1 vitality";
                case BackgroundEnumerator::WARRIOR: return "+1 strength, +1 dexterity, +1 vitality, +1 resistence";
                case BackgroundEnumerator::WANDERER: return "+2 vitality and +2 resistence";
                case BackgroundEnumerator::COMMONER: return "+2 dexterity and +2 luck";
                case BackgroundEnumerator::MERCHANT: return "+2 luck and +2 intelligence";
                case BackgroundEnumerator::GODLY: return "+1 intelligence, +1 vitality, +1 resistence and +1 luck";
                case BackgroundEnumerator::OCCULTIST: return "+1 intelligence, +1 psychic, +1 resistence and +1 luck";
                default: return "?????";
            }
        }

        BackgroundEnumerator GetEnumValue() const
        {
            return family;
        }

    protected:
        BackgroundEnumerator family;
};