#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int x = 100;
  printf("Assigning variable 'x' the value: %d\n", x);
  pid_t parentpid = getpid();
  printf("Forking parent process with PID: %d\n", parentpid);
  pid_t postpid = fork();
  if (postpid == 0) {
    printf("Parent process (%d) reads from variable 'x' with value: %d\n", parentpid, x);
    int nextx = 101;
    printf("Parent process(%d) writes to variable 'x' with value: %d\n", parentpid, nextx);
    x = nextx;
    printf("Parent process(%d) reads from variable 'x' with value: %d\n", parentpid, x);
  } else {
    printf("Child process (%d) reads from variable 'x' with value: %d\n", postpid, x);
    int nextx = 102;
    printf("Child process (%d) writes to variable 'x' with value: %d\n", postpid, nextx);
    x = nextx;
    printf("Child process (%d) reads from variable 'x' with value: %d\n", postpid, x);
  }
  return EXIT_SUCCESS;
}
