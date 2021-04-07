/* 
 * Author: Adam Chisolm
 * File: main.c
 * Description: Main driver for Conway's Game of Life. 
 *
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // for sleep

void init();

int main(int argc, char* argv[])
{

	printf("hello, world\n");

	init();

	sleep(1);
	
	endwin();

	return 0;
}

void init()
{
	// Init curses
	initscr();
	// Don't echo keypresses
	noecho();
	// Don't display cursor
	curs_set(FALSE);
}
