#include "items/ItemDefinition.h"

ItemDefinition::ItemDefinition(const ItemId &itemId, const std::string &name, const std::string &description, ItemType type, int damage, int defense, int hp, bool stackable, int value, int maxStack) :
 itemId(itemId), name(name), description(description), type(type), damage(damage), defense(defense), hp(hp), stackable(stackable), value(value),maxStack(maxStack) {
    if (name ==""||description==""||damage<0||defense<0||hp<0||value<0||maxStack<0){
      throw std::invalid_argument("zly argument!");
    }
 };
