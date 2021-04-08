/* 
 * Author: Adam Chisolm
 * File: main.c
 * Description: Main driver for Conway's Game of Life. 
 *
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // for sleep

#define DELAY 30000

//char** board;
char board[24][80];
int max_y, max_x;
char* board2 = "Hello worldy";

void init();
void test();
void set_board();
void print_screen();

int main(int argc, char* argv[])
{

	printf("hello, world\n");

	init();
	
	set_board();

	for (int i=0; i<max_y;++i)
		for (int j = 0; j < max_x; j++)
		{
			board[i][j] = 'o';
			print_screen();
		}
		
	sleep(1);
	
	endwin();

	printf("max_X: %d\nmax_y: %d\n", max_x, max_y);

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

void set_board()
{
	for (int row=0; row<max_y; ++row)
	{
		for (int col=0;col<max_x; ++col)
		{
			board[row][col] = 'x';
		}
	}
}
void print_screen()
{
	//clear();
	for (int row=0; row<max_y; ++row)
	{
		mvprintw(row, 0, board[row]);
	}
	refresh();
	usleep(DELAY);
}
