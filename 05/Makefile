CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: hex2dd dd2hex

hex2dd: hex2dd.o
	$(CC) $(CFLAGS) -o hex2dd hex2dd.o

dd2hex: dd2hex.o
	$(CC) $(CFLAGS) -o dd2hex dd2hex.o

hex2dd.o: hex2dd.c
	$(CC) -c hex2dd.c

dd2hex.o: dd2hex.c
	$(CC) -c dd2hex.c

clean:
	rm -rf *.o *~ hex2dd dd2hex
