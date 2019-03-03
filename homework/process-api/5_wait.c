#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int status, pid = fork();
  int res = wait(&status);

  if (pid) {
    printf("Parent's res, WIFEXITED(status): %d, %d\n", res, WIFEXITED(status));
  } else {
    printf("Child's res, WIFEXITED(status): %d, %d\n", res, WIFEXITED(status));
  }
  return EXIT_SUCCESS;
}
