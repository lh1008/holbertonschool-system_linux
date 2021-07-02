#include "multithreading.h"

/**
* prime_factor - entry to primer_factor
* Desc: primer_factor function to make the list of prime factors
* @n: number to get the prime factors
* @list: the list of prime factors
* Return: Nothing
*/
void prime_factor(unsigned long n, list_t *list)
{
	unsigned long i = 0, *number = NULL;

	while (n % 2 == 0)
	{
		number = calloc(1, sizeof(unsigned long));
		*number = 2;
		list_add(list, number);
		n /= 2;
	}
	i = 3;
	while (i * i <= n)
	{
		while (n % i == 0)
		{
			number = calloc(1, sizeof(unsigned long));
			*number = i;
			list_add(list, number);
			n /= i;
		}
		i += 2;
	}
	if (n > 2)
	{
		number = calloc(1, sizeof(unsigned long));
		*number = n;
		list_add(list, number);
	}
}

/**
 * prime_factors - entry to prime factors
 * Desc: prime_factors function that factorizes a
 * number into a list of prime factors
 * @s: pointer to the string representation of the number to factorize
 * Return: pointer to factorized string
 */
list_t *prime_factors(char const *s)
{
	list_t *list;
	int i = 0;
	unsigned long n = 0;

	if (s == NULL)
		return (NULL);
	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list = list_init(list);

	while (s[i])
	{
		n = (n * 10) + (s[i++] - '0');
	}
	prime_factor(n, list);
	return (list);
}
