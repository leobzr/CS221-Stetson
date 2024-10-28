#include <iostream>

using namespace std;

int main () {
    int *a;
    a = new int[5]; // allocating space for 5 integers
    a[0] = 20;
    *(a+1) = 24;  // a[1] = 24;
    a[2] = 28;
    a[3] = 32;
    a[4] = 36;  // Changed from a[5] to a[4] since a was declared with new int[5]

    int b = 10; // This is just a simple integer

    int *c;
    c = &a[2];  // Pointing to the address of a[2]

    int **d;
    d = new int*;  // Allocating memory for a pointer to an int
    *d = new int;  // Allocating memory for an integer
    **d = 5;  // Setting the value at the allocated space to 5

    int*** e;
    e = new int**[3];  // Allocating an array of 3 pointers to int**
    e[0] = &a;  // Store address of a in e[0]
    e[1] = &c;  // Store address of c in e[1]
    e[2] = (int**)&e;  // Store address of d in e[2]

    // Printing the values
    cout << "Array a:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    cout << "\nValue of b: " << b << endl;
    cout << "Address c points to (a[2]): " << c << endl;
    cout << "Value of d (pointer to pointer): " << **d << endl;
    
    cout << "\nPointer array e:" << endl;
    cout << "e[0] points to a: " << *e[0] << endl;
    cout << "e[1] points to c (which holds address of a[2]): " << (*e[1]) << endl;
    cout << "e[2] points to d (which holds value of itself): " << *e[2] << endl;

    // Delete commands
    delete[] a;  // Deallocating the array a
    delete *d;   // Deallocating the int that *d points to
    delete d;    // Deallocating the pointer d
    delete[] e;  // Deallocating the array of pointers e

    return 0;
}
