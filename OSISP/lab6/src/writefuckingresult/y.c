#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <mqueue.h>
#include <errno.h>

#define MQNAME    "/fuckingmessages"
#define MQMAXMSG  10
#define MQMSGSIZE 1024
#define SLEN      100
#define SCOUNT    3
#define TRUE      1
#define FALSE     0

void killer() {
  printf("I won't die\n");
}

size_t is_vowel(char c) {
  if(c == 'a' || c == 'A' ||
     c == 'e' || c == 'E' ||
     c == 'i' || c == 'I' ||
     c == 'o' || c == 'O' ||
     c == 'u' || c == 'U' ||
     c == 'y' || c == 'Y') {
       return TRUE;
     }
  return FALSE;
}

int main() {
  char **ss = (char **)malloc(SCOUNT * sizeof(char *));
  for(size_t i = 0; i < SCOUNT; i++) {
    ss[i] = (char *)malloc(SLEN * sizeof(char));
  }

  for(size_t i = 0; i < SCOUNT; i++) {
    printf("Enter %zu string : ", i + 1);
    fgets(ss[i], SLEN, stdin);
  }

  struct sigaction action = { 0 };
  action.sa_handler = killer;
  sigaction(SIGUSR1, &action, NULL);

  int pid = fork();
  if(pid == -1) {
    return 1;
  }
  if(pid == 0) {
    // Child process
    struct mq_attr server_attr;
    server_attr.mq_flags = 0;
    server_attr.mq_maxmsg = MAX_MESSAGES;
    server_attr.mq_msgsize = MAX_MESSAGE_SIZE;
    server_attr.mq_curmsgs = 0;
    char *buf = (char *)malloc((MQMSGSIZE + 1) * sizeof(char));

    char **rec_ss = (char **)malloc(SCOUNT * sizeof(char *));
    for(size_t i = 0; i < SCOUNT; i++) {
      rec_ss[i] = (char *)malloc(MQMSGSIZE * sizeof(char));
    }
    char *res_s = (char *)malloc(MQMSGSIZE * sizeof(char));
    size_t max_vowels = 0;
    size_t tmp = 0;
    mqd_t mq_rec = mq_open(MQNAME, O_CREAT | O_RDONLY, 0644, &attr);
    for(size_t i = 0; i < SCOUNT; i++) {
      ssize_t bytes_read = mq_receive(mq_rec, rec_ss[i], MQMSGSIZE, NULL);
      rec_ss[i][bytes_read] = '\0';
      tmp = 0;
      for(size_t j = 0; j < strlen(rec_ss[i]); j++) {
        if(is_vowel(rec_ss[i][j]) == TRUE) {
          tmp++;
        }
      }
      if(tmp > max_vowels) {
        max_vowels = tmp;
        strcpy(res_s, rec_ss[i]);
      }
      printf("received %s", rec_ss[i]);
    }
    mqd_t mq_snd_res = mq_open(MQNAME, O_WRONLY);
    int snd_res_s = mq_send(mq_snd_res, res_s, MQMSGSIZE, 0);
  } else {
    // Parent process
    //char* buf_snd = (char *)malloc(MQMSGSIZE * sizeof(char));
    struct mq_attr client_attr;
    client_attr.mq_flags = 0;
    client_attr.mq_maxmsg = MAX_MESSAGES;
    client_attr.mq_msgsize = MAX_MESSAGE_SIZE;
    client_attr.mq_curmsgs = 0;

    mqd_t qd_send_to_server, qd_receive_from_server;

    mqd_t mq_snd = mq_open(MQNAME, O_WRONLY);
    for(size_t i = 0; i < SCOUNT; i++) {
      int snd_res = mq_send(mq_snd, ss[i], MQMSGSIZE, 0);
    }
    mqd_t mq_rec_res = mq_open(MQNAME, O_CREAT | O_RDONLY, 0644, &attr);
    char *buf = (char *)malloc((MQMSGSIZE + 1) * sizeof(char));
    ssize_t bytes_read = mq_receive(mq_rec_res, buf, MQMSGSIZE, NULL);
    buf[bytes_read] = '\0';
    printf("result %s", buf);
    //wait(NULL);
    //printf("\n\nFuck you\n\n");
    //wait(NULL);
    //exit(0);
  }
  //sleep(2);
  for(size_t i = 0; i < SCOUNT; i++) {
    free(ss[i]);
  }
  free(ss);
  return 0;
}
