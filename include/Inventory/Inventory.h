#pragma once
#include <vector>
#include "items/ItemInstance.h"
#include "items/ItemRegistry.h"
#include <memory>
#include <cstddef>

class Inventory
{
private:
    // constexp po to żeby wartość była znana podczas kompilacji
    // static po to żeby wartosc należała do klasy a nie obiektu
    static constexpr std::size_t MAX_SLOTS = 40;
    std::vector<std::unique_ptr<ItemInstance>> inventory;
    bool fillExistingStacks(std::unique_ptr<ItemInstance> &&item, const ItemRegistry &itemRegistry);
    bool createNewStacks(std::unique_ptr<ItemInstance> &&item, const ItemRegistry &itemRegistry, int quantity);

public:
    const std::vector<std::unique_ptr<ItemInstance>> &getItems() const { return inventory; }

    bool addItem(std::unique_ptr<ItemInstance>&&item, const ItemRegistry &itemRegistry);
};