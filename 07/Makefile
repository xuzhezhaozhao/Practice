CC = gcc
CFLAGS = -Wall -g -c

all: echoclient echoserveri

echoclient: echoclient.o csapp.o
	$(CC) -o echoclient echoclient.o csapp.o

echoserveri: echoserveri.o csapp.o echo.o
	$(CC) -o echoserveri echoserveri.o csapp.o echo.o

echoclient.o: echoclient.c
	$(CC) $(CFLAGS) echoclient.c

echoserveri.o: echoserveri.c
	$(CC) $(CFLAGS) echoserveri.c

echo.o: echo.c
	$(CC) $(CFLAGS) echo.c

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) csapp.c

clean:
	rm -rf *.o *~ *.swp echoclient echoserveri

.PHONY: all clean
