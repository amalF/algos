FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(teststack ${SRCS})
TARGET_LINK_LIBRARIES(teststack stack linkedlist gtest pthread)

ADD_TEST(NAME teststack
	COMMAND teststack)
