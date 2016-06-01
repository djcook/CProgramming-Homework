/*
Program Name: battleship.c
Programmer: Dylan Cook
Class: CS 3335 A
HW: 04
Problem: 01
Date: 11/4/15
*/

/*This program is made to simulate a 1-D game of battleship*/
#include <stdio.h>
#include <time.h>

void printBoard(char *h, char *c)
{
	int x;

	//print boards
	printf("Human Board: \n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for(x = 0; x < 10; x++)
	{
		printf("%c ", h[x]);
	}

	printf("\n\nComputer Board: \n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for(x = 0; x < 10; x++)
	{
		printf("%c ", c[x]);
	}
	printf("\n\n");
}

void setBoard(char *h)
{
	int x;
	int pos1; //position 1 for ship
	int pos2; //position 2 for ship

	//initialize array with *
	for(x = 0; x < 10; x++)
	{
		h[x] = '*';
	}

	printf("Enter 1st position: ");
	scanf("%d", &pos1);

	h[pos1] = 'S';

	printf("Enter 2nd position: ");
	scanf("%d", &pos2);
	
	//checks to make sure ships are beside each other
	while((pos2 != pos1 + 1) && (pos2 != pos1 - 1))
	{
		if(pos1 == 0)
		{
			printf("New 2nd position: 1\n");
			pos2 = 1;
		}
		else if(pos1 == 9)
		{
			printf("New 2nd position: 8\n");
			pos2 = 8;
		}
		else
		{
			printf("Please enter new 2nd position: ");
			scanf("%d", &pos2);
		}
	}
	h[pos2] = 'S';
	printf("\n");
}

void setComputerBoard(char *c)
{
	int x;
	int pos1; //position 1 for ship
	int pos2; //postion 2 for ship

	//initialize array with *
	for(x = 0; x < 10; x++)
	{
		c[x] = '*';
	}

	pos1 = rand() % 10;
	c[pos1] = 'S';

	pos2 = rand() % 10;

	//checks to make sure ships are beside each other
	while((pos2 != pos1 + 1) && (pos2 != pos1 - 1))
	{
		if(pos1 == 0)
		{
			pos2 = 1;
		}
		if(pos2 == 9)
		{
			pos2 = 8;
		}
		else
		{
			pos2 = rand() % 10;
		}
	} 
	c[pos2] = 'S';
}

int playGame(char *h, char *c)
{
	//computer/human count and guess variables
	int hCount = 0;
	int cCount = 0;
	int cGuess = 0;
	int hGuess = 0;
	int x;
	
	/*plays game ending it if human/computer
	destroyed both ships*/ 
	while(hCount != 2 && cCount != 2)
	{
		//Computer guess
		cGuess = rand() % 10;

		/*Making sure computer doesnt guess 
		something it previously guessed*/
		while(h[cGuess] == 'H' || h[cGuess] == 'M')
		{
			cGuess = rand() % 10;
		}
		printf("Computer guesses: %d\n", cGuess);

		//Checks if computer hit or miss
		if(h[cGuess] == 'S')
		{
			printf("HIT!\n\n");
			h[cGuess] = 'H';
			cCount++;
		}
		else 
		{
			printf("MISS!\n\n");
			h[cGuess] = 'M';
		}

		printBoard(h, c);

		/*stops human from taking a 
		turn if computer already won*/
		if(cCount == 2)
		{
			break;
		}

		//human guess
		printf("Enter guess: ");
		scanf("%d", &hGuess);
		printf("You guessed: %d\n", hGuess);

		//check if hit or miss
		if(c[hGuess] == 'S')
		{
			printf("HIT!\n\n");
			c[hGuess] = 'H';
			hCount++;
		}
		else 
		{
			printf("MISS!\n\n");
			c[hGuess] = 'M';
		}
		printBoard(h, c);
	}
	//returns winner
	if(hCount == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char array1[10];
	char array2[10];

	char *human;
	human = array1;

	char *computer;
	computer = array2;

	srand(time(NULL));

	setBoard(human);
	setComputerBoard(computer);
	int winner = playGame(human,computer);

	if(winner==0)
	{
		printf("Computer wins!\n");
	}
	 else
	{
		printf("Human Wins!\n");
	}
}

