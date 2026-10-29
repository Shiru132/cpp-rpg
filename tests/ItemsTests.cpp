
#include "../include/Items.h"
#include <gtest/gtest.h>

// test 1
TEST(ItemsTest, FirstItemHasCorrectName)
{
    ItemsList itemsList;
    Item &item = itemsList.getItem(0);

    EXPECT_EQ(item.GetName(), "red shield");
}
TEST(ItemsTest, duplicationTest)
{
    ItemsList itemsList;
    Item &item1 = itemsList.getItem(0);
    Item &item2 = itemsList.getItem(0);

    EXPECT_EQ(&item1,&item2);
    
}
// test 2
TEST(ItemsTest, indexTest)
{
    ItemsList itemsList;

    EXPECT_THROW(itemsList.getItem(4), std::runtime_error);
    EXPECT_THROW(itemsList.getItem(-1), std::runtime_error);
}