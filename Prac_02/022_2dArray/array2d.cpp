#include <iostream>

int main() {

  int SIZE1 = 0, SIZE2 = 0;

  int sum = 0;

  std::cin >> SIZE1 >> SIZE2;

  int** arr = new int*[SIZE1];
  int* row_sum = new int[SIZE1];
  int* col_sum = new int [SIZE2];

  for (int i = 0; i < SIZE1; i++) {
    arr[i] = new int[SIZE2];
    for (int j = 0; j < SIZE2; j++) {
      std::cin >> arr[i][j];
      sum += arr[i][j];
    } 
    row_sum[i] = sum;
    sum = 0;
  }

  for (int j = 0; j < SIZE2; j++) {
    for (int i = 0; i < SIZE1; i++) {
      sum += arr[i][j];
    }
    col_sum[j] = sum;
    sum = 0;
  }

  for (int i = 0; i < SIZE1; i++) {
    std::cout << row_sum[i] << " ";
  }

  std::cout << "\n";

  for (int j = 0; j < SIZE2; j++) {
    std::cout << col_sum[j] << " ";
  }

  delete [] arr;
  
  return 0;

}