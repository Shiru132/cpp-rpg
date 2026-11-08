#pragma once
#include <cstdint>
#include <string>
#include "Core/Types.h"

enum class ItemType
{
    Weapon,
    Helmet,
    Shield,
    Armor,
    Potion,
    Neutral,
};

class ItemDefinition
{
private:
    ItemId itemId;
    std::string name;
    std::string description;
    ItemType type;
    int damage;
    int defense;
    int hp;
    bool stackable;
    int value;
    // value mamy na kiedyś do systemu sklepów teraz po prostu sobie jest
public:
    ItemDefinition(const ItemId &itemId, const std::string &name, const std::string &description, ItemType type, int damage, int defense, int hp, bool stackable, int value);
    // pierwszy const po to żeby nie można było modyfikować przez refa a drugi po to żeby nie można było modyfikować przez metode czyli w {}
    const ItemId &getItemId() const { return this->itemId; }
    // const & żeby nie kopiowało tego bo przy dużej ilośći niepotrzebnie marnujemy pamięć
    const std::string &getName() const { return this->name; }
    const std::string &getDescription() const { return this->description; }
    ItemType getItemType() const { return this->type; }
    int getHp() const { return this->hp; }
    int getDamage() const { return this->damage; }
    int getDefense() const { return this->defense; }
    bool isStackable() const { return this->stackable; }
    int getValue() const { return this->value; }
};