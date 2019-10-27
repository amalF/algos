FILE(GLOB SRCS *.cpp)

# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testdoublelinkedlist ${SRCS})
target_link_libraries(testdoublelinkedlist list gtest pthread)

ADD_TEST(NAME testdoublelinkedlist
	COMMAND testdoublelinkedlist)
