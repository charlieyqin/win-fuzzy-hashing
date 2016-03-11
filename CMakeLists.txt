cmake_minimum_required (VERSION 2.6)
project (win_fuzzy_hashing)


# add head files
file(GLOB_RECURSE win_fuzzy_hashing_lib_head_files "./win_fuzzy_hashing/include/*.h")

# add source file
aux_source_directory("./win_fuzzy_hashing/src" win_fuzzy_hashing_lib_src_files)

# add thirdparty head files directoryes
# include_directories("dir")
add_library(win_fuzzy_hashing ${win_fuzzy_hashing_lib_head_files} ${win_fuzzy_hashing_lib_src_files})


