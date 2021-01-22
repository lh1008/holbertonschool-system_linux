#include "headers.h"

/**
 * print_arg - Entry point
 * Desc: print_arg function to parse parameters
 * @argc: number of arguments passed
 * @argv: pointer to array of arguments passed
 * Return: prints parameters.
 */
void get_arg(int argc, char **argv)
{
	int i, x;
	struct op_tions *option_s;

	for (i = 0; i < argc; i++)
	{
		if (*argv[i] == '-')
		{
			for (x = 0; x < strlen(argv[i]); x++)
			{
				switch (argv[i][x])
				{
				case 'a': option_s->a = 1;
					printf("%d", option_s->a);
					break;
				case 'A': option_s->A = 1;
					printf("%d", option_s->A);
					break;
				case 'l': option_s->l = 1;
					printf("%d", option_s->l);
					break;
				case '1': option_s->one = 1;
					printf("%d", option_s->one);
					break;
				case '-':
					break;
				default: option_s->err = errno;
					printf("%d", option_s->err);
					break;
				}
				/*printf("%c", argv[i][x]);*/
			}
			putchar('\n');
		}
		else
		{
			open_dir_path(argc, argv);
			printf("%s\n", argv[i]);
		}
	}
}
