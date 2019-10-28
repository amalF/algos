FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testqueue ${SRCS})
TARGET_LINK_LIBRARIES(testqueue queue list gtest pthread)

ADD_TEST(NAME testqueue
	COMMAND testqueue)
