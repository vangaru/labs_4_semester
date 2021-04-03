#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include <signal.h>

#define SERVER_QUEUE_NAME "/fucking-server"
#define CLIENT_QUEUE_NAME "/fucking-client"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256
#define MESSAGE_BUFFER_SIZE MAX_MESSAGE_SIZE + 10
#define SCOUNT 3
#define FUCKING_TEST_STRING "im a fucking test string"
#define TRUE 1
#define FALSE 0

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

void killer() {
  write(STDOUT_FILENO, "I won't die\n", 13);
}

int main() {
  char input_strings[SCOUNT][MAX_MESSAGE_SIZE + 1];

  for(size_t i = 0; i < SCOUNT; i++) {
    printf("Enter %zu string : ", i + 1);
    fgets(input_strings[i], MAX_MESSAGE_SIZE, stdin);
    if ((strlen(input_strings[i]) > 0) && (input_strings[i][strlen (input_strings[i]) - 1] == '\n'))
        input_strings[i][strlen (input_strings[i]) - 1] = '\0';
  }

  struct sigaction action = { 0 };
  action.sa_handler = killer;
  sigaction(SIGUSR1, &action, NULL);

  pid_t pid = fork();
  if(pid == -1) {
    perror("Pid fork");
    return 1;
  } else if(pid == 0) {
    // Server process
    struct mq_attr server_attr;
    server_attr.mq_flags = 0;
    server_attr.mq_maxmsg = MAX_MESSAGES;
    server_attr.mq_msgsize = MAX_MESSAGE_SIZE;
    server_attr.mq_curmsgs = 0;

    mqd_t qd_receive_from_client, qd_send_to_client;

    if((qd_receive_from_client = mq_open(SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &server_attr)) == -1) {
      perror("Server: mq_open(client)");
      exit(1);
    }

    char in_buffer[SCOUNT][MAX_MESSAGE_SIZE];
    sleep(1);
    for(size_t i = 0; i < SCOUNT; i++) {
      int bytes_read;
      if((bytes_read = mq_receive (qd_receive_from_client, in_buffer[i], MAX_MESSAGE_SIZE, NULL)) == -1) {
        perror("Server: mq_receive");
        exit(1);
      }
      in_buffer[i][bytes_read] = '\0';
      printf("Server: message received from client: %s\n", in_buffer[i]);
    }

    size_t max_vowels = 0;
    char res_string[MAX_MESSAGE_SIZE];

    for(size_t i = 0; i < SCOUNT; i++) {
      size_t tmp = 0;
      for(size_t j = 0; j < strlen(in_buffer[i]); j++) {
        if(is_vowel(in_buffer[i][j])) {
          tmp++;
        }
      }
      if(tmp > max_vowels) {
        max_vowels = tmp;
        strcpy(res_string, in_buffer[i]);
        res_string[strlen(in_buffer[i])] = '\0';
      }
    }

    if((qd_send_to_client = mq_open(CLIENT_QUEUE_NAME, O_WRONLY)) == -1) {
      perror("Server: mq_open(client)");
      exit(1);
    }

    if(mq_send(qd_send_to_client, res_string, strlen(res_string), 0) == -1) {
      perror("Server: Not able to send message to client");
      exit(1);
    }


  } else {
    // Client process
    kill(pid, SIGUSR1);
    struct mq_attr client_attr;
    client_attr.mq_flags = 0;
    client_attr.mq_maxmsg = MAX_MESSAGES;
    client_attr.mq_msgsize = MAX_MESSAGE_SIZE;
    client_attr.mq_curmsgs = 0;

    mqd_t qd_send_to_server, qd_receive_from_server;

    if((qd_send_to_server = mq_open(SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
      perror("Client: mq_open(server)");
      exit(1);
    }

    for(size_t i = 0; i < SCOUNT; i++) {
      if(mq_send(qd_send_to_server, input_strings[i], strlen(input_strings[i]), 0) == -1) {
        perror("Client: Not able to send message to server");
        exit(1);
      }
      printf("Client: message sent to server: %s\n", input_strings[i]);
    }

    if((qd_receive_from_server = mq_open(CLIENT_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &client_attr)) == -1) {
      perror("Client: mq_open(client)");
      exit(1);
    }

    int bts_read;
    char buf[MAX_MESSAGE_SIZE + 1];
    if((bts_read = mq_receive(qd_receive_from_server, buf, MAX_MESSAGE_SIZE, NULL)) == -1) {
      perror("Client: mq_receive");
      exit(1);
    }

    //sleep(1);
    printf("Client: result message eceived from server: %s\n", buf);

    //printf("Try to appear after that\n");

    // if(mq_close(qd_send_to_server) == -1) {
    //   perror("Client: mq_close(server)");
    //   exit(1);
    // }
    //
    // if(mq_unlink(CLIENT_QUEUE_NAME) == -1) {
    //   perror("Client: mq_unlink");
    //   exit(1);
    // }
  }
  return 0;
}
