#include<bits/stdc++.h>
using namespace std;

map <string, string> encoder;
map <string, string> decoder;

string cipherText(const string &text, int block_size) {
    string cipher = "";

    for(int i=0; i<text.size(); i+=block_size) {
        string block = text.substr(i, block_size);

        if(encoder.find(block) != encoder.end()) {
            cipher += encoder[block];
        }

        else {
            cipher += block;
        }
    }

    return cipher;
}

string decipherText(const string &text, int block_size) {
    string decipher = "";

    for(int i=0; i<text.size(); i+=block_size) {
        string block = text.substr(i, block_size);

        if(decoder.find(block) != decoder.end()) {
            decipher += decoder[block];
        }

        else {
            decipher += block;
        }
    }

    return decipher;
}

int main()
{
    freopen("polygon.txt", "r", stdin);
    string text;
    getline(cin, text);
    cin.clear();
    cout << "Plain Text : " << text << endl;

    freopen("dictionary.txt", "r", stdin);

    string s1, s2;
    while(cin >> s1 >> s2) {
        encoder[s1] = s2;
        decoder[s2] = s1;
    }

    int block_size = 3;

    string cipher = cipherText(text, block_size);
    cout << "Cipher Text : " << cipher << endl;

    string decipher = decipherText(cipher, block_size);
    cout << "Decipher text : " << decipher << endl;
}