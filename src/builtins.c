/***************************************************************************//**
 * 
 * @file      builtins.c
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function definitions for built-in shell commands
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_fnc[])(char **) = {
	&fnc_cd,
	&fnc_help,
	&fnc_exit
};

/**
 * @brief Change directory
 * @param args List of arguments
 * @return 1 to continue execution
 */
int
fnc_cd(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "sh-ovel: expected argument to \"cd\"\n");
	} else {
		if (chdir(args[1]) != 0) {
			perror("sh-ovel");
		}
	}
	return 1;
}

/**
 * @brief Display help information
 * @param args List of arguments
 * @return 1 to continue execution
 */
int
fnc_help(char **args)
{
	printf("sh-ovel shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("Use the man command for information on other programs.\n");
	return 1;
}

/**
 * @brief Exit the shell
 * @param args List of arguments
 * @return 0 to exit the shell
 */
int
fnc_exit(char **args)
{
	return 0;
}

/**
 * @brief Get the number of built-in commands
 * @return Number of built-in commands
 */
int
num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}