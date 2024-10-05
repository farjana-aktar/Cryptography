#include <bits/stdc++.h>
using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

long long stringIntoLongLong(string str) {
    long long result = 0;
    for(int i=0; i<str.length(); i++) {
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

void splitMessageIntoBlocks(string message, long long blocks[], int block_size, int &block_count) {
    block_count = 0;

    for(int i=0; i<message.length(); i++) {
        string block = message.substr(i, block_size);
        blocks[block_count++] = stringIntoLongLong(block);
    }
}

int main()
{
    long long p = 47;
    long long q = 71;
    long long n = p * q;
    long long phi = (p-1) * (q-1);
    long long e = 79;
    long long d = 1019;

    string message = "6882326879666683";

    int block_size = to_string(n).length() - 1;
    cout << "Block size : " << block_size << " digits" << endl;

    long long messageBlock[100];
    int block_count = 0;
    splitMessageIntoBlocks(message, messageBlock, block_size, block_count);

    cout << "Original Message Blocks : ";
    for(int i=0; i< block_count; i++) {
        cout << messageBlock[i] << " ";
    }

    cout << endl;

    long long encryptedBlocks[100];
    for(int i=0; i<block_count; i++) {
        encryptedBlocks[i] = modExp(messageBlock[i], e, n);
    }

    cout << "Encrypted Message Blocks : ";
    for(int i=0; i<block_count; i++) {
        cout << encryptedBlocks[i] << " ";
    }
    cout << endl;

    long long decryptedBlock[100];
    for(int i=0; i<block_count; i++) {
        decryptedBlock[i] = modExp(encryptedBlocks[i], d, n);
    }

    cout << "Decrypted Message Blocks : ";
    for(int i=0; i<block_count; i++) {
        cout << decryptedBlock[i] << " ";
    }
    cout << endl;
}
