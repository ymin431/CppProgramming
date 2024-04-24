#include "complex.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    complex c1;
    complex c11();  //function declaration
    complex c2 = 1;
    complex c3(1);
    complex c4 = complex();
    cout << c1 << '\n';
    cout << typeid(c11).name() << '\n';

    complex c5{1, 2};
    complex c6 = {1, 6};
    complex c7{};
    complex c8 = {};
    cout << c5 << '\n';
    cout << c5.add(c6) << '\n';
    cout << c5.add(1) << '\n';

    auto c9 = complex{1};
    cout << typeid(c9).name() << '\n';
    auto c10 = complex{1, 1};
    cout << typeid(c10).name() << '\n';

    return 0;
}