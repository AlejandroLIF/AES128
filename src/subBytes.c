#include "subBytes.h"
#include "AES128.h"

void subBytes(const unsigned char* block, const unsigned int len){
    int i;
    unsigned char* ptr = block;
    for(i = 0; i < len; i++){
        *ptr = s[*(ptr++)];
    }
}

void invSubBytes(const unsigned char* block, const unsigned int len){
    int i;
    unsigned char* ptr = block;
    for(i = 0; i < len; i++){
        *ptr = inv_s[*(ptr++)];
    }
}
