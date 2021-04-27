/* 
 * Author: Adam Chisolm
 * File: main.c
 * Description: Main driver for Conway's Game of Life. 
 *
 */

#include <stdio.h>
#include <curses.h>
#include <unistd.h> // for sleep

#define DELAY 300000

//char** board;

// Hard coding max values for now...
char board[24][80];
char next_board[24][80];
int max_y = 24, max_x = 80;
char* board2 = "Hello worldy";

struct node {
	int x;
	int y;
};

void init();
void set_board();
void print_screen();
//int is_legal(struct node n);
int is_legal(int x, int y);
int num_neighbors(struct node n);
void update();
void make_ant();

int main(int argc, char* argv[])
{

	printf("hello, world\n");

	struct node n = {-1, 0};

	// printf("node is legal: %d\n", is_legal(n));

	init();
	
	set_board();

	// check_all_neighbors();
	
	//print_screen();
	//sleep(1);
	//endwin();
	//return 1;

	while(1)
	{
		print_screen();
		update();
	}
	
	
	//print_screen();

	board[max_y-1][max_x-1] = 'o';
	int row = 0;
	//mvprintw(row, 0, board[row]);
	//refresh();

	//sleep(10);
	
	endwin();

	//printf("max_X: %d\nmax_y: %d\n", max_x, max_y);

	return 0;
}

/* Initial setup (ncurses, etc.) */
void init()
{
	// Init curses
	initscr();
	// Don't echo keypresses
	noecho();
	// Don't display cursor
	curs_set(FALSE);

	// Uncomment when you make screen size variable
	//getmaxyx(stdscr, max_y, max_x);

	// TODO: Should probably initialize board here?
}

/* Update board for next life cycle */
void update()
{
	struct node n = {0, 0};
	int live_neighbors;

	for (int i=0; i<max_y; ++i)
	{
		for (int j=0;j<max_x;j++)
		{
			n.x = j;
			n.y = i;
			// Count live neighbors
			live_neighbors = num_neighbors(n);
			// Set next_board accordingly
			// 1. Any live cell with two or three neighbors survives
			if (board[i][j] == 'x' && (live_neighbors == 2 || live_neighbors == 3))
				next_board[i][j] = 'x'; // supose i could just do nothing...?
			// 2. Any dead cell with three living neighbors becomes alive
			else if (board[i][j] == ' ' && live_neighbors == 3)
				next_board[i][j] = 'x';
			// 3. All other live cells die, and all other dead cells stay dead
			else
				next_board[i][j] = ' ';
		}
	}

	// Update the real board
	for (int i=0; i<max_y; ++i)
	{
		for (int j=0;j<max_x;j++)
		{
			board[i][j] = next_board[i][j];
		}
	}
}

/* Returns the number of live neighbors for a given node */
int num_neighbors(struct node n)
{
	int live_neighbors = 0;
	struct node temp = {0, 0};

	//printf("is first neighbor legal: %d\n", is_legal(n.x-1, n.y-1));
	if (is_legal(n.x-1, n.y-1))
	{
		if (board[n.y-1][n.x-1] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x-1, n.y))
	{
		if (board[n.y][n.x-1] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x-1, n.y+1))
	{
		if (board[n.y+1][n.x-1] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x, n.y-1))
	{
		if (board[n.y-1][n.x] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x, n.y+1))
	{
		if (board[n.y+1][n.x] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x+1, n.y-1))
	{
		if (board[n.y-1][n.x+1] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x+1, n.y))
	{
		if (board[n.y][n.x+1] == 'x')
		{
			live_neighbors++;
		}
	}

	if (is_legal(n.x+1, n.y+1))
	{
		if (board[n.y+1][n.x+1] == 'x')
		{
			live_neighbors++;
		}
	}


	return live_neighbors;
}

void test_num_neighbors()
{
	int num_tests = 6;
	struct node tests[num_tests];

	tests[0].x = 0;
	tests[0].y = 0;

	tests[1].x = max_x-1;
	tests[1].y = max_y-1;

	tests[2].x = max_x-1;
	tests[2].y = 0;

	tests[3].x = 0;
	tests[3].y = max_y-1;

	tests[4].x = 10;
	tests[4].y = 10;

	tests[5].x = max_x;
	tests[5].y = max_y;

	for (int i = 0; i < num_tests; i++)
	{
		printf("test%d live neighbors: %d\n", i, num_neighbors(tests[i]));
	}
}

/* Setup initial state of board */
void set_board()
{

	

	// Initialize both boards as empty
	for (int row=0; row<max_y; ++row)
	{
		for (int col=0;col<max_x; ++col)
		{
			board[row][col] = ' ';
			next_board[row][col] = ' ';
		}
	}

	// Set initial state for board

	make_ant();
/*
	for (int i = 3; i < 10; i++)
	{
		//board[5][i] = 'x';

		//board[8][i] = 'x';

		//board[10][i] = 'x';

		if (i != 6)
			board[5][i] = 'x';
	}
*/

/*
	board[1][1] = 'x';
	board[1][2] = 'x';
	board[1][3] = 'x';
*/

/*
	board[3][4] = 'x';
	board[4][4] = 'x';
	board[5][4] = 'x';
*/

/*
	board[3][15] = 'x';
	board[4][15] = 'x';
	board[5][15] = 'x';
*/	
}

void make_ant()
{
	board[0][0] = 'x';
	board[1][1] = board[1][2] = 'x';
	board[2][0] = board[2][1] = 'x';
}

/* Print the contents of board to the screen */
void print_screen()
{
	clear();

	//int row = 0;
	for (int row=0; row<max_y;row++)
		mvprintw(row, 0, board[row]);
	refresh();
	usleep(DELAY);
}

void check_all_neighbors()
{
	struct node n;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			n.x = j;
			n.y = i;
			printf("board[%d][%d] neighbors: %d\n", i, j, num_neighbors(n));
		}
		
	}
}

/* Check to see if coordinates are legal (i.e. the x,y coordinates exist on the board) */
int is_legal(int x, int y)
{
	return (x >= 0 && x < max_x &&
 			y >= 0 && y < max_y);
}
/*
int is_legal(struct node n)
{
	printf("n.x = %d, n.y = %d\n", n.x, n.y);
	printf("1 < 2: %d\n", 1 < 2);

	printf("n.x >= 0: %d\n", n.x >= 0);
	printf("n.x < max_x: %d\n", n.x < max_x);
	printf("n.y >= 0: %d\n", n.y >= 0);
	printf("n.y < max_y: %d\n", n.y < max_y);

	return (n.x >= 0 && n.x < max_x &&
			n.y >= 0 && n.y < max_y);
}
*/