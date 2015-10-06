CC=gcc
ARGS=-O

DEPS= addRoundKey AES128 keyExpansion mixColumns rotateWord shiftRows subBytes

/bin/addRoundKey.o : /src/addRoundKey.c
	$(CC) -c -Wall /src/addRoundKey.c
	
/bin/AES128.o : /src/AES128.c
	$(CC) -c -Wall /src/AES128.c
	
/bin/keyExpansion.o : /src/keyExpansion.c
	$(CC) -c -Wall /src/keyExpansion.c
	
/bin/mixColumns.o : /src/mixColumns.c
	$(CC) -c -Wall /src/mixColumns.c
	
/bin/rotateWord.o : /src/rotateWord.c
	$(CC) -c -Wall /src/rotateWord.c
	
/bin/shiftRows.o : /src/shiftRows.c
	$(CC) -c -Wall /src/shiftRows.c
	
/bin/subBytes.o : /src/subBytes.c
	$(CC) -c -Wall /src/subBytes.c
	
all: /bin/$(DEPS).o
	$(CC) $(ARGS) -o AES128.run /bin/$(DEPS).o
