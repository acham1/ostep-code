#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    printf("Could not create pipe\n");
    exit(EXIT_SUCCESS);
  }
  if (!fork()) {
    // child 1: reader
    printf("Reader in pid: %d\n", getpid());    
    dup2(pipefd[0], STDIN_FILENO);
    char input[8];
    read(STDIN_FILENO, input, 7);
    input[7] = '\0';
    printf("Did Read: %s\n", input);
    exit(EXIT_SUCCESS);
  } else if (!fork()) {
    // child 2: writer
    printf("Writer in pid: %d\n", getpid());
    dup2(pipefd[1], STDOUT_FILENO);
    write(STDOUT_FILENO, "testing", 7);
    exit(EXIT_SUCCESS);
  } else {
    int pid;
    printf("Parent in pid: %d\n", getpid());
    while((pid = wait(NULL)) >= 0) printf("Exited %d\n", pid); 
  }
  return EXIT_SUCCESS;
}
