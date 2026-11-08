#include "items/ItemDefinition.h"

ItemDefinition::ItemDefinition(const ItemId &itemId, const std::string &name, const std::string &description, ItemType type, int damage, int defense, int hp, bool stackable, int value) :
 itemId(itemId), name(name), description(description), type(type), damage(damage), defense(defense), hp(hp), stackable(stackable), value(value) {};
