#pragma once
#include "items/ItemDefinition.h"

class ItemInstance
{
private:
    const InstanceId *instanceId;
    const ItemId *itemId;
    const ItemDefinition *itemDefinition;
    int upgradeLvl;
    int bonusDamage;

public:
    explicit ItemInstance(InstanceId *instanceId, ItemId *itemId, const ItemDefinition *itemDefinition, int upgradeLvl, int bonusDamage);
    int getUpgradeLvl() const { return upgradeLvl; }
    int getBonusDamage() const { return bonusDamage; }
    const InstanceId *getInstanceId() const { return this->instanceId; }
   
};