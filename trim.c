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
	char *start = s, *end;

	while (*start == ' ' || *start == '\t')
		start++;
	if (*start == '\0')
	{
		*s = '\0';
		return (s);
	}
	end = start + strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t'))
		end--;
	*(end + 1) = '\0';
	if (start != s)
		memmove(s, start, end - start + 2);
	return (s);
}
