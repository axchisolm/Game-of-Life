/* 
 * Author: Adam Chisolm
 * File: main.c
 * Description: Main driver for Conway's Game of Life. 
 *
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // for sleep

int main(int argc, char* argv[])
{

	printf("hello, world\n");

	// Init curses
	// Don't echo keypresses
	// Don't display cursor
	initscr();
	noecho();
	curs_set(FALSE);

	sleep(1);
	
	endwin();

	return 0;
}
