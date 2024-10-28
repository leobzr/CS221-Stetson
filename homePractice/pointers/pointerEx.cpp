#include <iostream>

using namespace std;

int main() {
    //working with pointers
    int a = 42; // if you want to take a direct number. 

    int *b;
    b = new int[3]; //pointer array
    b[0] = 10;
    b[1] = 11;
    b[2] = a; //getting the value of a (42)

    // C needs is the address in the memory of 11!
    int *c;
    c = &b[1]; //goes to b[1] (11) and hold the address; 


    //D needs to to through all previous pointer to get to a.
    int **d;
    d = &c;


    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;


    return 0;

    




}