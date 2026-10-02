#include "../include/Inventory.h"
ItemsList itemslist;
Item &item = itemslist.getItem(0);

void Inventory::addItem(const Item &item, int quantity)
{
    inventory.push_back(InventoryItemSlot(item, quantity));
}