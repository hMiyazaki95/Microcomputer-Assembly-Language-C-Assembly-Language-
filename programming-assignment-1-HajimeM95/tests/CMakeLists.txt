cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../out/)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runGetDaysTests testGetDays.cpp)
add_executable(runGetDaysOfWeekTests testGetDaysOfWeek.cpp)
add_executable(runGetFirstDayOfMonthTests testGetFirstDayOfMonth.cpp)
add_executable(runGetMonthYearTests testGetMonthYear.cpp)
add_executable(runGetNumOfDaysInMonthTests testGetNumOfDaysInMonth.cpp)
add_executable(runIsLeapYearTests testIsLeapYear.cpp)

target_link_libraries(runGetDaysTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetDaysOfWeekTests  ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetFirstDayOfMonthTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetMonthYearTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetNumOfDaysInMonthTests  ${GTEST_LIBRARIES} pthread)
target_link_libraries(runIsLeapYearTests  ${GTEST_LIBRARIES} pthread)