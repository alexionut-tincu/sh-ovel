/***************************************************************************//**
 * 
 * @file      parse.c
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function definitions for parsing the input
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

#define RL_BUF_SZ 4096
#define TOK_BUF_SZ 64
#define TOK_DELIM " \t\r\n\a"

/**
 * @brief Read a line from the standard input
 * @return The line read from the standard input
 */
char *
read_line(void)
{
	ssize_t buf_sz = RL_BUF_SZ;
	char *buf = malloc(buf_sz * sizeof(char));
	int c;
	int pos = 0;

	if (!buf) {
		fprintf(stderr, "sh-ovel: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();

		/* When EOF is encountered, replace with null */
		if (c == EOF || c == '\n') {
			buf[pos] = '\0';
			return buf;
		} else {
			buf[pos] = c;
		}

		pos++;

		if (pos >= buf_sz) {
			buf_sz += RL_BUF_SZ;
			buf = realloc(buf, buf_sz);
			if (!buf) {
				fprintf(stderr, "sh-ovel: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * @brief Split the line into tokens
 * @param line The line to split
 * @return The tokens
 */
char **
split_line(char *line)
{
	ssize_t buf_sz = TOK_BUF_SZ;
	char **tokens = malloc(buf_sz * sizeof(char *));
	char *token;
	int pos = 0;

	if (!tokens) {
		fprintf(stderr, "sh-ovel: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL) {
		tokens[pos] = token;
		pos++;

		if (pos >= buf_sz) {
			buf_sz += TOK_BUF_SZ;
			tokens = realloc(tokens, buf_sz * sizeof(char *));
			if (!tokens) {
				fprintf(stderr, "sh-ovel: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}

	tokens[pos] = NULL;
	return tokens;
}