#include <iostream>
#include <iomanip>

int main() {

    float num1, num2;
    
    std::cin >> num1 >> num2;

    std::cout << std::fixed << std::setprecision(2) << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;


    return 0;
    
}