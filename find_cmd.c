#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * find_cmd - Finds the full path of a command in the PATH
 * @cmd: The command name
 *
 * Return: A pointer to a string containing the full path of the command
 *         or NULL if the command is not found or cannot be executed.
 */
char *find_cmd(char *cmd)
{
	char *path = getenv("PATH"), *tkn, *path_cpy, *cmd_path;

	path_cpy = strdup(path);
	if (path_cpy == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
	for (tkn = strtok(path_cpy, ":"); tkn != NULL; tkn = strtok(NULL, ":"))
	{
		cmd_path = malloc(strlen(tkn) + strlen(cmd) + 2);
		if (cmd_path == NULL)
			break;
		sprintf(cmd_path, "%s/%s", tkn, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(path_cpy);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free(path_cpy);
	return (NULL);
}
