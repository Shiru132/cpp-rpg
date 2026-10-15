#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include <Character.h>
#include <Items.h>
#include "Character.h"

class InventoryItemSlot
{
private:
    const Item &item;
    int quantity;

public:
    InventoryItemSlot(const Item &item, int quantity)
        : item(item), quantity(quantity)
    {
    }
    const Item& getItem() const;
};
class Inventory
{
private:
    std::vector<InventoryItemSlot> inventory;

public:
    // w trakcie budowy
    void addItem(const Item &, int quantity);
    // do zrobienia całość
    void equipItem(const Item &item, int numbOfItem, Character *hero);
    void useItem(Item &, int quantity);
    void removeItem(Item &, int quantity);
    void checkInventory() const;
};

#endif