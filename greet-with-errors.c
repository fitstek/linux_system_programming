#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int fd;
	fd = open("foo", O_WRONLY | O_CREAT, 0644);

	if (fd < 0) {
		printf("error number %d\n", errno);
		perror("Error type");
		exit(1);
	}
	write(fd, "Hello World", 11);
	close(fd);
}
