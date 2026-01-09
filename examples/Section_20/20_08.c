#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOSS  0
#define WIN	  1

void unfair_play(int sel, int bet, int *lost, int *times);
int fair_play(int sel, int bet, int *lost);

int main(void)
{
	int sel, last_sel, flag, tmp, bet, sum_lost, win_times, lost_times;
	
	flag = 1;
	sum_lost = win_times = lost_times = 0;

	while(1) 
	{
		printf("\nRoulette Game\n");
		printf("--------------\n");

		printf("1. Odd\n");
		printf("2. Even\n");
		printf("3. Play\n");
		printf("4. Stats\n");
		printf("5. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		srand(time(NULL)); 

		switch(sel)
		{
			case 1:
			case 2:
				last_sel = sel; /* last_sel holds the last choice of the player, before the third choice is selected. */
				do
				{
					printf("\nPlace your bet: ");
					scanf("%d", &bet);
				} while(bet <= 0);
			break;

			case 3:
				if(bet == 0)
				{
					printf("No bet is placed\n");
					break;
				}
				if(flag == 1) /* We force the program to play unfair and make the player to lose the first bet. */
				{
					flag = 0;
					unfair_play(last_sel, bet,
						&sum_lost, &lost_times);
				}
				else
				{
					if(bet >= sum_lost) /* If the player bets a larger amount than the money he loses, the program behaves unfair and the player loses. */
						unfair_play(last_sel, bet,
						&sum_lost, &lost_times);
					else
					{
						tmp = fair_play(last_sel, bet, &sum_lost);
						if(tmp == LOSS)
						{
							printf("Sorry, you lost ...\n");
							lost_times++;
						}
						else
						{
							printf("Yeaaaaah, you won ...\n");
							win_times++;
						}
					}
				}
				bet = 0; 
			break;

			case 4:
				printf("\nWin_Times: %d\tLost_Times: %d\tLost_Money: %d euro\n", win_times, lost_times, sum_lost);
			break; 

			case 5:
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	} 
	return 0;
}

/* The program generates a number, so that the player loses. For example, if the player bets on odd numbers the program generates an even number, and vice versa. */
void unfair_play(int sel, int bet, int *lost, int *times)
{
	int num;

	*lost += bet;
	(*times)++;

	while(1)
	{
		num = rand() % 37;
		if(sel == 1) /* The player bets on odd numbers. */
		{
			if((num & 1) == 0) 
			{
				printf("\nThe ball goes to %d. Sorry, you lost ...\n", num);
				return;
			}
		}
		else /* The player bets on even numbers. */
		{
			if((num & 1) == 1)
			{
				printf("\nThe ball goes to %d. Sorry, you lost ...\n", num);
				return;
			}
		}
	}
}

int fair_play(int sel, int bet, int *lost)
{
	int num;

	num = rand() % 37;
	printf("\nThe ball goes to %d. ", num);

	if(num == 0) /* If zero comes out, the player loses. */
	{
		*lost += bet; 
		return LOSS;
	}
	if(sel == 1) /* The player bets on odd numbers. */
	{
		if((num & 1) == 1)
		{
			*lost -= bet; /* If the player wins, the total lost amount is reduced. */
			return WIN;
		}
		else
			*lost += bet; /* If the player loses, the total lost amount is increased. */
	}
	else /* The player bets on even numbers. */
	{
		if((num & 1) == 0)
		{
			*lost -= bet; 
			return WIN;
		}
		else
			*lost += bet;
	}
	return LOSS;
}
