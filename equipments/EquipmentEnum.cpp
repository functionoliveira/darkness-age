#include <iostream>

enum class EquipmentEnum
{
    ONE_HANDED = 1,
    TWO_HANDED = 2,
    RANGED = 3,
    HEAD_ARMOR = 4,
    BODY_ARMOR = 5,
    LEGS_ARMOR = 6,
    FOOTS_ARMOR = 7,
    ARMS_ARMOR = 8,
    HANDS_ARMOR = 9
};

using namespace std;

string GetEquipmentName(EquipmentEnum value)
{
    switch (value)
    {
        case EquipmentEnum::ONE_HANDED: return "uma mao";
        case EquipmentEnum::TWO_HANDED: return "duas maos";
        case EquipmentEnum::RANGED: return "longa distancia";
        case EquipmentEnum::BODY_ARMOR: return "peiroral";
        case EquipmentEnum::HEAD_ARMOR: return "capacete";
        case EquipmentEnum::LEGS_ARMOR: return "pernas";
        case EquipmentEnum::FOOTS_ARMOR: return "pes";
        case EquipmentEnum::ARMS_ARMOR: return "bracos";
        case EquipmentEnum::HANDS_ARMOR: return "maos";
        default: return "Unknown";
    }
}