#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int Open(const char *pathname, int flags, mode_t mode);
ssize_t Write(int fd, const void *buf, size_t count);
void *Mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
void mmapcopy(int fd, int size);

/* mmapcopy driver */
int main(int argc, const char **argv)
{
	struct stat stat;	
	int fd;

	/* Check for required command line argument */
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	/* Copy the input argument to stdout */
	fd = Open(argv[1], O_RDONLY, 0);
	fstat(fd, &stat);
	mmapcopy(fd, stat.st_size);

	return 0;
}

/*
 * uses mmap to copy file fd to stdout
 */
void mmapcopy(int fd, int size)
{
	char *bufp;
	bufp = Mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	Write(1, bufp, size);
	return;
}

/* open wrapper */
int Open(const char *pathname, int flags, mode_t mode)
{
	int fd;
	if ((fd = open(pathname, flags, mode)) == -1) {
		printf("open %s error\n", pathname);
		exit(0);
	}
	return fd;
}

/* writer wrapper */
ssize_t Write(int fd, const void *buf, size_t count)
{
	ssize_t size;
	if ((size = write(fd, buf, count)) == -1) {
		printf("write error\n");
		exit(0);
	}
	return size;
}

/* mmap wrapper */
void *Mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset)
{
	void *vp;
	if ((vp = mmap(start, length, prot, flags, fd, offset)) == MAP_FAILED) {
		printf("mmap error\n");
		exit(0);
	}
	return vp;
}
