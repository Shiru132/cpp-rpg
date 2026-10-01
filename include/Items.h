#ifndef ITEMS_H
#define ITEMS_H
#include <vector>
#include <string>

class Items
{
private:
    std::string name;
    int dmg;
    int hp;
    int def;
    int value;

public:
    Items(const std::string &name, int dmg, int hp, int def, int value);
    void showItemInfo() const;
    void equipItem();
    std::string GetName() const;
};

class ItemsList
{
private:
    std::vector<Items> ListOfItems;

public:
    Items &getItem(int i);
    
};

#endif