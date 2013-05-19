CC = gcc
CFLAGS = -Wall -c 
OBJ = mmapcopy.o

all: mmapcopy

mmapcopy: mmapcopy.o
	$(CC) $(OBJ) -o mmapcopy 

mmapcopy.o: mmapcopy.c
	$(CC) $(CFLAGS) mmapcopy.c 

clean:
	rm -rf *o *~ mmapcopy
