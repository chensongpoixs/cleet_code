project(0381.Insert_Delete_GetRandom_O(1)_Duplicates_allowed)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")
MESSAGE(STATUS ${PROJECT_NAME})
file(GLOB ALL_C_SRCS
        ./*.c
        )

add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME})