#include <map>

map<Armor*, int> GetMapLightArmor()
{
    return {
        { new Armor("Elmo de couro", EquipmentEnum::HEAD_ARMOR, 1, 0), 1 },
        { new Armor("Peitoral de couro", EquipmentEnum::BODY_ARMOR, 1, 0), 2 },
        { new Armor("Calca de couro", EquipmentEnum::LEGS_ARMOR, 1, 0), 3 },
        { new Armor("Luvas de couro", EquipmentEnum::HANDS_ARMOR, 1, 0), 4 },
        { new Armor("Ombreira de couro", EquipmentEnum::ARMS_ARMOR, 1, 0), 5 },
        { new Armor("Bota de couro", EquipmentEnum::FOOTS_ARMOR, 1, 0), 6 }
    };
}

map<Armor*, int> GetMapHeavyArmor()
{
    return {
        { new Armor("Elmo de ferro", EquipmentEnum::HEAD_ARMOR, 1, 1), 1 },
        { new Armor("Cota de malha", EquipmentEnum::BODY_ARMOR, 1, 1), 2 },
        { new Armor("Cota de malha inferior", EquipmentEnum::LEGS_ARMOR, 1, 1), 3 },
        { new Armor("Luvas malha de ferro", EquipmentEnum::HANDS_ARMOR, 1, 1), 4 },
        { new Armor("Ombreira de ferro", EquipmentEnum::ARMS_ARMOR, 1, 1), 5 },
        { new Armor("Bota de ferro", EquipmentEnum::FOOTS_ARMOR, 1, 1), 6 }
    };
}