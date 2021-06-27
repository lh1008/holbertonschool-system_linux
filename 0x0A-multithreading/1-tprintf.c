#include "multithreading.h"

/**
 * tprintf - entry to tprintf
 * Desc: tprintf function that uses the printf
 * family to print out a given formatted string
 * @format: variadic pointer const char
 * Return: return printed pthread_self()
 */
int tprintf(char const *format, ...)
{
	va_list args;

	va_start(args, format);

	printf("[%ld] %s", pthread_self(), format);

	va_end(args);

	return (0);
}
