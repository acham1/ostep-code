#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINES 1000000

int main(int argc, char* argv[]) {
  int fd = open("2_open_fork.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  pid_t postpid = fork();
  if (postpid == 0) {
    for (int i = 0; i < MAX_LINES; i++) {
      write(fd, "parent\n", 7);
    }
  } else {
    for (int i = 0; i < MAX_LINES; i++) {
      write(fd, "child\n", 6);
    }
  }
  return EXIT_SUCCESS;
}
