#include "../src/getFirstDayOfMonth.c"
#include <gtest/gtest.h>

TEST(FirstDayOfMonth, Jan2019)
{
    
// TODO
    int First_day;
    char buffer[1024];
    First_day = getFirstDayOfMonth(1, 2019);
    
    if(First_day = 0) 
    {
        ASSERT_STREQ(buffer, "Su");
    } 
    else if(First_day = 1) 
    {
        ASSERT_STREQ(buffer, "Mo");
    } 
    else if(First_day = 2) 
    {
        ASSERT_STREQ(buffer, "Tu");
    } 
    else if(First_day = 3) 
    {
        ASSERT_STREQ(buffer, "We");
    } 
    else if(First_day = 4) 
    {
        ASSERT_STREQ(buffer, "Th");
    } 
    else if(First_day = 5) 
    {
        ASSERT_STREQ(buffer, "Fr");
    } 
    else if(First_day = 6) 
    {
        ASSERT_STREQ(buffer, "Sa");
    }
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}