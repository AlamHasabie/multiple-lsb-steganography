#ifndef _VIGENERE_H_
#define _VIGENERE_H_


#include <string>

void encryptAsciiVigenere(const std::string& plaintext, std::string& ciphertext, const std::string& key);
void decryptAsciiVigenere(const std::string& ciphertext, std::string& plaintext, const std::string& key);


#endif
