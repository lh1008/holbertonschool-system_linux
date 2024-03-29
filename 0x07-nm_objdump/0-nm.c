#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry to main function
 * Desc: main function program that reproduces the GNU nm command
 * @argc: number of arguments in command line
 * @argv: arguments from command line
 * @env: environment from shell
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv, char **env)
{
	char *av[] = {"./hnm", "-p", "", NULL};

	(void)argc;

	av[2] = argv[1];
	if (execve("/usr/bin/nm", av, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
