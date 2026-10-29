
#include "../include/Items.h"
#include <gtest/gtest.h>

// test na zgodność nazw
TEST(ItemsTest, FirstItemHasCorrectName)
{
    ItemsList itemsList;
    Item &item = itemsList.getItem(0);

    EXPECT_EQ(item.GetName(), "red shield");
}
// test dla duplikacji listy itemków
TEST(ItemsTest, duplicationTest)
{
    ItemsList itemsList;
    Item &item1 = itemsList.getItem(0);
    Item &item2 = itemsList.getItem(0);

    EXPECT_EQ(&item1,&item2);
    
}
// test na wyjście poza index
TEST(ItemsTest, indexTest)
{
    ItemsList itemsList;

    EXPECT_THROW(itemsList.getItem(4), std::runtime_error);
    EXPECT_THROW(itemsList.getItem(-1), std::runtime_error);
}