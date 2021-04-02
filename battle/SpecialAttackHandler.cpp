class SpecialAttackHandler
{
    public:
        enum class SpecialAttackType
        {
            // magic attacks
                MAGIC_MISSEL = 1
            // psychic attacks

            // physical attacks
        }

        SpecialAttack handle(int type)
        {
            switch (type)
            {
            case 1:
                return MagicMissel();
                break;
            default:
                break;
            }
        }
};