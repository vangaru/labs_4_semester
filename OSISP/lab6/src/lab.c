#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mqueue.h>
#include <signal.h>

#define MAX_SSIZE 100
#define SCOUNT 3
#define MAX_MSG_IN_QUEUE 10
#define MAX_MSG_SIZE 1024
#define MQNAME "/msg"

void handl_sigusr1() {
  printf("SIGUSR1 HANDLER\n");
}

int main() {
  char ss[SCOUNT][MAX_SSIZE];

  printf("Enter first string: ");
  fgets(ss[0], MAX_SSIZE, stdin);
  printf("Enter second string: ");
  fgets(ss[1], MAX_SSIZE, stdin);
  printf("Enter third string: ");
  fgets(ss[2], MAX_SSIZE, stdin);

  int pid = fork();
  if(pid == -1) {
    return 1;
  }

  if(pid == 0) {
    // Child process
    sleep(1);
    kill(getppid(), SIGUSR1);
    mqd_t rcv_hndl = mq_open(MQNAME, O_RDWR);
    if(rcv_hndl < 0) {
      printf("Error %d (%s) mq_open for receive\n");
      exit(-1);
    }
    printf("\nReceiving messages\n");
    printf("Opened mqd_t of %d \n", rcv_hndl);
    printf("Receiving mqd_t of %d \n\n", rcv_hndl);

    char buf[MAX_MSG_SIZE];
    for(int i = 0; i < SCOUNT; i++) {
      int rec_res = mq_receive(rcv_hndl, buf, sizeof(buf), NULL);
      if(rec_res < 0) {
        printf("Error %d (%s) mq_receive", errno, strerror(errno));
        exit(-1);
      }
      printf("Received: %s \n", buf);
    }
  } else {
    // Parent process
    struct mq_attr mq;
    mq.mq_maxmsg = MAX_MSG_IN_QUEUE;
    mq.mq_msgsize = MAX_MSG_SIZE;
    printf("Open message queue\n");
    mqd_t snd_hndl = mq_open(MQNAME, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &mq);
    if(snd_hndl < 0) {
      printf("Error %d (%s) mq_open for send\n", errno, strerror(errno));
      exit(-1);
    }
    printf("Opened mqd_t of %d\n", snd_hndl);
    for(int i = 0; i < SCOUNT; i++) {
      int snd_res = mq_send(snd_hndl, ss[i], sizeof(ss[i]), 1);
      if(snd_res < 0) {
        printf("Error %d (%s) mq_send\n", errno, strerror(errno));
        exit(-1);
      }
      printf("Send mqd_t of %d\n", snd_hndl);
    }
    struct sigaction sa = { 0 };
    sa.sa_handler = &handl_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);

    wait(NULL);
  }


  return 0;
}
