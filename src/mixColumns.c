#include "mixColumns.h"

void mixColumns(const unsigned char* block){
    int i;
    unsigned char* temp = block;
    for(i = 0; i < WORD_SIZE; i++){
        mixColumn(temp);
        temp += WORD_SIZE;
    }
}

/*
    This function is deliberately private.
*/
void mixColumn(const unsigned char* column) {
    int i;
    unsigned char t[WORD_SIZE];
    for(i = 0; i < len(t); i++){
        t[i] = column[i];
    }
    
    column[0] = x2[t[0]] + x3[t[1]] +    t[2]  +    t[3];
    column[1] =    t[0]  + x2[t[1]] + x3[t[2]] +    t[3];
    column[2] =    t[0]  +    t[1]  + x2[t[2]] + x3[t[3]];
    column[3] = x3[t[0]] +    t[1]  +    t[2]  + x2[t[3]];
}

void invMixColumns(const unsigned char* block){
    int i;
    unsigned char* temp = block;
    for(i = 0; i < WORD_SIZE; i++){
        invMixColumn(temp);
        temp += WORD_SIZE;
    }
}

/*
    This function is deliberately private.
*/
void invMixColumn(const unsigned char* column){
    int i;
    unsigned char t[WORD_SIZE];
    for(i = 0; i<len(t); i++){
        t[i] = column[i];
    }
    
    column[0] = x14[t[0]] + x11[t[1]] + x13[t[2]] +  x9[t[3]];
    column[1] =  x9[t[0]] + x14[t[1]] + x11[t[2]] + x13[t[3]];
    column[2] = x13[t[0]] +  x9[t[1]] + x14[t[2]] + x11[t[3]];
    column[3] = x11[t[0]] + x13[t[1]] +  x9[t[2]] + x14[t[3]];
}
