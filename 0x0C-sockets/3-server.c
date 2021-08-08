#include "header.h"

/**
 * socket_error - entry to socket error
 * Desc: socket_error function that prints error
 * @err: pointer to error string message
 * Return: EXIT_FAILURE when error
 */
void socket_error(char *err)
{
	printf("%s\n", err);
	exit(EXIT_FAILURE);
}

/**
 * main - entry to main
 * Desc: main function to open a socket connection print port, IP
 * wait for incoming message from client, print message, close
 * connection, exit.
 * Return:, nothing, void function.
 */
int main(void)
{
	int servSock, status, ac_cept, client_msg;
	struct sockaddr_in echoServPort, client_addr;
	socklen_t client_addrlen;
	char buffer[1024] = {0};

	servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (servSock < 0)
		socket_error("socket failed");
	echoServPort.sin_family = AF_INET;
	echoServPort.sin_port = htons(PORT);
	echoServPort.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(servSock, (struct sockaddr *) &echoServPort,
		 sizeof(echoServPort)) < 0)
		socket_error("bind failed");

	status = listen(servSock, MAXPENDING);
	if (status < 0)
		socket_error("listen failed");
	printf("Server listening to port %d\n", ntohs(echoServPort.sin_port));
	ac_cept = accept(servSock, (struct sockaddr *) &client_addr,
			 (socklen_t *) &client_addrlen);
	if (ac_cept < 0)
		socket_error("accept failed");
	printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
	client_msg = recv(ac_cept, buffer, 1024, 0);
	if (client_msg < 0)
		socket_error("received failed");
	close(ac_cept), close(servSock);
	printf("Message received: \"%s\n", buffer);
	return (0);
}
