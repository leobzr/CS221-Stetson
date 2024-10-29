#include "CaesarCipher.h"
using namespace std;

string encryptText(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') { 
            c = c - 'A';
            c = (c + shift) % 26;
            c = c + 'A';
            text[i] = c;
        } else if (c >= 'a' && c <= 'z') {
            c = c - 'a';
            c = (c + shift) % 26;
            c = c + 'a';
            text[i] = c;
        }
        // obs: any non alphabetic chars doesnt change :)
    }
    return text;
}

string decryptText(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') { 
            c = c - 'A';
            c = (c - shift + 26) % 26;
            c = c + 'A';
            text[i] = c;
        } else if (c >= 'a' && c <= 'z') { 
            c = c - 'a';
            c = (c - shift + 26) % 26;
            c = c + 'a';
            text[i] = c;
        }
        // non alphabetic remain unchanged here as well ;)
    }
    return text;
}