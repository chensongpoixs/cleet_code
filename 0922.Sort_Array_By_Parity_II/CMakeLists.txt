project(0922.Sort_Array_By_Parity_II)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")

file(GLOB ALL_C_SRCS
        ./*.c
        )

add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME})