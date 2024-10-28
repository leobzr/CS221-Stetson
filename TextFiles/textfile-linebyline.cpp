#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () { 
    string line;
    fstream myfile("myfile.txt", ios::in);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    } else {
        cout << "Unable to return file";
    }

    return 0;
}