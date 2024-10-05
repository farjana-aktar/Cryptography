#include <bits/stdc++.h>
using namespace std;

string encryp(string str, string key) {
    string cipher = "";

    for(int i=0;i<str.length();i++) {
        char ch = str[i];

        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + (key[i] - 'A') + 26) % 26 + 'A';
        }

        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + (key[i] - 'a') + 26) % 26 + 'a';
        }

        cipher += ch;
    }

    return cipher;
}

string decryp(string str, string key) {
    string decipher = "";

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - (key[i] - 'A') + 26) % 26 + 'A';
        }

        else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - (key[i] - 'a') + 26) % 26 + 'a';
        }

        decipher += ch;
    }

    return decipher;
}

int main()
{
    freopen("oneTime.txt", "r", stdin);
    string key;
    getline(cin, key);

    string text = "ABCDE";
    cout << "Plain Text : " << text << endl;

    string CipherText = encryp(text, key);
    cout << "Cipher Text : " << CipherText << endl;

    string DecipherText = decryp(CipherText, key);
    cout << "Original Text : " << DecipherText << endl;
}