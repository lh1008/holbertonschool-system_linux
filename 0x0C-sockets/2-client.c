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
 * Desc: main function that connects a client to a server
 * @argc: number of arguments passed
 * @argv: pointer to arguments
 * Return: printed connected message, and 0 in success
 */
int main(int argc, char *argv[])
{
	int sockfd, con_nect;
	uint16_t port;
	char *host;
	struct sockaddr_in servaddr;

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	host = argv[1];
	port = atoi(argv[2]);

	sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)
		socket_error("socket failed");

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = strcmp("localhost", host) ?
		inet_addr(argv[1]) : inet_addr("127.0.0.1");

	con_nect = connect(sockfd, (struct sockaddr *)&servaddr,
			   sizeof(servaddr));
	if (con_nect < 0)
		socket_error("connect failed");
	printf("Connected to localhost:%d\n", ntohs(servaddr.sin_port));
	close(sockfd);
	return (0);
}
