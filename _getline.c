#include <stdlib.h>
#include <stdio.h>

/**
 * _getline - custom get line function
 *
 * Return: one line string
 */
char *_getline(char *prName)
{
	char *line;
	int c;
	size_t i = 0, strLen = 1024;

	line = malloc(sizeof(char) * strLen);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	printf("%s$", prName);
	c = getchar();

	while (c != EOF && c != '\n')
	{
		if (i > strLen - 1)
		{
			strLen += 1024;
			line = realloc(line, strLen);
			if (line == NULL)
			{
				free(line);
				return (NULL);
			}
		}
		line[i] = c;
		i++;
		c = getchar();
	}
	line[i] = '\0';
	return (line);
}
