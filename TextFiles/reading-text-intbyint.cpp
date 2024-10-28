#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    int number;
    fstream myfile ("myfile.txt", ios::in);
    if (myfile.is_open()) {
        while (myfile >> number) {
            cout << number << endl;
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
    return 0;
}