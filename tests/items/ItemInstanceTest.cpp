#include <gtest/gtest.h>
#include "items/ItemInstance.h"
#include "items/ItemDefinition.h"
#include "core/IdGenerator.h"

class ItemInstanceTest : public testing::Test
{
protected:
    IdGenerator &generator = IdGenerator::getInstance();
    ItemId itemId{1};
    
    InstanceId instanceId1{generator.generateInstanceId()};
    InstanceId instanceId2{generator.generateInstanceId()};

    ItemDefinition zelaznyMiecz{itemId, "zelazny miecz", "jakis tam mieczyk", ItemType::Weapon, 100, 50, 0, false, 1000, 1};
    ItemInstance zelaznyMieczPlus2{instanceId1, itemId, 2, 20,1};
    ItemInstance zelaznyMieczPlus0{instanceId2, itemId, 0, 0,1};
};

TEST_F(ItemInstanceTest, ConstructorTest)
{
    EXPECT_EQ(zelaznyMieczPlus0.getUpgradeLvl(), 0);
    EXPECT_EQ(zelaznyMieczPlus0.getBonusDamage(), 0);
    EXPECT_EQ(zelaznyMieczPlus2.getUpgradeLvl(), 2);
    EXPECT_EQ(zelaznyMieczPlus2.getBonusDamage(), 20);
    
}
TEST_F(ItemInstanceTest, InstanceIdTest){
EXPECT_NE(zelaznyMieczPlus0.getInstanceId(), zelaznyMieczPlus2.getInstanceId());
}
TEST_F(ItemInstanceTest, BonusDamageTest){
EXPECT_EQ(zelaznyMieczPlus2.getBonusDamage()+zelaznyMiecz.getDamage(), 120);
}
TEST_F(ItemInstanceTest, UpgradeLvlTest){
EXPECT_NE(zelaznyMieczPlus2.getUpgradeLvl(),zelaznyMieczPlus0.getUpgradeLvl());
}
TEST_F(ItemInstanceTest, InvalidArgumentsTest){
EXPECT_THROW(ItemInstance zelaznyMieczPlus0(instanceId2, itemId, -5, -10,1),std::invalid_argument);
}
