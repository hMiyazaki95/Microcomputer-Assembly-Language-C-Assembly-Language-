#include "../src/queue_list.c"
#include <gtest/gtest.h>

TEST(LongList, TestName)
{
    queue_list_t *list = queue_list_init();
    ASSERT_NE(list, nullptr);
}

// TODO: write tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}