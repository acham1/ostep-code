#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

void tryexecl(char* cwd) {
  if (fork()) {
    printf("Trying execl\n");
    execl("/bin/ls", cwd, NULL);
  }
}

void tryexeclp() {
}

void tryexecle() {
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
  tryexecle();
  tryexecv();
  tryexecvp();
  tryexecvpe();
  return EXIT_SUCCESS;
}
