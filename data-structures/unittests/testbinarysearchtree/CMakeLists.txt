FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testbst ${SRCS})
TARGET_LINK_LIBRARIES(testbst binarysearchtree queue list gtest pthread)

ADD_TEST(NAME testbst
	COMMAND testbst)
