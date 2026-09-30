#include "../include/Items.h"
#include <stdexcept>
#include <iostream>


Items::Items(const std::string &name, int dmg, int hp, int def)
{
    this->name = name;
    this->dmg = dmg;
    this->hp = hp;
    this->def = def;
}

Items &ItemsList::dropItem(int i)
{
    Items truta("red shield", 20, 30, 40);
    Items stal("poison blade", 20, 30, 40);
    ListOfItems.push_back(truta);
    ListOfItems.push_back(stal);
    if (i > (ListOfItems.size()) - 1 || i < 0)
    {
        throw std::runtime_error("Monster not found potato");
    }
    return ListOfItems[i];
}
void Items::showItemInfo() const{
    std::cout << "Nazwa przedmiotu: " << name << std::endl
                  << "Hp: " << hp << std::endl
                  << "Def: " << def << std::endl
                  << "Dmg: " << dmg << std::endl;
}