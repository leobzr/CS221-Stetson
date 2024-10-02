#include <iostream>

using namespace std;

int main() {
    int *p;
    p = new int;
    *p = 42;
    cout << "value of p: " << p << ", deferenced value: " << *p << endl;
    delete p;

    int *b  = new int[3]; //this is an array
    b[0] = 1;
    *b = 1;
    *(b+1) = 6;
    b[1] = 6;
    cout << b[1] << " " << *b+1 << " " << *(b+1) << endl; // note the difference in this operation this will be on the test
    // since this is an array, to delete it you gotta do:
    delete[] b;

    // 2D Pointers - Specially used for 2d arrays
    int **d = new int*;
    *d = new int;
    **d = 100;
    




    return 0; 
}