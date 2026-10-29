#include "../include/Items.h"
#include <stdexcept>
#include <iostream>

Item::Item(const std::string &name, int dmg, int hp, int def, int value, bool stackable, itemType type)
{
    this->name = name;
    this->dmg = dmg;
    this->hp = hp;
    this->def = def;
    this->value = value;
    this->stackable = stackable;
    this->type = type;
}

// dajemy tu konstruktor dlatego żeby tylko raz zainicjalizować liste przedmiotów aby uniknąć duplikatów
ItemsList::ItemsList()
{
                                //name ,        dmg, hp, def, value, stackable, type
    ListOfItems.emplace_back("red shield",      20, 300, 40,   1200, false, itemType::Shield);
    ListOfItems.emplace_back("poison blade",    20, 30,  40,   1000, false, itemType::Weapon);
    ListOfItems.emplace_back("healing potion ", 0,  50,  0,    50,   true,  itemType::Potion);
    ListOfItems.emplace_back("dark helmet ",    0,  50,  300,  900,  false,  itemType::Helmet);
}
Item &ItemsList::getItem(int i)
{
  

    if (i > (ListOfItems.size()) - 1 || i < 0 || ListOfItems.size()==0) 
    {
        throw std::runtime_error("Item not found potato");
    }
    return ListOfItems[i];
}
void Item::showItemInfo() const
{
    std::cout << "Nazwa przedmiotu: " << name << std::endl
              << "Hp: " << hp << std::endl
              << "Def: " << def << std::endl
              << "Dmg: " << dmg << std::endl;
}

std::string Item::GetName() const
{

    return name;
}
bool Item::checkIfStackable() const
{
    return stackable;
}

int Item::GetDmg() const
{
    return dmg;
}
int Item::GetHp() const
{
    return hp;
}
int Item::GetDef() const
{
    return def;
}
itemType Item::GetTypeOfItem() const
{
    return type;
}
