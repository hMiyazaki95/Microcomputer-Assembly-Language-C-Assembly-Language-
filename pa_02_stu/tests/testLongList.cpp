#include "../src/long_list.c"
#include <gtest/gtest.h>

//
// This is a text fixture. It creates and destroys the `list` var for each TEST_F.
// Only tests that explicitly use the LongList fixture will get this support.
// Read: https://github.com/google/googletest/blob/master/googletest/docs/primer.md
//
class LongList : public ::testing::Test {
    protected:
        void SetUp() override 
        {
            list = long_list_init();
        }
        
        void TearDown() override 
        {
           free(list);
        }

        long_list_node_t *list;
};

TEST(LongListInit, Init)
{
    ASSERT_NE(long_list_init(), nullptr) << "init should return a pointer";
    ASSERT_EQ(long_list_init()->next, nullptr) << "next must be initialized to NULL";
}

TEST_F(LongList, Add)
{
    long_list_add(list, 42);
    ASSERT_EQ(list->next->data, 42);
    
    long_list_add(list, 99);
    ASSERT_EQ(list->next->next->data, 99);
}

TEST_F(LongList, Get)
{
    list->data = 0;
    
    for (int i = 1; i < 5; i++)
    {
        long_list_add(list, i);
    }
    
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(long_list_get(list, i), i);
    }
}

TEST_F(LongList, Set)
{
    list->data = 0;
    
    for (int i = 1; i < 5; i++)
    {
        long_list_add(list, i);
    }
    
    for (int i = 0; i < 5; i++)
    {
        long_list_set(list, i, i * 2);
    }
    
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(long_list_get(list, i), i * 2);
    }
}

TEST_F(LongList, Remove)
{
    list->data = 0;
    
    for (int i = 1; i < 5; i++)
    {
        long_list_add(list, i);
    }  
    
    // before   0 1 2 3 4
    // after    0 2 3 4
    long_list_remove(list, 1);
    ASSERT_EQ(long_list_get(list, 1), 2);
    
    // after    0 1 4
    long_list_remove(list, 2);
    ASSERT_EQ(long_list_get(list, 2), 4);
}

TEST_F(LongList, RemoveFirst)
{
    list->data = 0;
    long_list_add(list, 1);
    
    long_list_remove(list, 0);
    ASSERT_EQ(list->data, 1);
    
    long_list_remove(list, 0);
    ASSERT_EQ(list->data, 1);
}

TEST_F(LongList, RemoveLast)
{
    ASSERT_NE(list, nullptr);
    list->data = 0;
    long_list_add(list, 11);
    long_list_add(list, 22);
    
    long_list_remove(list, 1);
    ASSERT_EQ(list->next->next, nullptr);
}

TEST_F(LongList, Contains)
{
    list->data = 0;
    long_list_add(list, 11);
    long_list_add(list, 22);
    long_list_add(list, 33);
    long_list_add(list, 44);
    
    ASSERT_TRUE(long_list_contains(list, 22)) << "List shoud contain 22";
    ASSERT_TRUE(long_list_contains(list, 44)) << "List shoud contain 44";
    ASSERT_FALSE(long_list_contains(list, 55)) << "List shoud NOT contain 55";
}

TEST_F(LongList, Size)
{
    list->data = 0;
    long_list_add(list, 11);
    long_list_add(list, 22);
    long_list_add(list, 33);
    long_list_add(list, 44); 
    
    ASSERT_EQ(long_list_size(list), 5) << "List should be length 5";
    
    long_list_remove(list, 0);
    ASSERT_EQ(long_list_size(list), 4) << "List should be length 4";
}

TEST_F(LongList, Destroy)
{
    list->data = 0;
    long_list_add(list, 11);
    long_list_add(list, 22);
    long_list_add(list, 33);
    long_list_add(list, 44);
    
    ASSERT_EQ(long_list_size(list), 5) << "List should be length 5";

    long_list_destroy(list);
    ASSERT_EQ(list->next, nullptr) << "List should be destroyed and next set to NULL";

    ASSERT_EQ(long_list_size(list), 1) << "Should only be able to see remnant of first node";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}