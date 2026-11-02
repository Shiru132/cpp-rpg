#include <gtest/gtest.h>
#include "Core/Types.h"

TEST(TypesTest, ItemIdTest){
    ItemId sword(10);
    ItemId shield(11);
    EXPECT_EQ(sword.getItemId(),10);
    EXPECT_NE(sword.getItemId(),shield.getItemId());
}
TEST(TypesTest, InstanceIdTest){
    InstanceId sword(10);
    InstanceId shield(11);
    EXPECT_EQ(sword.getInstanceId(),10);
    EXPECT_NE(sword.getInstanceId(),shield.getInstanceId());
}
TEST(TypesTest, CharacterIdTest){
    CharacterId mage(10);
    CharacterId archer(11);
    EXPECT_EQ(mage.getCharacterId(),10);
    EXPECT_NE(mage.getCharacterId(),archer.getCharacterId());
}
TEST(TypesTest, MonsterIdTest){
    MonsterId wolf(10);
    MonsterId dragon(11);
    EXPECT_EQ(wolf.getMonsterId(),10);
    EXPECT_NE(wolf.getMonsterId(),dragon.getMonsterId());
}
