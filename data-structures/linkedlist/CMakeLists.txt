#Declare the library
ADD_LIBRARY(linkedlist INTERFACE)

#Include Directory
TARGET_INCLUDE_DIRECTORIES(linkedlist INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
