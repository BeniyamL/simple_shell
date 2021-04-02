#include <stdio.h>
#include "holberton.h"

/**
 * main - run exercise questions
 * @argc: argument counter
 * @argv: argument values
 * 
 * Return: always 0
 */
int main (int argc, char **argv)
{
	char *line;

	while (1)
	{
		line = _getline(argv[0]);
		printf("%s\n", line);
	}

	return (1);
}
