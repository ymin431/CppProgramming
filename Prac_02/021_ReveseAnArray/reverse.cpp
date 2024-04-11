#include <iostream>

int main() {

  int SIZE = 0;
  std::cin >> SIZE;

  int* arr = new int[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    std::cin >> arr[i];
  }

  for (int i = SIZE; i > 0; i--) {
    std::cout << arr[i - 1] << " ";
  }
  
  delete [] arr;

  return 0;

}