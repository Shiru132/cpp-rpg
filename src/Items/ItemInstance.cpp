#include "items/ItemInstance.h"
#include <stdexcept>

ItemInstance::ItemInstance(InstanceId  instanceId,  ItemId itemId, int upgradeLvl, int bonusDamage, int quantity) : instanceId(instanceId),
itemId(itemId),upgradeLvl(upgradeLvl),bonusDamage(bonusDamage),quantity(quantity){
    if (upgradeLvl<0 ||bonusDamage<0 || quantity<1){
        throw std::invalid_argument("Nieprawidlowy upgradeLvl, bonus damage lub qiantity!!\n");
    };
};