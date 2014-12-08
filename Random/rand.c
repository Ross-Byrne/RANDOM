#include <stdio.h>
#include <stdlib.h>

#define TURNS 5

// The program generates a number between 1 and 20
// the user gets 5 guesses to guess the number
// program says weather num is correct, too high or too low

int main(void)
{
	int endGame = 0; //used to end game loop

	int rndNum = 0, guess;
	int playerLifes = TURNS; // player only gets 5 guesses
	time_t t;
	
	// Intializes random number generator
	srand((unsigned)time(&t));

	while (endGame != 99) // type 99 to exit
	{
		rndNum = (rand() % 20) + 1; // generates number bewteen 1 and 20

		playerLifes = TURNS; // resets lifes back to 5

		printf("\nThe aim of the game is to guess a number between 1 and 20");
		printf("\nType 99 to exit the game\n");

		for (int i = 0; i < TURNS; i++) // loops 5 times, giving user 5 goes
		{
			if (playerLifes > 1) // to change lifes to life when only one is left
			{
				printf("\nYou have %d lifes left!\n", playerLifes);
			}
			else { printf("\nYou have %d life left!\n", playerLifes); }

			printf("\nGuess the number between 1 and 20: ");
			scanf_s("%d", &guess); fflush(stdin);
			
			if (guess == 99)		// ends the game when you type 99
			{
				endGame = guess;	// equals endGame to 99 to exit while loop
				break;				// exits for loop so the while loop can see endGame == 99 and stop running
			}
			else if (guess > rndNum) // if guess is higher then number
			{
				printf("\nSorry, your guess %d is too high!", guess);
			}
			else if (guess < rndNum) // if guess is lower then number
			{
				printf("\nSorry, your guess %d is too low!", guess);
			}
			else if (guess == rndNum) // if you guess right
			{
				printf("\n\nYou have guessed %d, Which is the right number!", rndNum);
				printf("\nCongratulations! You have won the game!\n\n");
				break;
			}// if else

			playerLifes--; // keeps track of users lifes
		} // for
		
		if (playerLifes == 0) // when the player runs out of lifes
		{
			printf("\n\nYou are out of lifes, better luck next time!\n\n");
		} // if
	} // while

	printf("\n\nThank you for playing!");

	printf("\n\n\n");
	system("pause");
} // main()