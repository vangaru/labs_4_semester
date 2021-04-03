#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {

  int fd = open("./text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  struct stat sb;

  if(fstat(fd, &sb) == -1) {
    perror("couldnt get file info");
  }
  printf("file size is %ld\n", sb.st_size);

  char* file_in_memory = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  for(int i = 0; i < sb.st_size; i++) {
    file_in_memory[i] = toupper(file_in_memory[i]);
    printf("%c", file_in_memory[i]);
  }

  return 0;
}
