#include "_getline.h"

/**
 * _getline - gets line
 * Desc: _getline that reads an entire line from file descriptor
 * @fd: const int type that receives file descriptor open()
 * Return: null-terminated string that does not include the new line character
 */
char *_getline(const int fd)
{
	static descriptor_t head;
	descriptor_t *fb = NULL, *temp = NULL;
	char *line = NULL;

	if (fd == -1)
	{
		if (head.buf == NULL)
			head.buf = (free(head.buf), NULL);
		fb = head.next;
		while (fb != NULL)
		{
			if (fb->buf != NULL)
			{
				free(fb->buf);
				fb->buf = NULL;
			}
			temp = fb;
			fb = fb->next;
			free(temp);
		}
		memset(&head, 0, sizeof(head));
		return (NULL);
	}
	fb = get_descriptor_buf(&head, fd);
	if (fb)
		line = read_buffer(fb);
	if (line && line[0] == '\n' && !line[1])
		line[0] = 0;
	return (line);
}

/**
 * read_buffer - reads into the buffer
 * Desc: read_buffer function
 * @fb: the fd buf struct
 * Return: 0 on success else -1 on error.
 */
char *read_buffer(descriptor_t *fb)
{
	char buf[READ_SIZE + 1], *p, *line;
	ssize_t r = 0;

	p = _strchr(fb->buf + fb->i, '\n', fb->len - fb->i);
	if (fb->len == 0 || fb->i >= fb->len || p == NULL)
	{
		while (1)
		{
			r = read(fb->fd, buf, READ_SIZE);
			if (r < 0 || (r == 0 && fb->len == 0))
				return (fb->buf ? (free(fb->buf), NULL) : NULL);
			if (r == 0)
			{
				p = fb->buf + fb->len;
				break;
			}
			fb->buf = _realloc(fb->buf, fb->len, fb->len + r + 1);
			if (fb->buf == NULL)
				return (NULL);
			memcpy(fb->buf + fb->len, buf, r), fb->len += r;
			p = _strchr(fb->buf + (fb->len - r), '\n', r);
			if (p)
			{
				fb->buf[fb->len] = 0;
				break;
			}
		}
	}
	*p = '\0';
	line = malloc(1 + (p - (fb->buf + fb->i)));
	if (line == NULL)
		return (NULL);
	memcpy(line, fb->buf + fb->i, 1 + (p - (fb->buf + fb->i)));
	fb->i = (p - fb->buf) + 1;
	if (fb->i >= fb->len)
	{
		fb->i = fb->len = 0;
		fb->buf = (free(fb->buf), NULL);
	}
	return (line);
}

/**
 * get_descriptor_buf - entry to struct buf
 * Desc: get_descriptor_buf function
 * @head: pointer to head node
 * @fd: file descriptor of buffer to get
 * Return: pointer to the fd buf head node
 */
descriptor_t *get_descriptor_buf(descriptor_t *head, const int fd)
{
	descriptor_t *node;

	if (head->buf == NULL && head->fd == '\0'
	    && head->next == NULL)
	{
		head->fd = fd;
		return (head);
	}
	while (head->next && head->next->fd <= fd)
		head = head->next;
	if (head->fd == fd)
		return (head);
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	if (fd < head->fd)
	{
		memcpy(node, head, sizeof(*head));
		memset(head, 0, sizeof(*head));
		head->fd = fd;
		head->next = node;
		return (head);
	}
	memset(node, 0, sizeof(*node));
	node->fd = fd;
	node->next = head->next;
	head->next = node;
	return (node);
}

/**
 ** _strchr - entry to compare character
 * Desc: _strchr function that locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * @len: number of bytes to search
 * Return: pointer to memory
 */
char *_strchr(char *s, char c, size_t len)
{
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _realloc - entry to reallocate
 * Desc: _realloc function that reallocates a block of memory
 * @ptr: pointer to buffer
 * @old_size: unisigned int type old size
 * @new_size: unsigned int type new size
 * Return: memory allocation, NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			free(ptr);
			return (NULL);
		}
		free(ptr);
		return (new);
	}
	new = malloc(new_size);
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
		memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
