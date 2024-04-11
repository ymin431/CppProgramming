#include <iostream>

#include <memory>

using namespace std;


void update(int* a, int* b);

int main(){

    unique_ptr<int> pa {new int{}};
    unique_ptr<int> pb {new int{}};

    cin >> *pa >> *pb;

    update(pa.get(), pb.get());

    cout << *pa << endl;
    cout << *pb << endl;

    return 0;
}

void update(int* a, int* b){

    int temp;

    temp = (*a) + (*b);
    *b = *a - *b;
    *a = temp;

}