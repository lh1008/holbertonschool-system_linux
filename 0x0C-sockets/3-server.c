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
	int servSock, status, ac_cept;
	struct sockaddr_in echoServPort;
	int addrlen = sizeof(echoServPort);
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
	while (1)
	{
		ac_cept = accept(servSock, (struct sockaddr *) &echoServPort,
				 (socklen_t *) &addrlen);
		if (ac_cept < 0)
			socket_error("accept");
		printf("Client connected: %s\n",
		       inet_ntoa(echoServPort.sin_addr));
		read(ac_cept, buffer, 1024);
		printf("%s\n", buffer);

		close(ac_cept);
		exit(EXIT_SUCCESS);
	}
	return (0);
}