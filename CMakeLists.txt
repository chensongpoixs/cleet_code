project(cleet_code)
cmake_minimum_required(VERSION 2.8)
MESSAGE(STATUS "#########################")
SET(CMAKE_BUILD_TYPE Release)
ADD_DEFINITIONS(-g -Wall )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(1.sum_of_two_numbers)
add_subdirectory(2.add_two_numbers)
add_subdirectory(3.longest_substring_without_repeating_characters)
add_subdirectory(4.find_the_median_of_two_positive_arrays)
#add_subdirectory(cvptr)
add_subdirectory(5.longest_palindromic_substring)
add_subdirectory(208.trie_tree)
add_subdirectory(211.add_and_search_word)

