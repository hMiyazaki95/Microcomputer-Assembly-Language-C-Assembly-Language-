#include "../src/iqueue.c"
#include <gtest/gtest.h>

TEST(IStack, TestName)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
}

// TODO: write tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}