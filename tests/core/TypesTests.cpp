#include <gtest/gtest.h>
#include "Core/Types.h"

TEST(TypesTest, ItemIdTest)
{
    ItemId sword(10);
    ItemId shield(11);
    EXPECT_EQ(sword.getItemId(), 10);
    EXPECT_NE(sword.getItemId(), shield.getItemId());
}
TEST(TypesTest, InstanceIdTest)
{
    InstanceId sword(10);
    InstanceId shield(11);
    EXPECT_EQ(sword.getInstanceId(), 10);
    EXPECT_NE(sword.getInstanceId(), shield.getInstanceId());
}
TEST(TypesTest, CharacterIdTest)
{
    CharacterId mage(10);
    CharacterId archer(11);
    EXPECT_EQ(mage.getCharacterId(), 10);
    EXPECT_NE(mage.getCharacterId(), archer.getCharacterId());
}
TEST(TypesTest, MonsterIdTest)
{
    MonsterId wolf(10);
    MonsterId dragon(11);
    EXPECT_EQ(wolf.getMonsterId(), 10);
    EXPECT_NE(wolf.getMonsterId(), dragon.getMonsterId());
}
TEST(IdTest, checkIdValue)
{
    EXPECT_THROW(ItemId(-5), std::invalid_argument);
    EXPECT_THROW(ItemId(0), std::invalid_argument);

    EXPECT_THROW(CharacterId(-5), std::invalid_argument);
    EXPECT_THROW(CharacterId(0), std::invalid_argument);

    EXPECT_THROW(InstanceId(-5), std::invalid_argument);
    EXPECT_THROW(InstanceId(0), std::invalid_argument);

    EXPECT_THROW(MonsterId(-5), std::invalid_argument);
    EXPECT_THROW(MonsterId(0), std::invalid_argument);

    EXPECT_NO_THROW(ItemId(150));
    EXPECT_NO_THROW(CharacterId(150));
    EXPECT_NO_THROW(InstanceId(150));
    EXPECT_NO_THROW(MonsterId(150));
}
TEST(IdTest, Equality)
{
    ItemId item(150);
    bool isEqual = (item == item);
    EXPECT_EQ(isEqual, 1);

    ItemId itemv2(40);
    bool isEqualv2 = (itemv2 == item);
    EXPECT_EQ(isEqualv2, 0);

    ItemId itemv3(40);
    bool isEqualv3 = (itemv3 == itemv2);
    EXPECT_EQ(isEqualv3, 1);
}

TEST(IdTest, Inequality)
{
    ItemId item(150);
    bool isDiff = (item != item);
    EXPECT_EQ(isDiff, 0);

    ItemId itemv2(40);
    bool isDiffv2 = (itemv2 != item);
    EXPECT_EQ(isDiffv2, 1);

    ItemId itemv3(40);
    bool isDiffv3 = (itemv3 != itemv2);
    EXPECT_EQ(isDiffv3, 0);
    // nie piszę dla monster character itd bo sensu nie ma skoro ta sama implementacja
}
