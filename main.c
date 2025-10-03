#include "env.h"
#include <stdio.h>
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
	char *line = NULL;
	size_t size = 0;
	ssize_t line_size;
	pid_t pid;
	int status;
	char *cargv[2] = {NULL, NULL};

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		line_size = getline(&line, &size, stdin);
		if (line_size == -1)
			break;
		line[line_size - 1] = '\0';
		if (line[0] == '\0')
			continue;
		cargv[0] = line;
		pid = fork();
		if (pid == -1)
			continue;
		if (pid == 0)
		{
			if (execve(line, cargv, environ) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(-1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(line);
	return (0);
}
