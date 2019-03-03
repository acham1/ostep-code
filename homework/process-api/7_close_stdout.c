#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
  if (!fork()) {
    close(STDOUT_FILENO);
    printf("Attempt printf to stdout\n");
  } else {
    int status;
    pid_t pid = wait(&status);
    printf("Child pid %d exited normally? %d\n", pid, WIFEXITED(status));
  }
  return EXIT_SUCCESS;
}
