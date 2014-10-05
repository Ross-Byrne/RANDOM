#include <stdio.h>
#include <stdlib.h>

// The program generates a number between 1 and 20
// the user gets 5 guesses to guess the number
// program says weather num is correct, too high or too low

int main(void)
{
	int rndNum = 0, guess;
	int playerLives = 5; // player only gets 5 guesses
	time_t t;

	// Intializes random number generator
	srand((unsigned)time(&t));

	rndNum = (rand() % 20) + 1; // generates number bewteen 1 and 20

	printf("The aim of the game is to guess number between 1 and 20");

	for (int i = 0; i < 5; i++) // loops 5 times, giving user 5 goes
	{
		printf("\nYou have %d lives left!\n", playerLives);

		printf("\nGuess the number between 1 and 20: ");
		scanf_s("%d", &guess); fflush(stdin);

		if (guess == rndNum) // if you guess right
		{
			printf("\nYou have guessed %d, Which is the right number!", rndNum);
			printf("\nCongratulations! You have won the game!");
			break;
		}
		else if (guess > rndNum) // if guess is higher then number
		{
			printf("\nSorry, your guess %d is too high!", guess);
		}
		else if (guess < rndNum) // if guess is lower then number
		{
			printf("\nSorry, your guess %d is too low!", guess);
		} // if else

		playerLives--; // keeps track of users lives
	} // for

	if (playerLives == 0) // when the player runs out of lives
	{
		printf("\n\nSorry, you are out of lives, better luck next time!");
	} // if

	printf("\n\n\n");
	system("pause");
} // main()