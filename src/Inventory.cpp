#include "../include/Inventory.h"
#include <iostream>



 const Item& InventoryItemSlot::getItem() const{
    return this->item;
 };

void Inventory::addItem(const Item &item, int quantity)
{
    inventory.push_back(InventoryItemSlot(item, quantity));
}

void Inventory::equipItem(int numberOfItem, Character *hero)
{
    int defenseFromItem = inventory[numberOfItem].getItem().GetDef();
    int hpFromItem = inventory[numberOfItem].getItem().GetHp();
    int dmgFromItem = inventory[numberOfItem].getItem().GetDmg();

    itemType type = inventory[numberOfItem].getItem().GetTypeOfItem();

    if (type == itemType::Armor && !armorEquipped)
    {
        hero->equippedItemBonus(hpFromItem, defenseFromItem, dmgFromItem);
        armorEquipped = true;
    }
    else if (type == itemType::Shield && !shieldEquipped)
    {
        hero->equippedItemBonus(hpFromItem, defenseFromItem, dmgFromItem);
        shieldEquipped = true;
    }
    else if (type == itemType::Weapon && !weaponEquipped)
    {
        hero->equippedItemBonus(hpFromItem, defenseFromItem, dmgFromItem);
        weaponEquipped = true;
    }
    else if (type == itemType::Helmet && !helmetEquipped)
    {
        hero->equippedItemBonus(hpFromItem, defenseFromItem, dmgFromItem);
        helmetEquipped = true;
    }
}
void InventoryItemSlot::addQuantity(int amount)
{
    if (amount <= 0)
    {
        return;
    }
    if (item.checkIfStackable() == true)
    {
        this->quantity += amount;
    }
    else
    {
        std::cout << "Przedmiot niestackowalny \n";
    }
}