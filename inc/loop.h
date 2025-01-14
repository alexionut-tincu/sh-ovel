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

typedef enum {
	COLOR_RESET = 0,
	COLOR_BLACK = 30,
	COLOR_RED = 31,
	COLOR_GREEN = 32,
	COLOR_YELLOW = 33,
	COLOR_BLUE = 34,
	COLOR_MAGENTA = 35,
	COLOR_CYAN = 36,
	COLOR_WHITE = 37,
	COLOR_BRIGHT_BLACK = 90,
	COLOR_BRIGHT_RED = 91,
	COLOR_BRIGHT_GREEN = 92,
	COLOR_BRIGHT_YELLOW = 93,
	COLOR_BRIGHT_BLUE = 94,
	COLOR_BRIGHT_MAGENTA = 95,
	COLOR_BRIGHT_CYAN = 96,
	COLOR_BRIGHT_WHITE = 97
} TerminalColor;

const char *color_code(TerminalColor color);
void loop(void);

#endif /* LOOP_H */