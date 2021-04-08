/* 
 * Author: Adam Chisolm
 * File: main.c
 * Description: Main driver for Conway's Game of Life. 
 *
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // for sleep

//char** board;
char board[10][10];
int max_y, max_x;
char* board2 = "Hello worldy";

void init();
void test();

int main(int argc, char* argv[])
{

	printf("hello, world\n");

	init();

	test();

	sleep(1);
	for (int i=0; i<10; ++i)
	{
		for (int j=0; j<10; ++j)
		{
			mvprintw(i, j, board[i][j]);
			refresh();
			usleep(10000);
		}
		//sleep(1);
		usleep(10000);
	}

	mvprintw(0, 0, "hello, world");
	refresh();
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

	getmaxyx(stdscr, max_y, max_x);
}

void update()
{
	for (int i=0; i<15; ++i)
	{
		mvprintw(0, i, "o");
		refresh();
		sleep(1);
	}
}

void test()
{
	mvprintw(0, 0, board2);
}
