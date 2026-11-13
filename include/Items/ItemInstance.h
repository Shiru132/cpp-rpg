#pragma once
#include "core/Types.h"

class ItemInstance
{
private:
    InstanceId instanceId;
    ItemId itemId;
    int upgradeLvl;
    int bonusDamage;
    int quantity;
public:
    explicit ItemInstance(InstanceId instanceId, ItemId itemId, int upgradeLvl, int bonusDamage,int quantity);
    int getUpgradeLvl() const { return upgradeLvl; }
    int getBonusDamage() const { return bonusDamage; }
    int getQuantity()const {return quantity;}
    InstanceId getInstanceId() const { return this->instanceId; }
    ItemId getItemId() const {return this->itemId;}
};