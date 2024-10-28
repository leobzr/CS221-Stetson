#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main () { 
    char buffer[] = "Hello";
    fstream myfile("myfile", ios::out | ios::binary);
    if (myfile.is_open()) { 
        myfile.write(buffer, 5);
        myfile.close();
    } else { 
        cout << "Unable to open file";
    }
    return 0;
}