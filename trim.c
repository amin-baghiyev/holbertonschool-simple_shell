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
	size_t len = strlen(s), start = 0, end = len - 1;

	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (start > 0)
		memmove(s, s + start, end - start + 1);
	s[end - start + 1] = '\0';
	return (s);
}
