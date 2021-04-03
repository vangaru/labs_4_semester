#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mqueue.h>

#define MQNAME "/message"
#define MQMESG "msg frm tsddd"
#define MAX_MSG_IN_QUEUE 10
#define MAX_MSG_SIZE 1024

int main() {
  struct mq_attr mqattr;
  mqattr.mq_maxmsg = MAX_MSG_IN_QUEUE;
  mqattr.mq_msgsize = MAX_MSG_SIZE;

  mqd_t snd_handl = mq_open(MQNAME, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &mqattr);

  if(snd_handl < 0) {
    printf("Error %d (%s) mq_open for send\n", errno, strerror(errno));
    exit(-1);
  }
  printf("Opened mqd_t of %d\n", snd_handl);

  int res = mq_send(snd_handl, MQMESG, sizeof(MQMESG), 1);
  if(res < 0) {
    printf("Error %d (%s) mq_send\n", errno, strerror(errno));
    exit(-1);
  }
  printf("Send mqd_t of %d\n", snd_handl);

  printf("\nReceiving message\n");
  mqd_t rcv_handl = mq_open(MQNAME, O_RDWR);
  if(rcv_handl < 0) {
    printf("Error %d (%s) mq_open for receive\n");
    exit(-1);
  }
  printf("Opened mqd_t of %d \n", rcv_handl);
  printf("Receiving mqd_t of %d \n", rcv_handl);

  char buffer[1024];
  res = mq_receive(rcv_handl, buffer, sizeof(buffer), NULL);
  if(res < 0) {
    printf("Error %d (%s) mq_receive\n", errno, strerror(errno));
    exit(-1);
  }
  printf("Received: [%s]\n", buffer);
  if(mq_unlink(MQNAME) < 0) {
    printf("Warning %s (%s) mq_unlink\n", errno, strerror(errno));
  }

  return 0;
}
