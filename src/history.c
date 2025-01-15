/***************************************************************************//**
 * 
 * @file      history.h
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function definitions for the history
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

/* History buffer */
static char *history[HISTORY_SIZE];
static int history_count = 0;

/**
 * @brief Initialize the history
 * @param filename The history file
 */
void
history_init(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if(!file) {
		return;
	}

	char *line = NULL;
	size_t len = 0;
	while (getline(&line, &len, file) != -1) {
		if (history_count < HISTORY_SIZE) {
			history[history_count++] = strdup(line);
			history[history_count - 1][strlen(history[history_count - 1]) - 1] = '\0';
		}
	}
	free(line);
	fclose(file);
}

/**
 * @brief Add a command to the history
 * @param command The command to add
 */
void
history_add(const char *command)
{
	if (history_count < HISTORY_SIZE) {
		history[history_count++] = strdup(command);
	} else {
		free(history[0]);
		memmove(history, history + 1, (HISTORY_SIZE - 1) * sizeof(char *));
		history[HISTORY_SIZE - 1] = strdup(command);
	}
}

/**
 * @brief Save the history to a file
 * @param filename The history file
 */
void
history_save(const char *filename)
{
	FILE *file = fopen(filename, "w");
	if(!file) {
		perror("Error opening history file");
		return;
	}

	for (int i = 0; i < history_count; ++i) {
		fprintf(file, "%s\n", history[i]);
	}
	fclose(file);
}

/**
 * @brief Free the history
 */
void
history_free(void)
{
	for (int i = 0; i < history_count; ++i) {
		free(history[i]);
	}
	
	history_count = 0;
}

/**
 * @brief Get a command from the history
 * @param index The index of the command
 * @return The command
 */
const char *
history_get(int index)
{
	if (index < 0 || index >= history_count) {
		return NULL;
	}
	return history[index];
}

/**
 * @brief Get the size of the history
 * @return The size of the history
 */
int
history_size(void)
{
	return history_count;
}
