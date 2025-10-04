#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * @argc: count of argv
 * @argv: arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *line = NULL, *token, *cargv[64], *cmd;
	size_t size = 0;
	ssize_t line_size;
	pid_t pid;
	int status, i;

	(void)argc;
	while (1)
	{
		for (i = 0; i < 64; i++)
			cargv[i] = NULL;
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		line_size = getline(&line, &size, stdin);
		if (line_size == -1)
			break;
		line[line_size - 1] = '\0', line = trim(line);
		if (line[0] == '\0')
			continue;
		token = strtok(line, " \t");
		for (i = 0; token != NULL && i < 63; i++)
			cargv[i] = token, token = strtok(NULL, " \t");
		cmd = cargv[0], cargv[0] = find_cmd(cargv[0]);
		if (cargv[0] == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
			continue;
		}
		pid = fork();
		if (pid == -1)
			continue;
		if (pid == 0)
			execve(cargv[0], cargv, environ), exit(-1);
		else
			waitpid(pid, &status, 0);
		if (cargv[0] != NULL)
			free(cargv[0]);
	}
	free(line);
	return (0);
}
