/***************************************************************************//**
 * 
 * @file      execute.c
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function definitions for executing commands
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "builtins.h"
#include "execute.h"

/**
 * @brief Launch a program and wait for it to terminate
 * @param args List of arguments
 * @return 1 to continue execution
 */
int
launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {
		/* Child process */
		if (execvp(args[0], args) == -1) {
			fprintf(stderr, "sh-ovel: failed to execute %s\n", args[0]);
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		/* Error forking */
		perror("sh-ovel");
	} else {
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED | WCONTINUED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

/**
 * @brief Execute a command
 * @param args List of arguments
 * @return 1 to continue execution
 */
int
execute(char **args)
{
	int i;

	if (args[0] == NULL || strcmp(args[0], "") == 0) {
		/* Empty command */
		return 1;
	}

	for (i = 0; i < num_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_fnc[i])(args);
		}
	}

	return launch(args);
}