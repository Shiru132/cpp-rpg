#include "inventory/Inventory.h"

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <iostream>

bool Inventory::addItem(std::unique_ptr<ItemInstance> &&item, const ItemRegistry &itemRegistry)
{
    if (!item)
    {
        throw std::invalid_argument("Pusty item w addItem\n");
    }

    const ItemDefinition &definition = itemRegistry.getItemDefiniton(item->getItemId());
    const int incomingQuantity = item->getQuantity();

    if (incomingQuantity > definition.getMaxStack())
    {
        throw std::invalid_argument("Ilosc przedmiotu przekracza maxStack\n");
    }

    if (!definition.isStackable() && incomingQuantity != 1)
    {
        throw std::invalid_argument("Przedmiot niestackowalny musi miec ilosc 1\n");
    }

    int quantityNeedingNewSlot = incomingQuantity;
    if (definition.isStackable())
    {
        for (const auto &existingItem : inventory)
        {
            const bool sameStack =
                existingItem->getItemId() == item->getItemId() &&
                existingItem->getUpgradeLvl() == item->getUpgradeLvl() &&
                existingItem->getBonusDamage() == item->getBonusDamage();

            if (!sameStack)
            {
                continue;
            }

            const int freeSpace = definition.getMaxStack() - existingItem->getQuantity();
            if (freeSpace > 0)
            {
                quantityNeedingNewSlot -= std::min(quantityNeedingNewSlot, freeSpace);
            }

            if (quantityNeedingNewSlot == 0)
            {
                break;
            }
        }
    }

    const std::size_t slotsNeeded = quantityNeedingNewSlot > 0 ? 1 : 0;
    if (inventory.size() + slotsNeeded > MAX_SLOTS)
    {
        return false;
    }

    if (definition.isStackable() && fillExistingStacks(std::move(item), itemRegistry))
    {
        return true;
    }

    const int remainingQuantity = item->getQuantity();
    return createNewStacks(std::move(item), itemRegistry, remainingQuantity);
}

bool Inventory::createNewStacks(std::unique_ptr<ItemInstance> &&item, const ItemRegistry &itemRegistry, int quantity)
{
    if (!item)
    {
        throw std::invalid_argument("Pusty item w createNewStacks\n");
    }

    if (inventory.size() >= MAX_SLOTS)
    {
        return false;
    }

    const ItemDefinition &definition = itemRegistry.getItemDefiniton(item->getItemId());
    if (quantity < 1 || quantity > definition.getMaxStack() || quantity > item->getQuantity())
    {
        return false;
    }

    if (quantity < item->getQuantity())
    {
        item->removeQuantity(item->getQuantity() - quantity);
    }

    inventory.emplace_back(std::move(item));

    return true;
}

bool Inventory::fillExistingStacks(std::unique_ptr<ItemInstance> &&item, const ItemRegistry &itemRegistry)
{
    if (!item)
    {
        throw std::invalid_argument("Pusty item w fillExistingStacks\n");
    }

    const ItemDefinition &definition = itemRegistry.getItemDefiniton(item->getItemId());
    if (!definition.isStackable())
    {
        return false;
    }

    for (auto &existingItem : inventory)
    {
        const bool sameStack =
            existingItem->getItemId() == item->getItemId() &&
            existingItem->getUpgradeLvl() == item->getUpgradeLvl() &&
            existingItem->getBonusDamage() == item->getBonusDamage();

        if (!sameStack)
        {
            continue;
        }

        const int freeSpace = definition.getMaxStack() - existingItem->getQuantity();
        if (freeSpace <= 0)
        {
            continue;
        }

        const int quantityToTransfer = std::min(item->getQuantity(), freeSpace);
        existingItem->addQuantity(quantityToTransfer);
        item->removeQuantity(quantityToTransfer);

        if (item->getQuantity() == 0)
        {

            item.reset();
            return true;
        }
    }

    return false;
}
std::unique_ptr<ItemInstance> Inventory::takeItem(const InstanceId& instanceId)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if ((*it)->getInstanceId().getInstanceId() == instanceId.getInstanceId())
        {
            auto newOwner = std::move(*it);
            inventory.erase(it);
            return newOwner;
        }
    }

    return nullptr;
}