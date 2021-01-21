#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

/**
 * open_dir - function taking parameters
 * Desc: open_dir function
 * @argc: number of parameters passed
 * @argv: pointer pointing to position parameter
 */
extern int open_dir(int argc, char *argv[]);
extern int open_dir_path(int argc, char *argv[]);

#endif /* HEADERS_H */
