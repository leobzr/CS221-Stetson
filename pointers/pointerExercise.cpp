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

    int *c;
    c = &a[2]; // it says: go to a at 2, get the value and find where it is stored. This is what we want to find. 

    int **d;
    d = new int*;// creating 0x40 nad putting it inside 0x28 address. Now we can jump over to 0x44
    *d = new int;
    **d = 5; 

    int ***e;
    e = new int**[3];
    e[0] = &a; //take the address of a and store it in the pointer array
    e[1] = &c; //take the address of c and store it inside the pointer array
    e[2] = (int**)&e; //same here!

    // delete commands:
    delete[] a; 
    delete* d;
    delete d;
    delete[] e;

    return 0;
}

