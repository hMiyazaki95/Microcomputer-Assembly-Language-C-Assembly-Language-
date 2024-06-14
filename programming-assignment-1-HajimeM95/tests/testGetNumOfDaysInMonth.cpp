#include "../src/getNumOfDaysInMonth.c"
#include <gtest/gtest.h>

TEST(NumOfDaysInMonth, Test)
{
    char buffer[1024];
    getDaysOfWeek(buffer);
    ASSERT_STREQ(buffer, "Su Mo Tu We Th Fr Sa\n");// TODO
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}