#include <map>

map<int, Sword*> GetMapOneHandedSword()
{
    return {
        { 1, new Sword("Espada de Madeira", EquipmentEnum::ONE_HANDED, 2, 6) },
        { 2, new Sword("Espada Simples", EquipmentEnum::ONE_HANDED, 2, 8) },
        { 3, new Sword("Espada Templaria", EquipmentEnum::ONE_HANDED, 4, 8) },
        { 4, new Sword("Espada Alfinete", EquipmentEnum::ONE_HANDED, 4, 8) },
        { 5, new Sword("Espada Vorpal", EquipmentEnum::ONE_HANDED, 10, 16) },
        { 6, new Sword("Espada Geada", EquipmentEnum::ONE_HANDED, 10, 16) }
    };
}

map<int, Sword*> GetMapTwoHandedSword()
{
    return {
        { 1, new Sword("Katana", EquipmentEnum::TWO_HANDED, 12, 8) },
        { 2, new Sword("Espada Montante", EquipmentEnum::TWO_HANDED, 8, 12) },
        { 3, new Sword("Espada Bastarda", EquipmentEnum::TWO_HANDED, 8, 12) },
        { 4, new Sword("Espada do Carrasco", EquipmentEnum::TWO_HANDED, 6, 14) },
        { 5, new Sword("Espada Draconica", EquipmentEnum::TWO_HANDED, 10, 16) },
        { 6, new Sword("Espada Vampirica", EquipmentEnum::TWO_HANDED, 6, 10) }
    };
}