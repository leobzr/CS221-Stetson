#include <iostream>

using namespace std;

int main () {
    int *a;
    a = new int[5];
    a[0] = 20;
    *(a+1) = 24; // a[1] = 24;
    a[2] = 28;
    a[3] = 32;
    a[5] = 36;

    int b = 10; // that is the number that it is stored, there are no intermediate values
    

    return 0;
}