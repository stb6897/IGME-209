#include "hangman.h";
#include <iostream>
#include <cstring>


// I decided that it would be easier to have the hangman text be hardcoded from an array.
const char* stages[7] = {
	 "|     |     |\n|           |\n|           |\n|           |\n",
	 "|     |     |\n|     0     |\n|           |\n|           |\n",
	 "|     |     |\n|     0     |\n|     |     |\n|           |\n",
	 "|     |     |\n|     0     |\n|   --|     |\n|           |\n",
	 "|     |     |\n|     0     |\n|   --|--   |\n|           |\n",
	 "|     |     |\n|     0     |\n|   --|--   |\n|    /      |\n",
	 "|     |     |\n|     0     |\n|   --|--   |\n|    / \\    |\n",
};

void drawGallows(int remainingGuesses) {
	std::cout << stages[remainingGuesses];
}

// Loops through the word to see if there are any matches.
// If so, display at the current index is replaced with the letter.
// We also set match to true so that we know it is a correct guess.
bool processGuess(char guess, char word[], char display[]) {
	bool match = false;
	int wordSize = strlen(word);
	for (int i = 0; i < wordSize; i++)
	{
		if (word[i] == guess) {
			display[i] = guess;
			match = true;
		}
	}
	return match;
}