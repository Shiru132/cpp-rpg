#include "items/ItemInstance.h"
#include <stdexcept>

ItemInstance::ItemInstance(const ItemId*itemId,const ItemDefinition *itemDefinition, int upgradeLvl, int bonusDamage) :
itemId(itemId), itemDefinition(itemDefinition),upgradeLvl(upgradeLvl),bonusDamage(bonusDamage){
    if (upgradeLvl<0 ||bonusDamage<0){
        std::__throw_invalid_argument("Nieprawidlowy upgradeLvl lub bonus damage!!\n");
    }
};