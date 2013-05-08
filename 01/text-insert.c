#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *pf;
	char *filename = "test.txt";
	int c;
	int count = 0;
	pf = fopen(filename, "r+");
	if (pf == NULL) {
		printf("Open file \"%s\" error\n", filename);
		exit(0);
	}
	count = 0;
	if (0 != fseek(pf, 0, 0)) {
		printf("fseek error");
		exit(0);
	}
	while ((c = fgetc(pf)) != EOF) {
		if ('\n' == c) {
			++count;
		}
		if (3 == count) {
			if (EOF == ungetc(c, pf)) {
				exit(0);
			}
			fprintf(pf, "insert to third line end");
			break;
		}
	}
	fclose(pf);
	return 0;
}
