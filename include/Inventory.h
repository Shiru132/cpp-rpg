#ifndef INVENTORY_H
#define INVENTORY_H
#include <memory>
#include "Character.h"
#include "Items.h"


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
    const std::string getItemName() const;
    
    void addQuantity(int amount);
    int checkQuantity()const;
        
    
};
class Inventory
{
private:
    std::vector<InventoryItemSlot> inventory;
    bool helmetEquipped = false;
    bool shieldEquipped = false;
    bool armorEquipped = false;
    bool weaponEquipped = false;

public:
    // w trakcie budowy
    void addItem(const Item &, int quantity);
   
    
    void equipItem(int numberOfItem, Character *hero);
    //do zrobienia
    // void useItem(Item &, int quantity);
    // void removeItem(Item &, int quantity);
    void checkInventory() const;
  
    
};

#endif