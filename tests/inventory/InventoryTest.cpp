#include <gtest/gtest.h>
#include "inventory/Inventory.h"
#include "core/IdGenerator.h"
#include "items/ItemDefinition.h"
#include "items/ItemLoader.h"
#include "items/ItemInstance.h"
#include "core/Types.h"
#include <string>

TEST(InvnetoryTest, TakeItemTest)
{
    std::string path = "data/Items.json";
    ItemLoader itemLoader;
    auto items = itemLoader.loadFromFile(path);
    ItemRegistry itemRegistry(items);

    Inventory inventory;
    IdGenerator &generator = IdGenerator::getInstance();
    InstanceId instanceId(generator.generateInstanceId());
    ItemId itemId(1001);
    InstanceId instanceId2(generator.generateInstanceId());
    ItemId itemId2(1002);

    auto itemInstance = std::make_unique<ItemInstance>(instanceId, itemId, 2, 20, 1);
    inventory.addItem(std::move(itemInstance), itemRegistry);
    auto itemInstance2 = std::make_unique<ItemInstance>(instanceId2, itemId2, 2, 20, 1);
    inventory.addItem(std::move(itemInstance2), itemRegistry);
    auto takenItem = inventory.takeItem(instanceId2);

    ASSERT_NE(takenItem, nullptr);
    EXPECT_EQ(takenItem->getInstanceId(), instanceId2);
    EXPECT_EQ(takenItem->getQuantity(), 1);
    EXPECT_EQ(inventory.getItems().size(), 1);
}