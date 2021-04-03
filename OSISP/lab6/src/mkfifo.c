#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define NAMEDPIPE_NAME "/tmp/my_named_pipe"
#define BUFSIZE        50

int main(int argc, char **argv) {
  int fd;
  size_t len;
  char buf[BUFSIZE];

  if( mkfifo(NAMEDPIPE_NAME, 0777) == -1) {
    perror("mkfifo");
    return 1;
  }
  printf("%s is created\n", NAMEDPIPE_NAME);

  if( (fd = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0 ) {
    perror("open");
  }
  printf("%s is opened\n", NAMEDPIPE_NAME);

  do {
    memset(buf, '\0', BUFSIZE);
    if( (len = read(fd, buf, BUFSIZE-1)) <= 0 ) {
      perror("read");
      close(fd);
      remove(NAMEDPIPE_NAME);
      return 0;
    }
    printf("Incomming message (%d) : %s\n", len, buf);
  } while(1);

  return 0;

}
