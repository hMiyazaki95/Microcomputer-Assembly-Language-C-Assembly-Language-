#include "../src/getDays.c"
#include <gtest/gtest.h>

TEST(Days, Test)
{
    char buffer[1024];
    getDays(buffer, 1, 2019);
    ASSERT_STRCASENE(buffer, "January, 2019\n");// TODO
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}