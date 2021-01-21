#include "headers.h"

/**
 * print_arg - Entry point
 * Desc: print_arg function to parse parameters
 * @argc: number of arguments passed
 * @argv: pointer to array of arguments passed
 * Return: prints parameters.
 */
void get_arg(int argc, char **argv)
{
	int i, x;

	for (i = 0; i < argc; i++)
	{
		if (*argv[i] == '-')
		{
			for (x = 0; x < strlen(argv[i]); x++)
			{
				printf("%c", argv[i][x]);
			}
			putchar('\n');
		}
		else
			printf("%s\n", argv[i]);
	}
}
