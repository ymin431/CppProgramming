#include <iostream>

void my_swap(int&, int&);

int main() {

    int m, n;

    std::cin >> m >> n;

    my_swap(m, n);

    std::cout << m << " " << n;

}

void my_swap(int& ref_a, int& ref_b) {

    int temp;
    
    temp = ref_a;
    ref_a = ref_b;
    ref_b = temp;

}