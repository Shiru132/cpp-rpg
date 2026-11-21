#include "items/ItemInstance.h"
#include <stdexcept>

ItemInstance::ItemInstance(InstanceId  instanceId,  ItemId itemId, int upgradeLvl, int bonusDamage, int quantity) : instanceId(instanceId),
itemId(itemId),upgradeLvl(upgradeLvl),bonusDamage(bonusDamage),quantity(quantity){
    if (upgradeLvl<0 ||bonusDamage<0 || quantity<1){
        throw std::invalid_argument("Nieprawidlowy upgradeLvl, bonus damage lub qiantity!!\n");
    };
};
void ItemInstance::addQuantity(int amount){
    if(amount<1){
        throw std::invalid_argument("Nie mozna dodac quanity ponizej 1\n");
    }
    this->quantity+=amount;

}
void ItemInstance::removeQuantity(int amount){
    if(amount<1){
        throw std::invalid_argument("Nie mozna dodac quanity ponizej 1\n");
    }
    else if(this->quantity<amount){
        throw std::logic_error("nie mozna odjac wiecej niz sie ma\n");
    }
    this->quantity-=amount;
}