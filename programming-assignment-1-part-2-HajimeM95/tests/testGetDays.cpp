#include "../src/cal.h"
#include <gtest/gtest.h>

TEST(Days, WriteYourDescriptionHere)
{
    char buffer[1024];
    getDays(buffer, 1, 2019);
    ASSERT_STRCASENE(buffer, "January, 2019\n");
}
./runGetFirstDayOfMonthTests
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}