#ifndef _GETLINE_H
#define _GETLINE_H

#define READ_SIZE 1020

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct file_descriptor - singly linked list for a file descriptor
 * @fd: int file descriptor
 * @buf: pointer to char buffer
 * @i: size_t int type
 * @len: size_t int type
 * @next: pointer to next node
 * Description: node structure that holds the file descriptor
 */
typedef struct file_descriptor
{
	int fd;
	char *buf;
	size_t i;
	size_t len;
	struct file_descriptor *next;
} descriptor_t;

char *_getline(const int fd);
char *read_buffer(descriptor_t *fb);
descriptor_t *get_descriptor_buf(descriptor_t *head, const int fd);
char *_strchr(char *s, char c, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* _GETLINE_H */
