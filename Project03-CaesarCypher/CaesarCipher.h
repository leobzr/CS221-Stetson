#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>
using namespace std;

// if something goes wrong, the error is probably here lmao.
string encryptText(string text, int shift);
string decryptText(string text, int shift);


#endif