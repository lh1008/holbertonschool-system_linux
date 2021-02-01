#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * struct op_tions - This struct has the options from terminal
 * @a: -a option
 * @A: -A option
 * @l: -l option
 * @one: -1 option
 * @err: whenever an erros shows up
 * Description: Longer description
 */
typedef struct op_tions
{
	char a;
	char A;
	char l;
	int  one;
	int err;
} option_s;

/**
 * open_dir - function taking parameters
 * Desc: open_dir function
 * @argc: number of parameters passed
 * @argv: pointer pointing to position parameter
 */
extern int open_dir(int argc, char **argv);
extern int open_dir_path(int argc, char **argv);
extern void get_arg(int argc, char **arcg);

#endif /* HEADERS_H */
