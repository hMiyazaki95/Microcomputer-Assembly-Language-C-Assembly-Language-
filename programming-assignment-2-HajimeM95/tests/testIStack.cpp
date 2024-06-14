#include "../src/istack.c"
#include <gtest/gtest.h>

// Fixture
class IStackTest : public ::testing::Test {
    protected:
        void SetUp() override 
        {
            istack_init(&st);
        }
        
        void TearDown() override 
        {
          return;
        }
        istack_t st;
};

TEST(IStackTT, Init)
{
    
}

TEST_F(IStackTest, InitTest)
{
    istack_init(&st);
    ASSERT_EQ(st.capacity, 8);
}

TEST_F(IStackTest, PushTest)
{
    for (int i=1; i<7; i++) {
        istack_push(&st, i);
    }
    ASSERT_EQ(st.capacity, 8);
    ASSERT_EQ(st.data[0], 1);
    ASSERT_EQ(st.data[1], 2);
    ASSERT_EQ(st.data[2], 3);
    ASSERT_EQ(st.data[3], 4);
    ASSERT_EQ(st.data[4], 5);
    ASSERT_EQ(st.data[5], 6);
        
    for (int i=1; i<15; i++) {
        istack_push(&st, i*10);
    }
    ASSERT_EQ(st.capacity,32);
    ASSERT_EQ(st.data[17],120);
}

TEST_F(IStackTest, PopTest)
{
    for (int i=0; i<20; i++) {
        istack_push(&st, (i*10));
    }
    ASSERT_EQ(st.capacity,32);
    ASSERT_EQ(st.index,19);
    ASSERT_EQ(st.size,20);
    ASSERT_EQ(st.data[19],190);
    ASSERT_EQ(istack_pop(&st),190);
    ASSERT_EQ(istack_pop(&st),180);
}

TEST_F(IStackTest, PeekTest)
{
    for (int i=1;i<20;i++) {
        istack_push(&st,i*100);
    }
    ASSERT_EQ(istack_peek(&st),1900);
    ASSERT_EQ(istack_pop(&st),1900);
    ASSERT_EQ(istack_peek(&st),1800);
    ASSERT_EQ(istack_pop(&st),1800);
}

TEST_F(IStackTest, DestroyTest)
{
    for (int i=1;i<7;i++) {
        istack_push(&st,i*1000);
    }
    ASSERT_EQ(istack_peek(&st),6000);
    istack_destroy(&st);
    ASSERT_EQ(st.size,0);
    ASSERT_EQ(st.capacity,0);
    ASSERT_EQ(st.index,-1);
    
    
}

// TODO: write tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}