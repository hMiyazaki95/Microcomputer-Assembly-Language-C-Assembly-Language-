cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../out/)

enable_language(C)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runLongListTests testLongList.cpp ../src/long_list.c)
add_executable(runIStackTests testIStack.cpp ../src/istack.c)
add_executable(runIQueueTests testIQueue.cpp ../src/iqueue.c)
add_executable(runLinkedListTests testLinkedList.cpp ../src/linked_list.c)
add_executable(runQueueListTests testQueueList.cpp ../src/queue_list.c)

target_link_libraries(runLongListTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runIStackTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runIQueueTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runLinkedListTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runQueueListTests ${GTEST_LIBRARIES} pthread)
