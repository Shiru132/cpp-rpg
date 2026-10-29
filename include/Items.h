#ifndef ITEMS_H
#define ITEMS_H
#include <vector>
#include <string>

enum class itemType
{
    Weapon,
    Helmet,
    Shield,
    Armor,
    Potion,
    Neutral,
};

class Item
{
private:
    std::string name;
    int dmg;
    int hp;
    int def;
    int value;
    bool stackable;
    itemType type;

public:
    Item(const std::string &name, int dmg, int hp, int def, int value, bool stackable, itemType type);
    void showItemInfo() const;

    std::string GetName() const;
    int GetDmg() const;
    int GetHp() const;
    int GetDef() const;
    itemType GetTypeOfItem() const;
};

class ItemsList
{
private:
    std::vector<Item> ListOfItems;

public:
    ItemsList();
    Item &getItem(int i);
};

#endif