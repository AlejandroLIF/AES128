#include "keyExpansion.h"
#include "rotateWord.h"
#include "AES128.h"

/*
    This method was written based on the one provided on http://www.samiam.org/key-schedule.html 

    cipherKey is expected to be a pointer to the first element of a 176-byte array.
*/
void expand(unsigned char* cipherKey){
    unsigned char temp[WORD_SIZE];
    unsigned char i;
    unsigned char expansionRound = 1;
    unsigned char nextByte = 16;
    //While nextByte < 16 bytes per key * 11 keys
    while(nextByte < 176){
        //Copy the previous word to the temporary variable.
        for(i = 0; i < WORD_SIZE; i++){
            temp[i] = cipherKey[nextByte + i - WORD_SIZE];
        }
        
        //Each time a complete key has been generated, mutate the new xoring constant
        if(nextByte % 16 == 0){
            rotateWord(temp);
            subBytes(temp, WORD_SIZE);
            temp[0] ^= rCon[expansionRound++];
        }
        
        for(i = 0; i < WORD_SIZE; i++){
            cipherKey[nextByte] = cipherKey[nextByte - 16] ^ temp[i];
            nextByte++;
        }
    }
    
}
