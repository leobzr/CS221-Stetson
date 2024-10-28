#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    fstream myfile ("myfile.txt", ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << "This is another line!";
        myfile.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}