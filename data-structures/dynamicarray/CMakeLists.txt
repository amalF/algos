#SET(dynamicarray_SRCS
#	dynamicarray.hpp
#	dynamicarray.h)
#
#Declare the library
ADD_LIBRARY(dynamicarray INTERFACE)#STATIC ${dynamicarray_SRCS})

#Include Directory
TARGET_INCLUDE_DIRECTORIES(dynamicarray INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
