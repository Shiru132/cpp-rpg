#include "../include/Inventory.h"
#include <iostream>

int InventoryItemSlot::checkQuantity() const
{
    return quantity;
}
const Item &InventoryItemSlot::getItem() const
{
    return this->item;
};
const std::string InventoryItemSlot::getItemName() const
{
    return item.GetName();
};

void Inventory::addItem(const Item &item, int quantity)
{
    if (quantity > 0)
    {
        if (item.checkIfStackable() == false)
        {
            quantity = 1;
            inventory.push_back(InventoryItemSlot(item, quantity));
        }
        else if (item.checkIfStackable() == true)
        {
            // pętla po inventory
            for (auto &slot : inventory)
            {

                if (slot.getItemName() == item.GetName())
                {

                    slot.addQuantity(quantity);
                    return;
                }
            }
            inventory.push_back(InventoryItemSlot(item, quantity));
        }
    }
    else
    {
        std::cout << "ilosc itemow jest mniejsza od 0\n";
    }
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
        std::cout << "ilsoc stacku nie moze byc mniejsza od 0 \n";
        return;
    }
    else if (item.checkIfStackable() == true)
    {
        this->quantity += amount;
        std::cout << "dodano \n";
    }
    else
    {
        std::cout << item.GetName() << " Przedmiot niestackowalny \n";
    }
}
void Inventory::checkInventory() const
{

    for (const auto &slot : inventory)
    {

        std::cout << "Ilosc: " << slot.checkQuantity() << " " << slot.getItem().GetName() << std::endl;
    }
}
int Inventory::getQuantityOfItemInInventory(const std::string &itemName) const
{
    for (const auto &slot : inventory)
    {
        if (itemName == slot.getItem().GetName())
        {
            return slot.checkQuantity();
        }
    }
    return 0;
}
int Inventory::getSlotCount()const{
    return inventory.size();
}