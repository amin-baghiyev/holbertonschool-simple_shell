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
	char *line = NULL, *token;
	size_t size = 0;
	ssize_t line_size;
	pid_t pid;
	int status, i;
	char *cargv[3] = {NULL, NULL, NULL};

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		line_size = getline(&line, &size, stdin);
		if (line_size == -1)
			break;
		line[line_size - 1] = '\0';
		line = trim(line);
		if (line[0] == '\0')
			continue;
		token = strtok(line, " \t");
		for (i = 0; token != NULL && i < 2; i++)
			cargv[i] = token, token = strtok(NULL, " \t");
		pid = fork();
		if (pid == -1)
			continue;
		if (pid == 0)
		{
			if (execve(cargv[0], cargv, environ) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(-1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(line);
	return (0);
}
