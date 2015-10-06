#include "addRoundKey.h"
#include "AES128.h"

void addRoundKey(const unsigned char* block, const unsigned char* key){
    unsigned char* a;
    unsigned char* b;
    int i;
    for(i = 0; i < BLOCK_SIZE; i++){
        *a = *(a++)^*(b++);
    }
}
