#include "header.h"

/**
 * main - entry to main
 * Desc: main function to open a socket connection
 * Return:, nothing, void function. Print which port and maintain open.
 */
int main(void)
{
	int sockid, status;
	struct sockaddr_in addrport;

	sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sockid < 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(PORT);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockid, (struct sockaddr *) &addrport, sizeof(addrport)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}


	status = listen(sockid, 3);

	if (status < 0)
	{
		perror("listen failed");
		exit(EXIT_FAILURE);
	}

	printf("Server listening to port %d\n", ntohs(addrport.sin_port));
	while (1)
		;

	return (0);
}
