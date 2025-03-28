#include <iostream>

#include "tuple_util.h"

int main() {
  std::tuple<float, int, std::string> t { 1.1, 10, "Hello" };

  int ind = 2;

  std::get<0>(t) = 1.2;

  fun::set_tuple_value(t, ind, std::string("hell"));

  std::cout << fun::get_tuple_value<float>(t, 0) << ' '
    << fun::get_tuple_value<int>(t, 1) << ' '
    << fun::get_tuple_value<std::string>(t, 2);

  return 0;
}
