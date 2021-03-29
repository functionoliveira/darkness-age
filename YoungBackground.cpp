class YoungBackground
{
    public:
        YoungBackground() {}
        YoungBackground(BackgroundEnumerator y)
        {
            young = y;
        }

        std::string GetLore()
        {
            switch (young)
            {
                case BackgroundEnumerator::UNKNOW: return "Young Unkown";
                case BackgroundEnumerator::NOBLE: return "Young noble";
                case BackgroundEnumerator::WILD: return "Young wild";
                case BackgroundEnumerator::WARRIOR: return "Young Warrior";
                case BackgroundEnumerator::WANDERER: return "Young wanderer";
                case BackgroundEnumerator::COMMONER: return "Young commoner";
                case BackgroundEnumerator::MERCHANT: return "Young merchant";
                case BackgroundEnumerator::GODLY: return "Young godly";
                case BackgroundEnumerator::OCCULTIST: return "Young occultis";
                default: return "?????";
            }
        }

        std::string GetInfoAboutAttributesUpdate() const
        {
            switch (young)
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
            return young;
        }

    private:
        BackgroundEnumerator young;
};