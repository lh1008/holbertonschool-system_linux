#include <Python.h>
#include <object.h>
#include <unicodeobject.h>
#include <stdio.h>

/**
 * print_python_string - entry to print_python_string
 * Desc: print_python_string function that prints Python string
 * @p: pointer to pyObject
 * Return: void function, nothing is returned
 */
void print_python_string(PyObject *p)
{

	wchar_t *val;
	char *data;
	Py_ssize_t len;

	printf("[.] string object info\n");
	if (strncmp(p->ob_type->tp_name, "str", 3) != 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	len = ((PyASCIIObject *)(p))->length;
	val = PyUnicode_AsWideCharString(p, &len);
	if (PyUnicode_IS_COMPACT_ASCII(p) != 0)
		data = "compact ascii";
	else
		data = "compact unicode object";
	printf("  type: %s\n  length: %lu\n  value: %ls\n", data, len, val);
}
