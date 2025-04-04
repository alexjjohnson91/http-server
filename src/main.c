#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    perror("Socket failed\n");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;  // Listen on all available interfaces
  address.sin_port = htons(8080);        // Convert port to network byte order

  if (bind(socket_desc, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  char ip4[INET_ADDRSTRLEN];  // space to hold the IPv4 string

  inet_ntop(address.sin_family, &(address.sin_addr), ip4, INET_ADDRSTRLEN);

  printf("The IPv4 address is: %s\n", ip4);

  printf("success");
  exit(EXIT_SUCCESS);
}

