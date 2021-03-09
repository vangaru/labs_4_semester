#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* s) {
    int end = strlen(s) - 1;
    int iters = ( (strlen(s) - 2) / 2) + 1;
    char t;
    for(int i = 1; i < iters; i++) {
	t = s[i];
	s[i] = s[end - i];
	s[end - i] = t;
    }
    printf("%s\n", s);
}

int main() {

    int fd;
    size_t sz;
    char *c = (char *)malloc(200);

    fd = open("text.txt", O_RDONLY);
    if(fd < 0) {
	perror("r1");
	exit(1);
    }

    sz = read(0, c, 150);
    printf("file descriptor - %d\n%d bytes were read\n", fd, sz);

    c[sz] = '\0';

    char* token = strtok(c, "\n");
    while(token != NULL) {
	printf("%s - %d\n", token, strlen(token));
	swap(token);
	token = strtok(NULL, "\n");
    }


    free(c);
    free(token);
    return 0;
}


