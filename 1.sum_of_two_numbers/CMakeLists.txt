project(1.csum_of_two_numbers)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
MESSAGE(STATUS "#########################")

file(GLOB ALL_C_SRCS
             ./*.c
)

set(ALL_LIB  	pthread
				)
add_executable(${PROJECT_NAME} ${ALL_C_SRCS})
target_link_libraries(${PROJECT_NAME} ${ALL_LIB})
