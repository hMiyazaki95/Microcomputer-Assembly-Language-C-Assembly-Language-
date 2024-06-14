#include "../src/linked_list.c"
#include <gtest/gtest.h>

class LinkedList : public ::testing::Test {
    protected:
        void SetUp() override 
        {
            list = linked_list_init();
        }
        
        void TearDown() override 
        {
           free(list);
        }
        list_node_t *list;
};

TEST(LL, LLInit)
{
    list_node_t *list = linked_list_init();
    ASSERT_NE(list, nullptr);
}

TEST_F(LinkedList, LinkedListAdd)
{
    int i1, i2;
    i1=42;
    i2=99;
    linked_list_add(list, &i1);
    ASSERT_EQ(*(int *)list->next->data, 42);
    
    linked_list_add(list, &i2);
    ASSERT_EQ(*(int *)list->next->next->data, 99);
}

TEST_F(LinkedList, LinkedListSet)
{
    int i1, i2, i3, i4, i5, i6;
    i1=0;
    i2=10;
    i3=20;
    i4=30;
    i5=40;
    i6=50;
    
    linked_list_add(list, &i1);
    linked_list_add(list, &i2);
    linked_list_add(list, &i3);
    linked_list_add(list, &i4);
    linked_list_add(list, &i5);
    linked_list_add(list, &i6);
    
    int s1, s2, s3, s4, s5;
    s1 = 0;
    s2 = 2;
    s3 = 4;
    s4 = 6; 
    s5 = 8;
        
    linked_list_set(list, 0, &s1);
    linked_list_set(list, 1, &s2);
    linked_list_set(list, 2, &s3);
    linked_list_set(list, 3, &s4);
    linked_list_set(list, 4, &s5);
   
    ASSERT_EQ(*(int *)linked_list_get(list, 0), 0);
    ASSERT_EQ(*(int *)linked_list_get(list, 2), 4);
    ASSERT_EQ(*(int *)linked_list_get(list, 3), 6);
    ASSERT_EQ(*(int *)linked_list_get(list, 4), 8);
}


TEST_F(LinkedList, LinkedListRemove)
{
    list_node_t *c;
    int r1, r2, r3, r4, r5;
    r1=0;
    r2=1;
    r3=2;
    r4=3;
    r5=4;
    
    linked_list_add(list, &r1);
    linked_list_add(list, &r2);
    linked_list_add(list, &r3);
    linked_list_add(list, &r4);
    linked_list_add(list, &r5);

    // before   0 1 2 3 4
    // after    0 2 3 4
    linked_list_remove(list, 1);
    ASSERT_EQ(*(int *)linked_list_get(list, 1), 2);
    
    // after    0 2 4
    linked_list_remove(list, 2);
    ASSERT_EQ(*(int *)linked_list_get(list, 1), 2);
    ASSERT_EQ(*(int *)linked_list_get(list, 2), 4);
}

TEST_F(LinkedList, LinkedListContains)
{
    int a1, a2, a3, a4, a55;
    a1=11;
    a2=22;
    a3=33;
    a4=44;
    a55=55;
    
  
    linked_list_add(list, &a1);
    linked_list_add(list, &a2);
    linked_list_add(list, &a3);
    linked_list_add(list, &a4);
    
    ASSERT_TRUE(linked_list_contains(list, &a1)) << "List shoud contain 22";
    ASSERT_TRUE(linked_list_contains(list, &a4)) << "List shoud contain 44";
    ASSERT_FALSE(linked_list_contains(list, &a55)) << "List shoud NOT contain 55";
}


TEST_F(LinkedList, Size)
{
    int ad1, ad2, ad3, ad4;
    ad1=11;
    ad2=22;
    ad3=33;
    ad4=44;
    
    linked_list_add(list, &ad1);
    linked_list_add(list, &ad2);
    linked_list_add(list, &ad3);
    linked_list_add(list, &ad4); 
    
    ASSERT_EQ(linked_list_size(list), 5) << "List should be length 5";
    
    linked_list_remove(list, 1);
    ASSERT_EQ(linked_list_size(list), 4) << "List should be length 4";
}

TEST_F(LinkedList, Destroy)
{
    int a1, a2, a3, a4;
    a1=11;
    a2=22;
    a3=33;
    a4=44;
    
    linked_list_add(list, &a1);
    linked_list_add(list, &a2);
    linked_list_add(list, &a3);
    linked_list_add(list, &a4);
    
    ASSERT_EQ(linked_list_size(list), 5) << "List should be length 5";

    linked_list_destroy(list);
    ASSERT_EQ(list->next, nullptr) << "List should be destroyed and next set to NULL";

    ASSERT_EQ(linked_list_size(list), 1) << "Should only be able to see remnant of first node";
}
// TODO: write tests

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}