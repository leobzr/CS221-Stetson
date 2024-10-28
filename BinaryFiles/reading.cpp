#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() { 
    streampos size;
    char * buffer;
    fstream myfile("myfile", ios::in | ios::binary | ios::ate);
    if (myfile.is_open()) {
        size = myfile.tellg();
        buffer = new char[size];
        myfile.seekg(0, ios::beg);
        myfile.read(buffer, size);
        myfile.close();
    } else {
        cout << "Unable to open";
    }

    cout << "File content is: " << buffer << endl;
    delete[] buffer;
    return 0;
}