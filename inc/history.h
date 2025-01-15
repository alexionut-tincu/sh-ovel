/***************************************************************************//**
 * 
 * @file      history.h
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function declarations for the history
 * 
 ******************************************************************************/

#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_SIZE 128

void history_init(const char *filename);
void history_add(const char *command);
void history_save(const char *filename);
void history_free(void);
const char *history_get(int index);
int history_size(void);

#endif /* HISTORY_H */