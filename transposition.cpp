#include<bits/stdc++.h>
using namespace std;

string encrypt(string text, int width) {
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

string decrypt(string text, int width) {
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
    freopen("transposition.txt", "r", stdin);
    string text;
    getline(cin, text);
    cout << "Plain Text : " << text << endl;

    int width = 10;

    string CipherText = encrypt(text, width);
    cout << "Cipher Text : " << CipherText << endl;

    string CipherText1 = encrypt(CipherText, width);
    cout << "Double Cipher Text : " << CipherText1 << endl;

    string Original = decrypt(CipherText, width);
    cout << "Original Text : " << Original << endl;
}