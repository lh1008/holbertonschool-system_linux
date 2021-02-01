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
 * @fd: file descriptor
 * @buf: character buffer
 * @next_l: position of buffer
 * @next: pointer to next node
 * Description: node structure that holds the file descriptor
 */
typedef struct descriptor
{
	int fd;
	char *buf;
	size_t i;
	size_t len;
	struct descriptor *next;
} descriptor_t;

char *_getline(const int fd);
char *read_buf(descriptor_t *fb);
descriptor_t *get_descriptor_buf(descriptor_t *head, const int fd);
char *_strchr(char *s, char c, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* _GETLINE_H */
