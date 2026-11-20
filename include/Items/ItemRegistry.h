#pragma once
#include <unordered_map>
#include <string>
#include "core/Types.h"
#include "ItemDefinition.h"
class ItemRegistry
{
private:
    std::unordered_map<ItemId, ItemDefinition, ItemIdHash> itemRegistry;

public:
    ItemRegistry(const std::vector<ItemDefinition>&items);
    void add(const ItemDefinition &itemDefiniton);
    
    
    const ItemDefinition& getItemDefiniton (const ItemId &itemId) const;
};
