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

	int dir_path = 0;

	if (argc == 1)
	{
		/*get_arg(argc, argv);*/
		dir_path = open_dir(argc, argv);
	}
	else if (argc > 1)
	{
		get_arg(argc, argv);
		/*dir_path = open_dir_path(argc, argv);*/
	}

	return (dir_path);
}
