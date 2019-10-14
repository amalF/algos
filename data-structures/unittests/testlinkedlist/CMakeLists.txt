FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testlinkedlist ${SRCS})
target_link_libraries(testlinkedlist linkedlist gtest pthread)

ADD_TEST(NAME testlinkedlist
	COMMAND testlinkedlist)
