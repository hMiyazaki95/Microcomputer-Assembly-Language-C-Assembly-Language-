#include "../src/istack.c"
#include <gtest/gtest.h>

class IStack : public ::testing::Test {
    protected:
        void SetUp() override
        {
            istack_init(&stack);
        }

        void TearDown() override
        {
           istack_destroy(&stack);
        }

        istack_t stack;
}; 

TEST(IStackInit, Init)
{
    istack_t stack;
    istack_init(&stack);
    ASSERT_EQ(stack.size, 0);
    ASSERT_EQ(stack.capacity, 8);
}

TEST_F(IStack, PushOne)
{
    istack_push(&stack, 99);
    ASSERT_EQ(stack.size, 1);
    ASSERT_EQ(stack.capacity, 8);
}

TEST_F(IStack, Push8)
{
    for (int i = 0; i < 8; i++)
    {
        istack_push(&stack, 99);
    }
    ASSERT_EQ(stack.size, 8);
    ASSERT_EQ(stack.capacity, 8);
}

TEST_F(IStack, Push9)
{
    for (int i = 0; i < 9; i++)
    {
        istack_push(&stack, 99);
    }
    
    ASSERT_EQ(stack.size, 9);
    ASSERT_EQ(stack.capacity, 16);
}

TEST_F(IStack, Peek16)
{
    for (int i = 0; i < 16; i++)
    {
        istack_push(&stack, i);
        ASSERT_EQ(istack_peek(&stack), i);
    }
    
    ASSERT_EQ(stack.size, 16);
    ASSERT_EQ(stack.capacity, 16);
}

TEST_F(IStack, Pop16)
{
    for (int i = 0; i < 16; i++)
    {
        istack_push(&stack, i);
    }
    
    ASSERT_EQ(stack.size, 16);
    ASSERT_EQ(stack.capacity, 16);
    
    for (int i = 15; i >= 0; i--)
    {
        ASSERT_EQ(istack_pop(&stack), i);
    }
}

TEST_F(IStack, Destroy)
{
    istack_push(&stack, 99);
    istack_destroy(&stack);
    
    ASSERT_EQ(stack.size, 0);
    ASSERT_EQ(stack.capacity, 0);
    ASSERT_EQ(stack.index, -1);
    ASSERT_EQ(stack.data, nullptr);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
