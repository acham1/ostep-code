#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>

void tryexecl(char* cwd) {
  if (fork()) {
    printf("Trying execl\n");
    execl("/bin/ls", cwd, NULL);
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

void tryexeclp() {
}

void tryexecle(char* cwd) {
  if (fork()) {
    printf("Trying execle\n");
    execle("/bin/ls", cwd, NULL, (char(*)[]) {NULL});
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
  }
}

void tryexecv() {
}

void tryexecvp() {
}

void tryexecvpe() {
}

int main(int argc, char* argv[]) {
  char cwd[PATH_MAX];
  getcwd(cwd, sizeof(cwd));
  
  tryexecl(cwd);
  tryexeclp();
  tryexecle(cwd);
  tryexecv();
  tryexecvp();
  tryexecvpe();
  return EXIT_SUCCESS;
}
