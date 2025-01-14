/***************************************************************************//**
 *
 * @file      parse.h
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function declarations for parsing the input
 * 
 ******************************************************************************/

#ifndef PARSE_H
#define PARSE_H

char *read_line(void);
char **split_line(char *line);

#endif /* PARSE_H */