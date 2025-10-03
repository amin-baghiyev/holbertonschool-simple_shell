#include "main.h"
#include <string.h>

char *trim(char *s)
{
	char *end;

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == 0)
		return (s);
	end = s + strlen(s) - 1;
	while (end > s && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;
	*(end + 1) = 0;
	return (s);
}
