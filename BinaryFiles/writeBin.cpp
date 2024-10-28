#include <iostream>
#include <fstream>
using namespace std;

int main() { 
    int number = 250;
    fstream myfile("myfile", ios::out | ios::binary);
    if (myfile.is_open()) {
        myfile.write( reinterpret_cast<const char*> (&number), sizeof(number));
        myfile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    cout << "The file content is: " << number << endl;
    return 0;
}