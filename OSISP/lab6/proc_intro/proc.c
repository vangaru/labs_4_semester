#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

void handler(int num) {
  write(STDOUT_FILENO, "I won't die\n", 13);
}

int main() {
  signal(SIGINT, handler);
  while(1) {
    printf("Waisting your cycles %d\n", getpid());
    sleep(1);
  }


  return 0;
}
