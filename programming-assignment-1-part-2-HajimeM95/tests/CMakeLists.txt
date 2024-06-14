cmake_minimum_required(VERSION 2.6)



# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_language(C ASM-ATT)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runGetDaysTests testGetDays.cpp ../src/getDays.s ../src/isLeapYear.s ../src/getFirstDayOfMonth.s)
add_executable(runGetDaysOfWeekTests testGetDaysOfWeek.cpp ../src/getDaysOfWeek.s)
add_executable(runGetFirstDayOfMonthTests testGetFirstDayOfMonth.cpp ../src/isLeapYear.s)
add_executable(runGetMonthYearTests ../src/getMonthYear.s testGetMonthYear.cpp)
add_executable(runGetNumOfDaysInMonthTests testGetNumOfDaysInMonth.cpp ../src/getNumOfDaysInMonth.s ../src/isLeapYear.s)
add_executable(runIsLeapYearTests testIsLeapYear.cpp ../src/isLeapYear.s)

target_link_libraries(runGetDaysTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetDaysOfWeekTests  ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetFirstDayOfMonthTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetMonthYearTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runGetNumOfDaysInMonthTests  ${GTEST_LIBRARIES} pthread)
target_link_libraries(runIsLeapYearTests  ${GTEST_LIBRARIES} pthread)
