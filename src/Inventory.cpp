#include "../include/Inventory.h"
ItemsList itemslist;
Item &item = itemslist.getItem(0);

void Inventory::addItem(const Item &item, int quantity)
{
    inventory.push_back(InventoryItemSlot(item, quantity));
}
void Inventory::equipItem(int numbOfITem, Character *hero)
{
    itemType type = inventory[numbOfITem].getItem().GetTypeOfItem();
    if(type == itemType::Armor ||
    type == itemType::Shield ||
    type == itemType::Weapon ||
    type == itemType::Helmet){
        //do napisania kod dla eq a potem dla niezakładalnych
    }
    
}