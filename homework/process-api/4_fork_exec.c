#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>

// l := list arguments variadically
void tryexecl(char* cwd) {
  if (fork()) {
    printf("Trying execl\n");
    execl("/bin/ls", cwd, NULL);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

// l ...
// p := search in environment PATH
void tryexeclp(char* cwd) {
  if (fork()) {
    printf("Trying execlp\n");
    execlp("ls", cwd, NULL);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

// l ...
// e := give environment as array of K=V strings
void tryexecle(char* cwd) {
  if (fork()) {
    printf("Trying execle\n");
    execle("/bin/ls", cwd, NULL, (char(*)[]) {NULL});
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

// v := arguments as array of strings
void tryexecv(char* cwd) {
  if (fork()) {
    char* args[] = {cwd, NULL};
    printf("Trying execv\n");
    execv("/bin/ls", args);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

// v ...
// p ...
void tryexecvp(char* cwd) {
  if (fork()) {
    char* args[] = {cwd, NULL};
    printf("Trying execvp\n");
    execvp("ls", args);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

// v ...
// p ...
// e ...
void tryexecvpe(char* cwd) {
  if (fork()) {
    char* args[] = {cwd, NULL};
    printf("Trying execvpe\n");
    execvpe("ls", args, (char* const*) {NULL});
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

int main(int argc, char* argv[]) {
  int status;
  pid_t wpid;
  char cwd[PATH_MAX];
  getcwd(cwd, sizeof(cwd));
  
  tryexecl(cwd);
  tryexeclp(cwd);
  tryexecle(cwd);
  tryexecv(cwd);
  tryexecvp(cwd);
  tryexecvpe(cwd);
  return EXIT_SUCCESS;
}
