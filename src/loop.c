/***************************************************************************//**
 *
 * @file      oop.c
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function definition for the shell loop
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "builtins.h"
#include "execute.h"
#include "loop.h"
#include "parse.h"

/**
 * @brief The shell loop
 */
void
loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("sh-ovel > ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}