#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void show_board(int c[][COLS], int s[][COLS]);
void sel_card(int c[][COLS], int s[][COLS], int *row, int *col);

int main(void)
{
	int i, j, m, r, c, r2, c2, cnt, cards[ROWS][COLS], status[ROWS][COLS] = {0}; /* The status array indicates if a card faces up or down (0 is for down). */
	cnt = 0; /* This variable counts the number of the faced up cards. */
	for(i = r = 0; i < ROWS; i++) /* Assign the values 1 to 8, sequentially. */
	{
		for(j = 0; j < COLS; j+=2)
		{
			cards[i][j] = cards[i][j+1] = r+1;
			r++;
		}
	}
	/* Now, shuffle the cards. */
	srand(time(NULL));
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			c = cards[i][j];
			m = rand()%ROWS;
			r = rand()%COLS;
			cards[i][j] = cards[m][r];
			cards[m][r] = c;
		}
	}
	show_board(cards, status);
	m = 0; 
	while(cnt != ROWS*COLS) /* The game ends when all cards are faced up. */
	{
		sel_card(cards, status, &r, &c);
		printf("Card_1 = %d\n", cards[r][c]);
		
		sel_card(cards, status, &r2, &c2);
		printf("Card_2 = %d\n", cards[r2][c2]);

		for(i = 0; i < 18; i++) /* Blank line to delete history and make harder for the player to remember the card positions. */
			printf("\n");

		if(cards[r][c] == cards[r2][c2])
		{
			printf("Cards matched !!!\n");
			cnt += 2;
		}
		else
		{
			printf("Sorry. No match !!!\n");
			status[r][c] = status[r2][c2] = 0; /* Reset the cards to face down condition. */
		}
		m++;
		show_board(cards, status);
	}
	printf("Congrats: You did it in %d tries\n", m);
	return 0;
}

void show_board(int c[][COLS], int s[][COLS])
{
	int i, j;
	
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			if(s[i][j] == 1)
				printf("%d ", c[i][j]);
			else
				printf("* ");
		}
		printf("\n");
	}
}

void sel_card(int c[][COLS], int s[][COLS], int *row, int *col)
{
	while(1)
	{
		printf("Enter row and column: ");
		scanf("%d %d", row, col);
		(*row)--; /* Subtract 1, because the indexing of the array starts from 0. */
		(*col)--;
		if(*row >= ROWS  || *row < 0 || *col >= COLS || *col < 0)
		{
			printf("Out of bound dimensions\n");
			continue;
		}
		if(s[*row][*col] == 1)
		{
			printf("Error: This card is already flipped\n");
			continue;
		}
		s[*row][*col] = 1; /* Change the card position to face up. */
		return;
	}
}
