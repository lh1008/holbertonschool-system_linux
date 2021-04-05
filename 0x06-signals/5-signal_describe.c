#include "signals.h"

#define USAGE "Usage: %s <signum>\n"

/**
 * main - entry to main
 * Desc: function that prints the description of a signal
 * @argc: int type number of arguments
 * @argv: pointer to array of string argument
 * Return: signal number and name
 */
int main(int argc, char *argv[])
{
	char *signal;

	if (argc != 2)
	{
		printf(USAGE, argv[0]);
		exit(EXIT_FAILURE);
	}
	signal = strsignal(atoi(argv[1]));
	printf("%s: %s\n", argv[1], signal);
	return (0);
}
