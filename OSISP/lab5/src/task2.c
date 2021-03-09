#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* swap(char* s) {
    int end = strlen(s) - 1;
    int iters = ( (strlen(s) - 2) / 2) + 1;
    char t;
    for(int i = 1; i < iters; i++) {
	t = s[i];
	s[i] = s[end - i];
	s[end - i] = t;
    }
    return s;
}

int main() {

    size_t sz;
    char *c = (char *)malloc(200);

    sz = read(0, c, 150);

    c[sz] = '\0';

    int fd = open("dict.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    size_t wd;

    if(fd < 0) {
	perror("r1");
	exit(1);
    }

    char* token = strtok(c, "\n");
    while(token != NULL) {
        wd = write(fd, token, strlen(token));
	wd = write(fd, " - ", strlen(" - "));
	char* sw = swap(token);
	wd = write(fd, sw, strlen(sw));
	wd = write(fd, "\n", strlen("\n"));
	token = strtok(NULL, "\n");
    }


    free(c);
    free(token);
    return 0;
}


