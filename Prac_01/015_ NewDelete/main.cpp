#include <iostream>

int main() {
    
    int SIZE = 0, i;

    std::cin >> SIZE;

    int* arr = new int[SIZE];

    for(int j = 0; j < SIZE; j++) {
        std::cin >> arr[j];
    }

    std::cin >> i;

    std::cout << arr[arr[i]] << std::endl;

    delete[] arr;

    return 0;
    
}