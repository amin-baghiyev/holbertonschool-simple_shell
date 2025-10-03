#include "main.h"
#include <ctype.h>
#include <string.h>

char *trim(char *s)
{
	char *end;

	while (isspace((unsigned char)*s))
		s++;
	if (*s == 0)
		return (s);
	end = s + strlen(s) - 1;
	while (end > s && isspace((unsigned char)*end))
		end--;
	*(end + 1) = 0;
	return (s);
}
