project(cvptr)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")

file(GLOB ALL_CC_SRCS
        ./*.cpp
        )

set(ALL_LIB
        )
add_executable(${PROJECT_NAME} ${ALL_CC_SRCS})
target_link_libraries(${PROJECT_NAME} ${ALL_LIB})
