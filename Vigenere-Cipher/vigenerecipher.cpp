/*
Rafi Alauddin
140810200056
*/

#include <iostream>
#include <windows.h>
using namespace std;
#define ma_mod(a,n) ((a%n)+n)%n


int main() {
    string key;
    string plainText;
    string extendedKey;
    string encryptedText;
    string decryptedText;
    int loopKey = 0;

    cout << "Key : ";
    cin >> key;
    cout << "Plain Text : ";
    cin >> plainText;

    for(int i=0; i<plainText.size(); i++) {
        if(loopKey % key.size() == 0) {
            loopKey = 0;
        } 
        extendedKey += key[loopKey];
        loopKey++;
        
    }

    cout << "Extended Key : " << extendedKey;

    // Encryption
    for(int i=0; i<plainText.size(); i++) {
        int indexEncrypted;

        indexEncrypted = (((int)plainText[i] + (int)extendedKey[i]) % 97) % 26;
        encryptedText += (char)indexEncrypted + 97;
        
    }
    cout << "\nCipher Text : " << encryptedText;
    int coba;
    // Decryption
     for(int i=0; i<encryptedText.size(); i++) {
        int indexDecrypted;
        
        indexDecrypted = ma_mod((int)encryptedText[i] - (int)extendedKey[i], 26);
        decryptedText += (char)indexDecrypted + 97;
        coba = ((int)encryptedText[1] - (int)extendedKey[1]) % 26;
    }
    cout << "\nDecrypted Text : " << decryptedText;


}