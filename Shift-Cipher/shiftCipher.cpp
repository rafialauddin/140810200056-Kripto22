/*
    SHIFT CIPHER

    Rafi Alauddin
    140810200056
*/


#include <iostream>
#include<windows.h>
using namespace std;

string encrypt(string text, int key) {
    string encrypted;

    for(int i=0; i< text.length(); i++) {
        int indexEncrypted;

        if((int)text[i] == 32) {
            indexEncrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  //(huruf kecil)
            indexEncrypted = (int)text[i] + key;
            if(indexEncrypted > 122) {
                indexEncrypted -= 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  //(huruf kapital)
            indexEncrypted = (int)text[i] + key;
            if(indexEncrypted > 90) {
                indexEncrypted -= 26;
            }
        }

        

        encrypted += (char)indexEncrypted;
    }

    return encrypted;
}

string decrypt(string text, int key) {
    string decrypted;

    for(int i=0; i< text.length(); i++) {
        int indexdecrypted;

        if((int)text[i] == 32) {
            indexdecrypted = (int)text[i];
        }else if((int)text[i] >= 97 && (int)text[i] <= 122) {  //(huruf kecil)
            indexdecrypted = (int)text[i] - key;
            if(indexdecrypted < 97) {
                indexdecrypted += 26;
            }
        }else if((int)text[i] >= 65 && (int)text[i] <= 90) {  //(huruf kapital)
            indexdecrypted = (int)text[i] - key;
            if(indexdecrypted < 65) {
                indexdecrypted += 26;
            }
        }


        decrypted += (char)indexdecrypted;
    }

    return decrypted;
}

int main() {
    string text;
    int key;

    cout << "\nMasukkan text : ";
    getline(cin, text);

    cout << "\nMasukkan kunci : ";
    cin >> key;

    cout << "\n>> Encrypted Text : ";
    cout << encrypt(text, key) << endl;

    cout << ">> Decrypted Text : ";
    cout << decrypt(encrypt(text, key), key) << endl;

}
