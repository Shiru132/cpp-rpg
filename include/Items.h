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

public:
    Items(const std::string &name, int dmg, int hp, int def);
     void showItemInfo() const;
};

class ItemsList
{
private:
    std::vector<Items> ListOfItems;

public:
    
    Items& dropItem(int i);
   
};

#endif