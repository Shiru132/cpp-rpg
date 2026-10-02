#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include <Character.h>
#include <Items.h>

class Inventory
{
private:
    
    
    std::vector<Item> InventoryItem;

    public:
    void addItem(Item &getItem(int i));
    void equipItem(Item &getItem(int i));
    void useItem(Item &getItem(int i));
    void removeItem(Item &getItem(int i));
    void checkInventory() const;
};

#endif