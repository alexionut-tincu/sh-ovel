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
#include <string.h>
#include <unistd.h>
#include "builtins.h"
#include "execute.h"
#include "loop.h"
#include "parse.h"

#define CWD_BUF_SZ 1024

/**
 * @brief The color codes for the terminal
 * @param color The color to get the code for
 * @return The color code
 */
const char 
*color_code(TerminalColor color)
{
	static char code[8];
	snprintf(code, sizeof(code), "\033[%dm", color);
	return code;
}

/**
 * @brief The shell loop
 */
void
loop(void)
{
	char *line;
	char **args;
	int status;
	char cwd[CWD_BUF_SZ];
	do {
		if (getcwd(cwd, sizeof(cwd))) {
			char *dir = strrchr(cwd, '/');
			if (dir) {
				printf("%ssh-ovel%s ",
					color_code(COLOR_BRIGHT_GREEN),
					color_code(COLOR_RESET)
				);
				printf("%s%s%s ",
					color_code(COLOR_BRIGHT_BLUE),
					dir + 1,
					color_code(COLOR_RESET)
				);
				printf("%s> ",
					color_code(COLOR_BRIGHT_GREEN)
				);
			} else {
				printf("%ssh-ovel%s ",
					color_code(COLOR_BRIGHT_GREEN),
					color_code(COLOR_RESET)
				);
				printf("%s> ",
					color_code(COLOR_BRIGHT_GREEN)
				);
			}
			printf("%s", color_code(COLOR_RESET));
		} else {
			perror("getcwd() error");
			return;
		}
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}