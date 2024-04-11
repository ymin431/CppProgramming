#include "Temperature.cpp"

SCALE getScale(char scale) {
    return scale == 'C' ? CELSIUS : FAHRENHEIT;
}

Temperature createTemperatureFromKeyboard(){
    float degree;
    char scale;
    std::cin >> degree >> scale;
    return Temperature {degree, getScale(scale)};
}

int main() {
    Temperature t1 = createTemperatureFromKeyboard();
    std::cout << t1.Temperature::print();

    Temperature t2 = createTemperatureFromKeyboard();
    std::cout << t2.Temperature::print();

    Temperature t3 = t1.Temperature::add(t2);
    std::cout << t3.Temperature::print();

    Temperature t4 = t2.Temperature::add(t1);
    std::cout << t4.Temperature::print();

    Temperature t5 = t3.Temperature::add(t4);
    std::cout << t5.Temperature::print();

    return 0;
}