#include <Python.h>

/**
 * print_python_int - entry to print_python_int
 * Desc: print_python_int function that prints Python integers
 * @p: pointer to PyObject type
 * Return: print integers
 */
void print_python_int(PyObject *p)
{
	unsigned long val = 0;
	Py_ssize_t size, i, a_bs;
	digit *number;


	if (PyLong_Check(p) == 0 || p == NULL)
	{
		printf("Invalid Int Object\n");
		return;
	}

	number = ((PyLongObject *)(p))->ob_digit;
	size = ((PyVarObject *)(p))->ob_size, a_bs = abs(size);


	if (a_bs > 3 || (a_bs == 3 && number[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		return;
	}

	for (i = 0; i < a_bs; i++)
		val += number[i] * (1L << (i * PyLong_SHIFT));

	if (size < 0)
		printf("-");

	printf("%lu\n", val);
}
