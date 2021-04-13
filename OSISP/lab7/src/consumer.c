#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

#define PRODUCER_MUTEX_NAME "producer_mutex"
#define CONSUMER_MUTEX_NAME "consumer_mutex"
#define FIBONACCI_SEMAPHORE_NAME "fibonacci_semaphore"
#define BARRIER 17000

void quit() {
    printf("Consumer %d Unlinking mutex\n", getpid());
    if(sem_unlink(PRODUCER_MUTEX_NAME) == -1){
        perror("Consumer: sem_unlink(producer_mutex)");
        exit(1);
    }
    printf("Consumer %d Unlinking consumer mutex\n", getpid());
    if(sem_unlink(CONSUMER_MUTEX_NAME) == -1) {
        perror("Consumer: sem_unlink(consumer_mutex)");
        exit(1);
    }
    printf("Consumer %d Unlinking fibonacci_semaphore\n", getpid());
    if(sem_unlink(FIBONACCI_SEMAPHORE_NAME) == -1) {
        perror("Consumer: sem_unlink(fib_sem)");
        exit(1);
    }
    exit(0);
}

int main() {
    signal(SIGINT, quit);
    sem_t *producer_mutex = sem_open(PRODUCER_MUTEX_NAME, O_RDWR);
    if(producer_mutex == SEM_FAILED) {
        perror("Consumer: sem_open(producer_mutex)");
        exit(1);
    }
    sem_t *consumer_mutex = sem_open(CONSUMER_MUTEX_NAME, O_RDWR);
    if(consumer_mutex == SEM_FAILED) {
        perror("Consumer: sem_open(consumer_mutex)");
        exit(1);
    }
    sem_t *fib_sem = sem_open(FIBONACCI_SEMAPHORE_NAME, O_RDWR);
    if(fib_sem == SEM_FAILED) {
        perror("Consumer: sem_open(fib_sem)");
        exit(1);
    }

    int f1 = 1;
    int f2;
    int fib;

    while(1) {
        if(sem_wait(producer_mutex) == -1) {
            perror("Consumer: sem_wait(producer_mutex)");
            exit(1);
        }
        if(sem_getvalue(fib_sem, &f2) == -1) {
            perror("Consumer: sem_getvalue(fib_sem, f2)");
            exit(1);
        }
        fib = f1 + f2;
        f1 = fib;
        printf("Consumer %d Fibonacci %d\n", getpid(), fib);
        for(size_t i = f2; i < fib; i++) {
            if(sem_post(fib_sem) == -1){
                perror("Consumer: sem_post(fib_sem)");
                exit(1);
            }
        }
        if(sem_post(consumer_mutex) == -1) {
            perror("Consumer: sem_post(consumer_mutex)");
            exit(1);
        }
        if(fib > BARRIER) {
            break;
        }
        sleep(1);
    }

    return 0;
}
