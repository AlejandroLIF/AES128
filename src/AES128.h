#include "AES128.c"

#define BLOCK_SIZE 16
#define WORD_SIZE 4

int main(const int argc, char*[] argv);
void encryptFile(char* fileName, char* key);
void encryptBlock(const unsigned char* block, const unsigned char* expandedKey);
void decryptFile(char* fileName, char* key);
void decryptBlock(const unsigned char* block, const unsigned char* expandedKey);
void parseKey(char* key, char* keyArray);
