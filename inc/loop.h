/***************************************************************************//**
 * 
 * @file      loop.h
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function declaration for the shell loop
 * 
 ******************************************************************************/
#ifndef LOOP_H
#define LOOP_H

char *read_line(void);
char **split_line(char *line);
void loop(void);

#endif /* LOOP_H */