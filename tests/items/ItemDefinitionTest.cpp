#include <gtest/gtest.h>
#include "items/ItemDefinition.h"

TEST(ItemDefinitionTest, ConstructorTest)
{
    ItemId swordId(100);
    ItemId armorId(200);

    ItemDefinition sword(swordId, "Zatruty miecz", "jakis opis miecza", ItemType::Weapon, 100, 50, 0, false, 2500, 1);
    ItemDefinition armor(armorId, "Stalowa zbroja", "jakis opis zbroji", ItemType::Armor, 0, 100, 150, false, 3500, 1);

    EXPECT_EQ(sword.getItemId(), swordId);
    EXPECT_EQ(sword.getName(), "Zatruty miecz");
    EXPECT_EQ(sword.getDescription(), "jakis opis miecza");
    EXPECT_EQ(sword.getItemType(), ItemType::Weapon);
    EXPECT_EQ(sword.getDamage(), 100);
    EXPECT_EQ(sword.getDefense(), 50);
    EXPECT_EQ(sword.getHp(), 0);
    EXPECT_EQ(sword.isStackable(), false);
    EXPECT_EQ(sword.getValue(), 2500);
    EXPECT_EQ(sword.getMaxStack(), 1);

    EXPECT_EQ(armor.getItemId(), armorId);
    EXPECT_EQ(armor.getName(), "Stalowa zbroja");
    EXPECT_EQ(armor.getDescription(), "jakis opis zbroji");
    EXPECT_EQ(armor.getItemType(), ItemType::Armor);
    EXPECT_EQ(armor.getDamage(), 0);
    EXPECT_EQ(armor.getDefense(), 100);
    EXPECT_EQ(armor.getHp(), 150);
    EXPECT_EQ(armor.isStackable(), false);
    EXPECT_EQ(armor.getValue(), 3500);
    EXPECT_EQ(armor.getMaxStack(), 1);
}