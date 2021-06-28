#include "multithreading.h"

pthread_mutex_t lock_x;
void begin(void) __attribute__((constructor));
void end(void) __attribute__((destructor));

/**
 * tprintf - entry to printf
 * Desc: tprintf function that uses the printf
 * family to print out a given formatted string
 * @format: variadic pointer const char
 * Return: printed pthread_self() and arg
 */
int tprintf(char const *format, ...)
{
	va_list args;

	va_start(args, format);

	printf("[%ld] %s", pthread_self(), format);

	pthread_mutex_lock(&lock_x);

	va_end(args);

	pthread_mutex_unlock(&lock_x);

	return (0);
}

/**
 * begin - entry to begin constructor
 * Desc: begin function that starts a mutex init before
 * executing main
 * Return: nothing, void function
 */
void begin(void)
{
	pthread_mutex_init(&lock_x, NULL);
}

/**
 * end - entry to end destructor
 * Desc: end function that exits a mutex init
 * Return: nothing, void function
 */
void end(void)
{
	pthread_exit(NULL);
}
