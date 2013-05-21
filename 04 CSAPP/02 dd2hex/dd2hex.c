#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct in_addr addr;
	uint32_t hex;

	if (2 != argc) {
		printf("Usage: %s <dootted-decimal>\n", argv[0]);
		exit(-1);
	}

	
	if (inet_aton(argv[1], &addr) == 0) {
		fprintf(stderr, "inet_aton error\n");
		exit(-1);
	}
	hex = ntohl(addr.s_addr);
	printf("ox%x\n", hex);
	
	return 0;
}
