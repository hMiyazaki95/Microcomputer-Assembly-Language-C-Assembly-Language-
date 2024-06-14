#include "../src/cal.h"
#include <gtest/gtest.h>

TEST(DaysOfWeek, WriteYourDescriptionHere)
{
    char buffer[4096];
    getDaysOfWeek(buffer);
    ASSERT_STREQ(buffer, "Su Mo Tu We Th Fr Sa\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}