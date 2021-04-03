#include <map>

map<int, Shield*> GetMapShield()
{
    return {
        { 1, new Shield("Escudo de madeira", EquipmentEnum::HEAD_ARMOR, 2) },
        { 2, new Shield("Escudo de ferro", EquipmentEnum::HEAD_ARMOR, 3) },
        { 3, new Shield("Escudo classico de aco", EquipmentEnum::HEAD_ARMOR, 4) },
        { 4, new Shield("Broquel de aco", EquipmentEnum::HEAD_ARMOR, 5) },
        { 5, new Shield("Escudo muralha de aco", EquipmentEnum::HEAD_ARMOR, 6) },
        { 6, new Shield("Escudo do campiao", EquipmentEnum::HEAD_ARMOR, 8) }
    };
}