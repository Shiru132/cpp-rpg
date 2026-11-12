#pragma once
#include "items/ItemDefinition.h"

class ItemInstance{
private:
    const ItemId *itemId;
    const ItemDefinition *itemDefinition;
    int upgradeLvl;
    int bonusDamage;
public:
        explicit ItemInstance(const ItemId*itemId,const ItemDefinition *itemDefinition, int upgradeLvl, int bonusDamage);
        int getUpgradeLvl()const {return upgradeLvl;}
        int getBonusDamage()const {return bonusDamage;}
};