#include "header.h"

/**
 * main - entry to main
 * Desc: main function to open a socket connection
 * Return:, nothing, void function. Print which port and maintain open.
 */
int main(void)
{
	int sockid, status, ac_cept;
	struct sockaddr_in addrport;
	int addrlen = sizeof(addrport);

	sockid = socket(PF_INET, SOCK_STREAM, 0);

	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(PORT);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockid, (struct sockaddr *) &addrport, sizeof(addrport)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	status = listen(sockid, 1);

	if (status < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	printf("Server listening to port %d\n", ntohs(addrport.sin_port));

	ac_cept = accept(sockid, (struct sockaddr *) &addrport,
			 (socklen_t *) &addrlen);
	if (ac_cept < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
}
