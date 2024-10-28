#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv){
    char opt;
    string inputFile;
    string outputFile;
    int eflag, dflag, iflag, oflag;
    eflag = 0;
    dflag = 0;
    iflag = 0;
    oflag = 0;
    while( (opt = getopt(argc, argv, "i:o:ed")) != -1){
        switch(opt){
            case 'i':
                iflag = 1;
                inputFile = optarg;
                break;
            case 'o':
                oflag = 1;
                outputFile = optarg;
                break;
            case 'e':
                eflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            default:
                cout << "Unknown option " << argv[0] << endl;
        }
    }
    if(argc != 6 || (iflag == 0) || (oflag == 0) ||(eflag == dflag)){
        cout << argv[0] << " option -i inputFileName.txt -o OutputFileName.bin" << endl;
        cout << " -e to encrypt" << endl;
        cout << " -d to decrypt" << endl;
        return 1;
    }

    cout << inputFile << endl;
    cout << outputFile << endl;
    if (eflag == 1) { 
        cout << "Encrypt Mode" << endl;
    } else {
        cout << "Decrypt Mode" << endl;
    }



    return 0;
}
