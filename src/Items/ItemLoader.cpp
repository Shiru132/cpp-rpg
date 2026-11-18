#include "items/ItemLoader.h"
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
using json = nlohmann::json;

ItemType stringToItemType(const std::string &type)
{
    if (type == "Weapon")
    {
        return ItemType::Weapon;
    }
    if (type == "Helmet")
    {
        return ItemType::Helmet;
    }
    if (type == "Armor")
    {
        return ItemType::Armor;
    }
    if (type == "Potion")
    {
        return ItemType::Potion;
    }
    if (type == "Neutral")
    {
        return ItemType::Neutral;
    }
    if (type == "Shield")
    {
        return ItemType::Shield;
    }

    throw std::invalid_argument("Unknown ItemType: " + type);
};

std::vector<ItemDefinition> ItemLoader::loadFromFile(const std::string &path)
{
    std::vector<ItemDefinition> jsonItems;
    std::ifstream fileItems(path);
    if (!fileItems.is_open())
    {
        throw std::runtime_error("Cannot open Items.json");
    }
    json data = json::parse(fileItems);
    for (const auto &item : data["items"])
    {
        std::string typeString = item.at("type");
        int itemId = item.at("id");
        std::string name = item.at("name");
        std::string description = item.at("description");
        ItemType firstType = stringToItemType(typeString);
        int damage = item.at("damage");
        int defense = item.at("defense");
        int hp = item.at("hp");
        bool stackable = item.at("stackable");
        int value = item.at("value");
        int maxStack = item.at("maxStack");
        ItemId constructorItemId(itemId);
        ItemDefinition itemDefinition(constructorItemId, name, description, firstType, damage, defense, hp, stackable, value, maxStack);
        jsonItems.emplace_back(itemDefinition);
        
    }
    return jsonItems;

}
