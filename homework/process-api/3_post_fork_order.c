#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
  int fd[2], tmp = 0;
  pipe(fd);
  if (fork() == 0) {
    printf("Hello\n");
    write(fd[1], &tmp, sizeof(int));
  } else {
    read(fd[0], &tmp, sizeof(int));
    printf("Goodbye\n");
  }    
  return EXIT_SUCCESS;
}
