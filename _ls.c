#include "holberton.h"

/**
 * _ls - custom implemention of ls
 * @t: tokens
 * @p: pname
 * @c: tokens count
 *
 * Return: int
 */
int _ls(char **t, char __attribute__((__unused__)) *p, int c)
{
	if (c == 1)
	{
		_custom_ls(".", 0, 0);
	}
	else if (c == 2)
	{
		if (t[1][0] == '-')
		{
			int op_a = 0, op_l = 0;
			char *p = (char *)(t[1] + 1);

			while (*p)
			{
				if (*p == 'a')
					op_a = 1;
				else if (*p == 'l')
					op_l = 1;
				else
				{
					perror("Option not available");
					exit(-1);
				}
				p++;
			}
			_custom_ls(".", op_a, op_l);
		}
	}
	return (1);
}

/**
 * _custom_ls - implement builtin ls
 * @dir: dir name
 * @op_a: val1
 * @op_l: val2
 *
 * Return: nothing
 */
void _custom_ls(const char *dir, int op_a, int op_l)
{
	struct dirent *d;
	DIR *dh = opendir(dir);
	char *msg = NULL;

	if (!dh)
	{
		if (errno == ENOENT)
			perror("Directory doesn't exist");
		else
			perror("Unable to read directory");
		exit(-1);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		msg = _strcat(d->d_name, "  ");
		write(STDOUT_FILENO, msg, _length(msg));
		if (op_l)
			write(STDOUT_FILENO, "\n", 1);
		free(msg);
	}
	if (!op_l)
		write(STDOUT_FILENO, "\n", 1);
}
