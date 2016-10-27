cmake_minimum_required(VERSION 3.0)
project(nan_bindings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC") #curlpp has broken build system

add_library(${PROJECT_NAME} SHARED
    nan_bindings.cpp
    library.cpp
)

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})

# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
