#include <map>

map<Shield*, int> GetMapShield()
{
    return {
        { new Shield("Escudo de madeira", EquipmentEnum::HEAD_ARMOR, 2), 1 },
        { new Shield("Escudo de ferro", EquipmentEnum::HEAD_ARMOR, 3), 2 },
        { new Shield("Escudo classico de aco", EquipmentEnum::HEAD_ARMOR, 4), 3 },
        { new Shield("Broquel de aco", EquipmentEnum::HEAD_ARMOR, 5), 4 },
        { new Shield("Escudo muralha de aco", EquipmentEnum::HEAD_ARMOR, 6), 5 },
        { new Shield("Escudo do campiao", EquipmentEnum::HEAD_ARMOR, 8), 6 }
    };
}