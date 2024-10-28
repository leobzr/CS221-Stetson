#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() { 
    string line;
    fstream myfile ("myfile.txt", ios::out);
    if (myfile.is_open()) { 
        myfile << "This is the first line! \n";
        myfile.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}
