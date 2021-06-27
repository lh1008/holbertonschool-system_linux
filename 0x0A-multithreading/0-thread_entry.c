#include "multithreading.h"

static int ret;

/**
 * thread_entry - entry to thread entry
 * Desc: thread_entry function that will serve as
 * the entry point to a new thread
 * @arg: void pointer that holds the address of a string
 * Return: nothing, void function
 */
void *thread_entry(void *arg)
{
	char *s = (char *)arg;

	if (ret == 1)
	{
		printf("%s\n", s);
		pthread_exit(&ret);
	}
	else
	{
		printf("%s\n", s);
		ret = 1;
	}

	return (0);
}
