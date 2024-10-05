#include <bits/stdc++.h>
using namespace std;

string caesarEncrypt(string text, int shift) {
    string str = "";

    for(int i=0; i<text.size(); i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            char ch = (text[i] - 'A' + shift) % 26 + 'A';
            str += ch;
        }

        else if(text[i] >= 'a' && text[i] <= 'z') {
            char ch = (text[i] - 'a' + shift) % 26 + 'a';
            str += ch;
        }

        else {
            str += text[i];
        }
    }

    return str;
}

string caesardencrypt(string text, int shift) {
    string str = "";

    for(int i=0; i<text.size(); i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            char ch = (text[i] - 'A' - shift) % 26 + 'A';
            str += ch;
        }

        else if(text[i] >= 'a' && text[i] <= 'z') {
            char ch = (text[i] - 'a' - shift) % 26 + 'a';
            str += ch;
        }

        else {
            str += text[i];
        }
    }

    return str;
}

string encrypt_tran(string text, int width) {
    string result = "";
    int col=0, i=0;

    while(col < width) {
        result += text[i];
        i += width;

        if(i >= text.size()) {
            i = ++col;
        }
    }
    return result;
}

string decrypt_trans(string text, int width) {
    string result = text;
    int j=0, col=0;

    for(int i=0; i<text.size(); i++) {
        result[j] = text[i];
        j += width;

        if(j >= text.length()) {
            j = ++col;
        }
    }
    return result;
}

int main()
{
    freopen("caser_tran.txt", "r", stdin);
    string text;
    getline(cin, text);
    // cin.clear();
    cout << "Plain text : " << text << endl;

    int shift = 3;

    string caesar_cipher = caesarEncrypt(text, shift);
    cout << "Caesar Cipher : " << caesar_cipher << endl;

    int width = 5;
    string tran_cipher = encrypt_tran(caesar_cipher, width);
    cout << "Transposition Cipher : " << tran_cipher << endl;

    string tran_decipher = decrypt_trans(tran_cipher, width);
    cout << "Transposition DeCipher : " << tran_decipher << endl;

    string caesar_decipher = caesardencrypt(tran_decipher, shift);
    cout << "Caesar deCipher(Original Plain Text) : " << caesar_decipher << endl;
}