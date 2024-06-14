#include "../src/iqueue.c"
#include <gtest/gtest.h>

TEST(IQueue, IQueueInit)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
    ASSERT_EQ(queue.capacity, 8);
}

TEST(IQueue, IQueueEnQueue)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
    
    for (int i=0; i<10; i++) {
        iqueue_enqueue(&queue, i*10);
    }
    
    ASSERT_EQ(queue.size, 10);
    ASSERT_EQ(queue.capacity, 16);
    ASSERT_EQ(queue.data[0], 0);
    ASSERT_EQ(queue.data[1], 10);
    ASSERT_EQ(queue.data[2], 20);
    ASSERT_EQ(queue.data[3], 30);
}

TEST(IQueue, IQueueDeQueue)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
    
    for (int i=0; i<10; i++) {
        iqueue_enqueue(&queue, i*10);
    }
    
    ASSERT_EQ(queue.size, 10);
    ASSERT_EQ(queue.capacity, 16);
    ASSERT_EQ(queue.data[0], 0);
    ASSERT_EQ(queue.data[1], 10);
    ASSERT_EQ(queue.data[2], 20);
    ASSERT_EQ(queue.data[3], 30);
    
    ASSERT_EQ(iqueue_dequeue(&queue), 0);
    ASSERT_EQ(iqueue_dequeue(&queue), 10);
    ASSERT_EQ(iqueue_dequeue(&queue), 20);
    ASSERT_EQ(iqueue_dequeue(&queue), 30);
    ASSERT_EQ(queue.size, 6);
    ASSERT_EQ(queue.capacity, 16);
}
TEST(IQueue, IQueuePeek)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
    
    for (int i=0; i<10; i++) {
        iqueue_enqueue(&queue, i*10);
    }
    
    ASSERT_EQ(queue.size, 10);
    ASSERT_EQ(queue.capacity, 16);
    ASSERT_EQ(queue.data[0], 0);
    ASSERT_EQ(queue.data[1], 10);
    ASSERT_EQ(queue.data[2], 20);
    ASSERT_EQ(queue.data[3], 30);
    
    ASSERT_EQ(iqueue_peek(&queue), 0);
    ASSERT_EQ(iqueue_dequeue(&queue), 0);
    ASSERT_EQ(iqueue_peek(&queue), 10);
    ASSERT_EQ(iqueue_dequeue(&queue), 10);
    ASSERT_EQ(iqueue_peek(&queue), 20);
    ASSERT_EQ(iqueue_dequeue(&queue), 20);
    ASSERT_EQ(iqueue_peek(&queue), 30);
    ASSERT_EQ(iqueue_dequeue(&queue), 30);
    ASSERT_EQ(queue.size, 6);
    ASSERT_EQ(queue.capacity, 16);
}
TEST(IQueue, IQueueDestroy)
{
    iqueue_t queue;
    iqueue_init(&queue);
    ASSERT_EQ(queue.size, 0);
    ASSERT_EQ(queue.capacity, 8);
    
    iqueue_destroy(&queue);
    ASSERT_EQ(queue.size, 0);
    ASSERT_EQ(queue.capacity, 0);
}
// TODO: write tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}