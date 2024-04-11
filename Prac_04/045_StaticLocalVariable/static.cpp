#include "static.h"

void inc(std::promise<int> && result) {
    //your implementation
    result.set_value(COUNTER);
}

int getCounter() {
    // your implementation
    return COUNTER;
}
