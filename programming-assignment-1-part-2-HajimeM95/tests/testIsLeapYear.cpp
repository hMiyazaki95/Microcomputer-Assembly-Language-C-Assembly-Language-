#include "../src/cal.h"
#include <gtest/gtest.h>

TEST(LeapYear, TestLeapYear)
{
    int test;
    test = isLeapYear(2019);
    ASSERT_STREQ(test, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}