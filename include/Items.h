#ifndef ITEMS_H
#define ITEMS_H
#include <vector>
#include <string>

class Item
{
private:
    std::string name;
    int dmg;
    int hp;
    int def;
    int value;
    bool stackable;

public:
    Item(const std::string &name, int dmg, int hp, int def, int value, bool stackable);
    void showItemInfo() const;
    
    std::string GetName() const;
};

class ItemsList
{
private:
    std::vector<Item> ListOfItems;

public:
    Item &getItem(int i);
};

#endif