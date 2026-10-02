#include "../include/Items.h"
#include <stdexcept>
#include <iostream>

Items::Items(const std::string &name, int dmg, int hp, int def, int value)
{
    this->name = name;
    this->dmg = dmg;
    this->hp = hp;
    this->def = def;
    this->value = value;
}

Items &ItemsList::getItem(int i)
{ // name , dmg , hp, def, value
    Items red_shield("red shield", 20, 30, 40, 1200);
    Items poison_blade("poison blade", 20, 30, 40, 1000);
    Items h_potion("healing potion ", 0, 50, 0, 20);
    ListOfItems.emplace_back(red_shield);
    ListOfItems.emplace_back(h_potion);
    if (i > (ListOfItems.size()) - 1 || i < 0)
    {
        throw std::runtime_error("Item not found potato");
    }
    return ListOfItems[i];
}
void Items::showItemInfo() const
{
    std::cout << "Nazwa przedmiotu: " << name << std::endl
              << "Hp: " << hp << std::endl
              << "Def: " << def << std::endl
              << "Dmg: " << dmg << std::endl;
}
// std::string ItemsList::getName(Items &getItem(int i))const {
//     int i;
//     return ListOfItems[i].name;
// }
void Items::equipItem()
{
}
std::string Items::GetName() const
{

    return name;
}
