#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int shift) {
    string str = "";

    for(int i=0; i<text.size();i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            char ch = (text[i] + shift - 'A') % 26 + 'A';
            str += ch;
        }

        else if(text[i] >= 'a' && text[i] <= 'z') {
            char ch = (text[i] + shift - 'a') % 26 + 'a';
            str += ch;
        }

        else {
            str += text[i];
        }
    }

    return str;
}

string decrypt(string text, int shift) {
    string str = "";

    for(int i=0; i<text.size(); i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            char ch = (text[i] - shift - 'A') % 26 + 'A';
            str += ch;
        }

        else if(text[i] >= 'a' && text[i] <= 'z') {
            char ch = (text[i] - shift - 'a') % 26 + 'a';
            str += ch;
        }

        else {
            str += text[i];
        }
    }

    return str;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string text;
    getline(cin, text);

    int shift;
    cin >> shift;
    shift = shift % 26;

    cout << "Plain Text : " << text << endl;

    string cipher = encrypt(text, shift);
    cout << "Encrypted Cipher : " << cipher << endl;

    string original = decrypt(cipher, shift);
    cout << "Decrypted Cipher : " << original << endl;

}