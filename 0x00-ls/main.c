#include "headers.h"
/**
 * main - Entry point
 * Desc: main opens a directory streams and browsers.
 * @argc: number of arguments passed
 * @argv: pointer to array to arguments
 * Return: prints directories files and folders.
 */
int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		open_dir(argc, argv);
	}
	else if (argc == 2)
	{
		open_dir_path(argc, argv);
	}

	return (0);
}
