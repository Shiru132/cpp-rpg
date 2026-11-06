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
    ItemDefinition(const ItemId &itemId, const std::string &name, const std::string &description, ItemType type, int damage, int defense, int hp, bool stackable, int value) :
     itemId(itemId), name(name), description(description), type(type), damage(damage), defense(defense), hp(hp), stackable(stackable), value(value) {};
    ItemId getItemId(const ItemId &itemId){
        return itemId;
    }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    ItemType getItemType() const { return type; }
    int getHp() const { return hp; }
    int getDamage() const { return damage; }
    int getDefense() const { return defense; }
    bool isStackable() const { return stackable; }
    int getValue() const { return value; }
};