#include "headers.h"

#define BLUE "\x1B[34m"
#define GREEN "\x1b[32m"
/**
 * open_dir - Entry point
 * Desc: open_dir opens a directory streams and browses.
 * @argc: number of arguments passed
 * @argv: pointer to array of arguments passed
 * Return: prints directories files and folders.
 */
int open_dir(int argc, char *argv[])
{
	DIR *dir = NULL;
	struct dirent *read = NULL;
	char string;

	dir = opendir("."); /* Opens directory  */

	if (dir == NULL) /* Checks if directory is empty */
		return (0);


	while ((read = readdir(dir)) != NULL)
	{
		if (strcmp(read->d_name, ".") != 0 && strcmp(read->d_name, "..") != 0)
		{
			if (read->d_type == DT_DIR)
			{
				printf(BLUE "%s ", read->d_name);
			}
			else if (read->d_type == DT_REG)
			{
				printf(GREEN "%s  ", read->d_name);
			}
		}
	}
	puts("\n");
	closedir(dir);
}
