#include <iostream>
#include <array>
#include <algorithm>

int main() {
  
  std::array<int, 10> arr;

  for (auto &iter : arr)
    std::cin >> iter;

  auto min_max = std::minmax_element(begin(arr), end(arr));

  std::cout << *min_max.second << " " << *min_max.first << std::endl;

  return 0;

}