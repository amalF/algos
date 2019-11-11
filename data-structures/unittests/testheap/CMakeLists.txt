FILE(GLOB SRCS *.cpp)


# Link with what we want to test and the GTest and pthread libr
ADD_EXECUTABLE(testheap ${SRCS})
TARGET_LINK_LIBRARIES(testheap heap dynamicarray gtest pthread)

ADD_TEST(NAME testheap
	COMMAND testheap)
