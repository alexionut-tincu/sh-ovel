/***************************************************************************//**
 * 
 * @file      builtins.h
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Function declarations for built-in shell commands
 * 
 ******************************************************************************/

#ifndef BUILTINS_H
#define BUILTINS_H

extern char *builtin_str[];
extern int (*builtin_fnc[])(char **);

int fnc_cd(char **args);
int fnc_help(char **args);
int fnc_exit(char **args);
int num_builtins();

#endif /* BUILTINS_H */