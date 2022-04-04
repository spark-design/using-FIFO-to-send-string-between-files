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

int main(int argc, char *argv[])
{
  // declare my variables
  char input[1054];
  printf("Please enter text at the producer: prompt\n");
  printf("producer: ");
  scanf("%s", input);
  int fd;
  char * myfifo = "/tmp/myfifo";
  mkfifo(myfifo, 0666);
  fd = open(myfifo, O_WRONLY); // open the fifo and write to it the input given
  write(fd,input,sizeof(input)); 
  close(fd);
  return 0;
}
