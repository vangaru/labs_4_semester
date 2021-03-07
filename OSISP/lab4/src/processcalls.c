#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    // Process 1 spawn
    printf("Process 1 spawn PID = %d PPID = %d\n", getpid(), getppid());

    // Process 2 spawn
    if((pid = fork()) == -1) {
	printf("Error!\n");
    } else if(pid == 0) {
	printf("Process 2 spawn PID = %d PPID = %d\n", getpid(), getppid());
	sleep(3);
	// Process 5 spawn
	if((pid = fork()) == -1){
	    printf("Error!\n");
	} else if(pid == 0) {
	    printf("Process 5 spawn PID = %d PPID = %d\n", getpid(), getppid());
	    // Process 6 spawn
	    if((pid = fork()) == -1) {
		printf("Error!\n");
	    } else if(pid == 0) {
		printf("Process 6 spawn PID = %d PPID = %d\n", getpid(), getppid());
		printf("Process 6 dies PID = %d PPID = %d\n", getpid(), getppid());
		exit(0);
	    } else sleep(1);
	    // Process 6 dies
	    // Process 7 spawn
            if((pid = fork()) == -1) {
                printf("Error!\n");
            } else if(pid == 0) {
                printf("Process 7 spawn PID = %d PPID = %d\n", getpid(), getppid());
                printf("Process 7 dies PID = %d PPID = %d\n", getpid(), getppid());
                exit(0);
            } else sleep(1);
            // Process 7 dies
            printf("Process 5 dies PID = %d PPID = %d\n", getpid(), getppid());
	    exit(0);
	} else sleep(3);
	// Process 5 dies
	printf("Process 2 dies PID = %d PPID = %d\n", getpid(), getppid());
	exit(0);
	// Process 5 dies
    } else sleep(1);
    // Process 2 dies

    // Process 3 spawn
    if((pid = fork()) == -1) {
	printf("Error!\n");
    } else if(pid == 0) {
	printf("Process 3 spawn PID = %d PPID = %d\n", getpid(), getppid());
	printf("Process 3 dies PID = %d PPID = %d\n", getpid(), getppid());
	execl("/bin/who", "who -a", NULL);
    } else sleep(1);
    // Process 3 dies

    // Process 4 spawn
    if((pid = fork()) == -1) {
	printf("Error!\n");
    } else if(pid == 0) {
	printf("Process 4 spawn PID = %d PPID = %d\n", getpid(), getppid());
	printf("Process 4 dies PID = %d PPID = %d\n", getpid(), getppid());
	exit(0);
    } else sleep(1);
    // Process 4 dies
    sleep(4);
    printf("Process 1 dies PID = %d PPID = %d\n", getpid(), getppid());
    exit(0);
    // Process 1 dies
    return 1;
}

