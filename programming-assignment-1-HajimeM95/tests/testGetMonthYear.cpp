#include "../src/getMonthYear.c"
#include <gtest/gtest.h>

TEST(MonthYear, Jan2019)
{
    char buffer[1024];
    getMonthYear(buffer, 1, 2019);
    ASSERT_STRCASENE(buffer, "January, 2019\n");
    
}

// TODO: write more tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}