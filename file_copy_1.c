#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BSIZE 16384

void main()
{
  int fin, fout;
  char buf[BSIZE];
  int count;

  if((fin = open("foo", O_RDONLY)) < 0) {
    perror("Error type: ");
    exit(1);
  }

  if((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0) {
    perror("Error type: ");
    exit(2);
  }

  while ((count = read(fin, buf, BSIZE)) > 0)
    write(fout, buf, count);

  close(fin);
  close(fout);

}
