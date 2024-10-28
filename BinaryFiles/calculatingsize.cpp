#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() { 
    streampos begin, end;
    fstream myfile("myfile", ios::in | ios::binary);
    if (myfile.is_open()) { 
        begin = myfile.tellg();
        myfile.seekg(0, ios::end);
        end = myfile.tellg();
        cout << "File size is: " << (end-begin) << "bytes \n";
        myfile.close();
    } else { 
        cout << "Unable to open file.";
    }
    return 0;
}