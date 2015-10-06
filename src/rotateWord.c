#include "rotateWord.h"

/*
    Performs a left-rotation on a 4-byte word.
*/
void rotateWord(const unsigned char* word){
    unsigned char temp;
    temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}
