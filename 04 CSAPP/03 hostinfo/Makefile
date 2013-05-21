CC = gcc
CFLAGS = -Wall -c

hostinfo: hostinfo.o csapp.o
	$(CC) -o hostinfo hostinfo.o csapp.o

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) csapp.c 
	
hostinfo.o: hostinfo.c 
	$(CC) $(CFLAGS) hostinfo.c


.PHONY: clean

clean:
	rm -rf *.o *~ *.swp hostinfo

