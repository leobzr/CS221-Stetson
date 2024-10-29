#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "CaesarCipher.h"
using namespace std;

int main(int argc, char** argv){
    char opt;
    string inputFileName;
    string outputFileName;
    int eflag, dflag, iflag, oflag;
    eflag = 0;
    dflag = 0;
    iflag = 0;
    oflag = 0;
    while( (opt = getopt(argc, argv, "i:o:ed")) != -1){
        switch(opt) {
            case 'i':
                iflag = 1;
                inputFileName = optarg;
                break;
            case 'o':
                oflag = 1;
                outputFileName = optarg;
                break;
            case 'e':
                eflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            default:
                cout << "Unknown option " << argv[0] << endl;
                return 1;
        }
    }
    if(argc != 6 || (iflag == 0) || (oflag == 0) ||(eflag == dflag)){
        cout << argv[0] << " option -i inputFileName.txt -o OutputFileName.bin" << endl;
        cout << " -e to encrypt" << endl;
        cout << " -d to decrypt" << endl;
        return 1;
    }

    cout << "Input file: " << inputFileName << endl;
    cout << "Output file: " << outputFileName << endl;

    if (eflag == 1) { 
        cout << "Encrypt Mode Selected." << endl;
    } else {
        cout << "Decrypt Mode Selected" << endl;
    }

    int shiftValue;
    cout << "Please enter the shift value (1 to 25): " << endl;
    cin >> shiftValue;

    if (shiftValue < 1 || shiftValue > 25) {
        cout << "Shift value must be between 1 and 25." << endl;
        return 1;
    }

    string text = "";
    char ch;

    if (eflag == 1) {
        cout << "Encrypt Mode" << endl; 

        fstream inputFile(inputFileName.c_str(), ios::in);
        if (!inputFile.is_open()) {
            cout << "Unable to open input file." << endl;
            return 1;
        }

        while (inputFile.get(ch)) {
            text += ch;
        }
        inputFile.close();

        string encryptedText = encryptText(text, shiftValue);

        // writing it to th binary file:
        fstream outputFile(outputFileName.c_str(), ios::out | ios::binary);
        if (!outputFile.is_open()) {
            cout << "Unable to open output file." << endl;
            return 1;
        }

        outputFile.write(encryptedText.c_str(), encryptedText.size());

        cout << "Encrypted binary file created: " << outputFileName << endl;
    } else if (dflag == 1) {
        cout << "Decryption Mode." << endl;

        fstream inputFile(inputFileName.c_str(), ios::in | ios::binary);
        if (!inputFile.is_open()) {
            cout << "Unable to open input file. " << endl;
            return 1;
        }

        inputFile.seekg(0, ios::end);
        int fileSize = inputFile.tellg();
        inputFile.seekg(0, ios::beg);

        char* buffer = new char[fileSize];
        inputFile.read(buffer, fileSize);
        inputFile.close();

        string encryptedText(buffer, fileSize);

        string decryptedText = decryptText(encryptedText, shiftValue);

        fstream outputFile(outputFileName.c_str(), ios::out);
        if (!outputFile.is_open()) {
            cout << "Unable to open output file." << endl;
            return 1;
        }

        outputFile << decryptedText;
        outputFile.close();

        cout << "Decrypted text file created: " << outputFileName << endl;
    }



    return 0;
}
