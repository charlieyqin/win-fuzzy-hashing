cmake_minimum_required (VERSION 2.6)
project (win_fuzzy_hashing)

# set mt md
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

# use unicode
add_definitions(-D_UNICODE)

# add head files
file(GLOB_RECURSE win_fuzzy_hashing_lib_head_files "./win_fuzzy_hashing/include/*.h")

# add source file
aux_source_directory("./win_fuzzy_hashing/src" win_fuzzy_hashing_lib_src_files)

# add thirdparty head files directoryes
# include_directories("dir")
add_library(win_fuzzy_hashing ${win_fuzzy_hashing_lib_head_files} ${win_fuzzy_hashing_lib_src_files})

# add gtest
if (NOT TARGET gtest)
set(gtest_lib_directory "./googletest/googletest/")
add_subdirectory(${gtest_lib_directory} gtest)
include_directories("${gtest_lib_directory}include")
file(GLOB_RECURSE gtest_lib_head_files "${gtest_lib_directory}include/*.h")
source_group("gtest" FILES ${gtest_lib_head_files})
endif()

aux_source_directory("./win_fuzzy_hashing_unittest/src" win_fuzzy_hashing_unittest_src_files)
file(GLOB_RECURSE win_fuzzy_hashing_unittest_include_files "./win_fuzzy_hashing_unittest/include/*.h")
add_executable(win_fuzzy_hashing_unittest ${win_fuzzy_hashing_unittest_src_files} ${win_fuzzy_hashing_unittest_include_files} ${gtest_lib_head_files})
# target_link_libraries(win_fuzzy_hashing_unittest win_fuzzy_hashing)
target_link_libraries(win_fuzzy_hashing_unittest gtest)