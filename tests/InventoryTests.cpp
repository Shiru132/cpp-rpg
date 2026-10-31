#include <gtest/gtest.h>
#include "Inventory.h"
#include "Items.h"

TEST(InventoryItemSlotTest, AddQuantity)
{
    ItemsList items;
    Item &potion = items.getItem(2);

    InventoryItemSlot slot(potion, 2);
    InventoryItemSlot slotv2(potion, 5);
    InventoryItemSlot slotv3(potion, 7);

    slot.addQuantity(3);
    slotv3.addQuantity(5);

    EXPECT_EQ(slot.checkQuantity(), 5);
    EXPECT_EQ(slotv2.checkQuantity(), 5);
    EXPECT_EQ(slotv3.checkQuantity(), 12);
}
TEST(InventoryAddItemTest, AddItem)
{
    ItemsList items;
    Item &potion = items.getItem(2);

    Inventory inventory;
    inventory.addItem(potion, 5);

    EXPECT_EQ(inventory.getQuantityOfItemInInventory(potion.GetName()), 5);
    inventory.addItem(potion, 3);
    EXPECT_EQ(inventory.getQuantityOfItemInInventory(potion.GetName()), 8);
    inventory.addItem(potion, -3);
    EXPECT_EQ(inventory.getQuantityOfItemInInventory(potion.GetName()), 8);
}
TEST(InventoryAddNotStackableItemTest, AddItem)
{
    ItemsList items;
    Item &sword = items.getItem(0);

    Inventory inventory;
    inventory.addItem(sword, 5);

    EXPECT_EQ(inventory.getQuantityOfItemInInventory(sword.GetName()), 1);
    inventory.addItem(sword, 3);
    EXPECT_EQ(inventory.getSlotCount(), 2);
   
}