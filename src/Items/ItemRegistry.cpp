#include "items/ItemRegistry.h"
ItemRegistry::ItemRegistry(const std::vector<ItemDefinition>&items){
    for (const ItemDefinition&itemDefiniton:items){
        add(itemDefiniton);
    }
}

void ItemRegistry::add(const ItemDefinition &itemDefiniton)
{
    auto result = itemRegistry.emplace(itemDefiniton.getItemId(), itemDefiniton);
    if (!result.second)
    {
        throw std::invalid_argument("dane itemId już istnieje\n");
    }
}
const ItemDefinition &ItemRegistry::getItemDefiniton(const ItemId &itemId) const
{
    auto it = itemRegistry.find(itemId);
    if (it == itemRegistry.end())
    {
        throw std::out_of_range("nie ma podanego itemid\n");
    }

    return it->second;
}