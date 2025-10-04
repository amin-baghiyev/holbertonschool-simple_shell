#include "main.h"
#include <string.h>

/**
 * trim - Removes leading and trailing whitespace characters from a string
 * @s: The string to be trimmed
 *
 * Return: A pointer to the trimmed string
 */
char *trim(char *s)
{
	char *end;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '\0')
		return (s);
	end = s + strlen(s) - 1;
	while (end > s && (*end == ' ' || *end == '\t'))
		end--;
	*(end + 1) = '\0';
	return (s);
}
