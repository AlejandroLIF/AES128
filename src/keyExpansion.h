#include "keyExpansion.c"



void expand(unsigned char* cipherKey);

/*
    Round Constants
    https://en.wikipedia.org/wiki/Rijndael_key_schedule#Rcon
*/
const unsigned char rCon[] = {0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
