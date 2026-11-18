#pragma once

#include "items/ItemDefinition.h"
#include <string>
#include <memory>
#include <vector>
class ItemLoader
{
private:
public:
    std::vector<ItemDefinition> loadFromFile(const std::string &path);
};