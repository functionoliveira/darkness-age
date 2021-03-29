class ChildrenBackground
{
    public:
        ChildrenBackground() {}
        ChildrenBackground(BackgroundEnumerator c)
        {
            children = c;
        }

        std::string GetLore()
        {
            switch (children)
            {
                case BackgroundEnumerator::UNKNOW: return "You dont remember from your childhood.";
                case BackgroundEnumerator::NOBLE: return "You born in palace with a big fest in your homage, you have good foods and much careful from your servers.";
                case BackgroundEnumerator::WILD: return "Your cradle was stack of bones and animals did take care you while your family hunt.";
                case BackgroundEnumerator::WARRIOR: return "Train some month after born make you a prodigy of battle fields.";
                case BackgroundEnumerator::WANDERER: return "Living in chest of your mother, the wanderer people care very well from your childrens protect and teach about the world.";
                case BackgroundEnumerator::COMMONER: return "The simple life too have your challenge, help your family in fields day after day to long life.";
                case BackgroundEnumerator::MERCHANT: return "The first lesson that you learn was about the sea and routes of navigation, pioneer is your dream.";
                case BackgroundEnumerator::GODLY: return "Born a new server of god for to spread the word of sir in all corner of the world, living in a sanctuary anointed  blessed water. The god guard goods already protect your body.";
                case BackgroundEnumerator::OCCULTIST: return "In born your life was offer to the darkness, your fisrt words was in name of lord of darkness and your hobby is read the great occultist grimoire.";
                default: return "?????";
            }
        }

        std::string GetInfoAboutAttributesUpdate() const
        {
            switch (children)
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
            return children;
        }

    private:
        BackgroundEnumerator children;
};