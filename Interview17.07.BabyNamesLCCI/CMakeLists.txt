project(Interview17.07.BabyNamesLCCI)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")
MESSAGE(STATUS ${PROJECT_NAME})
ADD_DEFINITIONS(-std=c++11 )
file(GLOB ALL_C_SRCS
        ./*.cpp
        )

add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME})