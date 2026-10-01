
#include "../include/Items.h"
#include <gtest/gtest.h>

TEST(ItemsTest, FirstItemHasCorrectName)
{
    ItemsList itemsList;

    Items& item = itemsList.getItem(0);

    EXPECT_EQ(item.GetName(), "red shield");
}
// TEST(ItemsTest, InvalidIndexThrows)
// {
//     ItemsList itemsList;

//     EXPECT_THROW(
//         itemsList.getItem(150),
//         std::runtime_error
//     );
// }