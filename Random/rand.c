#include <stdio.h>
#include <stdlib.h>

// The program generates a number between 1 and 20
// the user gets 5 guesses to guess the number
// program says weather num is correct, too high or too low

int main(void)
{
	// Intializes random number generator
	srand(time(NULL));

	printf("%d\n", (rand() % 20)+1);

	printf("\n\n\n");
	system("pause");

} // main()