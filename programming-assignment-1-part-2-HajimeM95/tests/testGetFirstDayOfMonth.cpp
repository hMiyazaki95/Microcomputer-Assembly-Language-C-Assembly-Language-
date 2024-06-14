#include "../src/cal.h"
#include <gtest/gtest.h>

TEST(FirstDayOfMonth, Jan2019)
{
    int First_day;
    char buffer[1024];
    First_day = getFirstDayOfMonth(1, 2019);
    sprintf(buffer, "%d\n", First_day);
    ASSERT_STREQ(buffer, "2\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}