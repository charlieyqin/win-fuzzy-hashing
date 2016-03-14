#include <type_traits>
#include "gtest//gtest.h"
#include "../../win_fuzzy_hashing/include/fuzzy.h"


TEST(fuzzy_hash_buf, result) {
  unsigned char buffer[] = "hello world";
  int buffer_size = std::extent<decltype(buffer)>::value;
  char result_buffer[1024] = {0};
  int return_value = fuzzy_hash_buf(buffer, buffer_size, result_buffer);
}





