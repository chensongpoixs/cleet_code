project(0012.integer_to_roman)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")
MESSAGE(STATUS ${PROJECT_NAME})
file(GLOB ALL_C_SRCS
        ./*.c
        )

add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME})