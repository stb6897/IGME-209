#include <iostream>
#include "hangman.h"

int main()
{

	char word[] = "austin";
	char displayWord[] = "______";
	char wrongGuesses[100] = " ";

	char incorrectLetters[] = "";
	int guessesLeft = 7;
	bool gameWon = false;
	printf("Let's play hangman!\n Your word has 6 letters in it!");

	while (guessesLeft > 0) {
		std::cout << guessesLeft;
		std::cout << "\n----------------------------------------------------------------\n";

		std::cout << "Word to solve: " << displayWord << "\n";
		std::cout << "Wrong Guesses: " << wrongGuesses << "\n";
		std::cout << "Guesses left: " << guessesLeft << "\n";

		drawGallows(7 - guessesLeft);
		std::cout << "\n";


		// If you are curious why the buffer is at 1000. There is an issue with cin where if
		// an input is too large, it will change values of other variables.
		std::cout << "\n Guess a letter: ";
		char buffer[1000] = " ";
		std::cin >> buffer;

		// Runs the processGuess function. If the letter is correct we do nothing.
		// Otherwise, we remove a guessesLeft and add the letter to the wrongGuesses string.
		if (!processGuess(buffer[0], word, displayWord) && !strchr(wrongGuesses, buffer[0])) {
			char letter[] = "  ";
			letter[0] = buffer[0];
			strcat_s(wrongGuesses, letter);
			guessesLeft--;
		}

		// If the display word and real word are the same, we break out of the loop.
		if (strcmp(displayWord, word) == 0) {
			gameWon = true;
			break;
		}
	}

	// Prints out the results of the game.
	if (gameWon) {
		printf("Congrats! You got the correct word!\n");
	}
	else {
		printf("Darn! You ran out of guesses!\n");
	}
	return 0;
}