/*
Student Name: Connor Sparkman
Student NetID: cps260
Complier Used: Linux GCC
Program Description: transfers string data entered in the producer to the consumer using a FIFO
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define size 1024

int main(int argc, char *argv[])
{
  // declare my variables
  int fd;
  char * myfifo = "/tmp/myfifo";
  char text[size];
  fd = open(myfifo, O_RDONLY); // open the fifo and read the input given to it
  read(fd,text,size);
  printf("consumer: %s", text);
  close(fd);
  return 0;
}
