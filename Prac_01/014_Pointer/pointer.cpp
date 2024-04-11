#include "pointer.h"

void update(int* a, int* b){

    int temp;

    temp = *a + *b;
    *b = *a - *b;
    *a = temp;

}