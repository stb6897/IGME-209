
#include <iostream>
#include <cstring>


int main()
{
	// First C string
	char super[100] = "supercalifragilistic";
	int superLength = strlen(super);

	// Second C string
	char expi[] = "expialidocious";

	// Combined C string
	strcat_s(super, expi);


	// Loops and counts up how many times the letter "I" occurs.
	int combinedLength = strlen(super);
	int amountOfI = 0;
	for (int i = 0; i < combinedLength; i++)
	{
		if (super[i] == 'i') {
			amountOfI++;
		}
	}

	// Print out our results
	std::cout << "Length of first C string: " << superLength << "\n";
	std::cout << "The combined string is: " << super << "\n";
	std::cout << "The amount of times the letter 'I' occurs is: " << amountOfI;
}