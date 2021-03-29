enum class BackgroundEnumerator
{
    UNKNOW = 1,
    NOBLE = 2, 
    WILD = 3, 
    WARRIOR = 4, 
    WANDERER = 5, 
    COMMONER = 6, 
    MERCHANT = 7, 
    GODLY = 8, 
    OCCULTIST = 9
};

std::string GetBackgroundEnumName(BackgroundEnumerator value)
{
    switch (value)
    {
        case BackgroundEnumerator::UNKNOW: return "Unknow";
        case BackgroundEnumerator::NOBLE: return "Noble";
        case BackgroundEnumerator::WILD: return "Wild";
        case BackgroundEnumerator::WARRIOR: return "Warrior";
        case BackgroundEnumerator::WANDERER: return "Wanderer";
        case BackgroundEnumerator::COMMONER: return "Commoner";
        case BackgroundEnumerator::MERCHANT: return "Mechant";
        case BackgroundEnumerator::GODLY: return "Godly";
        case BackgroundEnumerator::OCCULTIST: return "Occultist";
        default: return "NO OPTIONS";
    }
}