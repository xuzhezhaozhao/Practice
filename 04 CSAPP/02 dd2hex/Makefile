CC = gcc
CFLAGS = -Wall -g -c

.PHONY: all clean

all: hex2dd dd2hex

hex2dd: hex2dd.o
	$(CC) -o hex2dd hex2dd.o

dd2hex: dd2hex.o
	$(CC) -o dd2hex dd2hex.o

hex2dd.o: hex2dd.c
	$(CC) $(CFLAGS) hex2dd.c

dd2hex.o: dd2hex.c
	$(CC) $(CFLAGS) dd2hex.c

clean:
	rm -rf *.o *~ hex2dd dd2hex
