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
 * Desc: main function to open a socket connection
 * Return:, nothing, void function. Print port, IP, close connection.
 */
int main(void)
{
	int sockid, status, ac_cept;
	struct sockaddr_in addrport;
	int addrlen = sizeof(addrport);

	sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockid < 0)
		socket_error("socket failed");

	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(PORT);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockid, (struct sockaddr *) &addrport, sizeof(addrport)) < 0)
		socket_error("bind failed");

	status = listen(sockid, 3);
	if (status < 0)
		socket_error("listen failed");

	printf("Server listening to port %d\n", ntohs(addrport.sin_port));
	while (1)
	{
		ac_cept = accept(sockid, (struct sockaddr *) &addrport,
				 (socklen_t *) &addrlen);
		if (ac_cept < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("Client connected: %s\n", inet_ntoa(addrport.sin_addr));
		close(ac_cept);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
