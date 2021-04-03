#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME "/sp-example-server"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256
#define MESSAGE_BUFFER_SIZE MAX_MESSAGE_SIZE + 10

int main(int argc, char **argv) {
  char client_queue_name[64];
  mqd_t qd_server, qd_client;

  sprintf(client_queue_name, "/sp-example-client-%d", getpid());

  struct mq_attr attr;
  attr.mq_flags = 0;
  attr.mq_maxmsg = MAX_MESSAGES;
  attr.mq_msgsize = MAX_MESSAGE_SIZE;
  attr.mq_curmsgs = 0;

  if((qd_client = mq_open(client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
    perror("Client: mq_open(client)");
    exit(1);
  }

  if((qd_server = mq_open(SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
    perror("Client: mq_open(server)");
    exit(1);
  }

  char in_buffer[MESSAGE_BUFFER_SIZE];
  printf("Ask for a token (Press <Enter>): ");

  char temp_buf [10];
  while(fgets(temp_buf, 2, stdin)) {
    if(mq_send(qd_server, client_queue_name, strlen(client_queue_name) + 1, 0) == -1) {
      perror("Client: Not able to send message to server");
      continue;
    }

    if(mq_receive(qd_client, in_buffer, MESSAGE_BUFFER_SIZE, NULL) == -1) {
      perror("Client: mq_receive");
      exit(1);
    }

    printf("Client: token received from server: %s\n\n", in_buffer);
    printf("Ask for a token (Press <Enter>): ");
  }

  if(mq_close(qd_client) == -1) {
    perror("Client: mq_close");
    exit(1);
  }

  if(mq_unlink(client_queue_name) == -1) {
    perror("Client: mq_unlink");
    exit(1);
  }
  printf("Client: bye\n");

  exit(0);
}
