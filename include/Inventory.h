#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include <Character.h>
#include <Items.h>

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
};
class Inventory
{
private:
    std::vector<InventoryItemSlot> inventory;
    
    

public:
    void addItem(const Item&, int quantity);
    void equipItem(Item &, int quantity);
    void useItem(Item &, int quantity);
    void removeItem(Item &, int quantity);
    void checkInventory() const;
};

#endif