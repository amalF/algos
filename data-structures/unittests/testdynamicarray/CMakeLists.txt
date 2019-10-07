FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testdynamicarray ${SRCS})
target_link_libraries(testdynamicarray dynamicarray ${GTEST_LIBRARIES} pthread)

ADD_TEST(NAME testdynamicarray
	COMMAND testdynamicarray)
