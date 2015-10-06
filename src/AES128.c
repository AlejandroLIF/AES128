#include <stdio.h>
#include <stdlib.h>

#include "AES128.h"

#include "addRoundKey.h"
#include "subBytes.h"
#include "shiftRows.h"
#include "mixColumns.h"
#include "keyExpansion.h"

int main(const int argc, char* argv[]){
    if(argc != 3){
        IO_ERR: printf("Usage: %s [-encrypt|-decrypt] [file] [16-byte HEX Key]\r\n", argv[0]);
        printf("Example: %s -encrypt myFile.txt 00112233445566778899AABBCCDDEEFF\r\n", argv[0]);
        return -1;
    }
    else{
        if(strcmp(argv[1], "-encrypt") == 0){
            encryptFile(argv[2], argv[3]);
        }
        else if(strcmp(argv[1], "-decrypt") == 0){
            decryptFile(argv[2], argv[3]);
        }
        else{
            goto IO_ERR;
        }
    }
    return 0;
}

void encryptFile(char* fileName, char* key){
    unsigned char keyArray[176]; //keyArray should hold enough memory for the expanded key
    unsigned char data[BLOCK_SIZE];
    unsigned char bytesRead;
    parseKey(key, keyArray);
    expand(&keyArray[0]);
    
    FILE *ifp = fopen(fileName, "r");
    if(ifp = NULL){
        printf("ERROR: invalid input file\r\n");
        exit(-1);//Cannot continue
    }
    
    FILE *ofp = fopen("AES128_encrypted_output.txt", "w");
    if(ifp = NULL){
        printf("ERROR: unable to write output to AES128_encrypted_output.txt\r\n");
        fclose(ifp);
        exit(-1);//Cannot continue
    }
    
    do{
        memset(&data[0], 0, BLOCK_SIZE); //Make sure "data" holds all zeroes.
        bytesRead = fread(&data[0], 1, BLOCK_SIZE, ifp);
        encryptBlock(&data[0], &keyArray[0]);
        fwrite(&data[0], 1, BLOCK_SIZE, ofp);
    }while(bytesRead == BLOCK_SIZE); //Read until EOF
    
    fclose(ifp);
    fclose(ofp);
}

void encryptBlock(const unsigned char* block, const unsigned char* expandedKey){
    int keyIndex = 0;
    int i;
    
    addRoundKey(block, &expandedKey[(keyIndex++) * BLOCK_SIZE]; //Add round key and increase the key index.

    for(i = 0; i<9; i++){
        subBytes(block, BLOCK_SIZE);
        shiftRows(block);
        mixColumns(block);
        addRoundKey(block, &expandedKey[(keyIndex++) * BLOCK_SIZE];
    }

    subBytes(block, BLOCK_SIZE);
    shiftRows(block);
    addRoundKey(block, &expandedKey[(keyIndex++) * BLOCK_SIZE];
}

void decryptFile(char* fileName, char* key){
    unsigned char keyArray[176];
    unsigned char data[BLOCK_SIZE];
    unsigned char bytesRead;
    parseKey(key, keyArray);
    
    FILE *ifp = fopen(fileName, "r");
    if(ifp = NULL){
        printf("ERROR: invalid input file\r\n");
        exit(-1);//Cannot continue
    }
    
    FILE *ofp = fopen("AES128_decrypted_output.txt", "w");
    if(ifp = NULL){
        printf("ERROR: unable to write output to AES128_decrypted_output.txt\r\n");
        fclose(ifp);
        exit(-1);//Cannot continue
    }
    
    do{
        memset(&data[0], 0, BLOCK_SIZE); //Make sure "data" holds all zeroes.
        bytesRead = fread(&data[0], 1, BLOCK_SIZE, ifp);
        decryptBlock(&data[0], &keyArray[0]);
        fwrite(&data[0], 1, BLOCK_SIZE, ofp);
    }while(bytesRead == BLOCK_SIZE); //Read until EOF
    
    fclose(ifp);
    fclose(ofp);
}

void decryptBlock(const unsigned char* block, const unsigned char* expandedKey){
    int keyIndex = 10;
    int i;
    
    addRoundKey(block, &expandedKey[(keyIndex--) * BLOCK_SIZE]; //Add round key and reduce the key index
    
    for(i = 0; i < 9; i++){
        invShiftRows(block);
        invsubBytes(block, BLOCK_SIZE);
        addRoundKey(block, &expandedKey[(keyIndex--) * BLOCK_SIZE];
        invMixColumn(block);
    }
    
    invShiftRows(block);
    invSubBytes(block);
    addRoundKey(block, &expandedKey[(keyIndex--) * BLOCK_SIZE];
}

/*
    Parse the key from its string representation to a byte array.
*/
void parseKey(char* key, char* keyArray){
    char* temp = key;
    int i = 0;
    //Find the null terminator
    while(*(temp++)){
        i++;
    }
    
    if(i != 32){ //If the key isn't composed of 32 characters
        printf("ERROR: Invalid key\r\n");
        exit(-1); //Cannot continue
    }
    
    //Go through each byte
    for(i = 15; i >= 0; i--){
        //Cycle back two characters
        temp -= 2;
        keyArray[i] = (unsigned char) strtol(temp, &key, 16);
        //Make the two parsed characters zero.
        *(--key) = 0;
        *(--key) = 0;
    }
}
