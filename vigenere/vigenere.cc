#include "vigenere.h"


using namespace std;

void encryptAsciiVigenere(const string& plaintext, string& ciphertext, const string& key){

    int ascii_dec;
    ciphertext.clear();
    for (int i=0 ; i < plaintext.length() ; i++){

        ascii_dec = ((int)plaintext[i] + (int) key[i%key.length()])%256;
        ciphertext.push_back((char) ascii_dec);
    }

}
void decryptAsciiVigenere(const string& ciphertext, string& plaintext, const string& key){

    int mod_result;
    plaintext.clear();

    for (int i=0 ; i < ciphertext.length() ; i++){
        mod_result = ((int) ciphertext[i] - (int) key[i%key.length()])%256;
        if (mod_result < 0) mod_result += 256;
        plaintext.push_back((char) mod_result);
    }
}