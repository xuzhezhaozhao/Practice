#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	uint32_t hex;
	struct in_addr addr;
	char *p;
	if (2 != argv) {
		printf("Usage: ./hex2dd <hex>\n");
		exit(-1);
	}

	sscanf(argc[1], "%x", &hex);
	addr.s_addr = htonl(hex);
	p = inet_ntoa(addr);
	printf("%s\n", p);
	
	return 0;
}
