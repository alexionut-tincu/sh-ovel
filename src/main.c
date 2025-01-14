/***************************************************************************//**
 * 
 * @file      main.c
 * 
 * @author    Alexandru-Ionuț Țîncu
 * 
 * @brief     Entry point of the shell
 * 
 ******************************************************************************/

#include <stdio.h>
#include "loop.h"

int main() {
	loop();

	printf("sh-ovel is sh-out. Goodbye\n");
	return 0;
}
