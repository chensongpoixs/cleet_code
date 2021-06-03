project(0525.ContiguousArray)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")
MESSAGE(STATUS ${PROJECT_NAME})
ADD_DEFINITIONS(-std=c++11 -g -Wall )
file(GLOB ALL_C_SRCS
        ./*.cpp
        )

add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME})