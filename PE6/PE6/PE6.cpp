#include <iostream>
#include <time.h>
void generateRandom(int numberOfRandoms);
char* reverseString(char inputString[]);
int main()
{
	//generateRandom(30);
	std::cout << "Please input a string: ";
	char userInput[256];
	std::cin >> userInput;
	std::cout << "New String:" << reverseString(userInput);
	return 0;
}

void generateRandom(int numberOfRandoms) {
	srand(time(NULL));
	for (int i = 0; i < numberOfRandoms; i++) {
		int randomNumber = rand();
		std::cout << "Random #" << i << " is :" << randomNumber << "\n";
	}
}

char* reverseString(char inputString[]) {
	// newString being set to "" makes it so that you cannot set an index at length - i to the char c.
	// A fix you can apply is to just add a space to the string. So newString = " ". 
	// It gets rid of the null terminator at newString[0].
	char newString[256] = " ";
	int length = strlen(inputString);
	for (int i = 0; i < length; i++)
	{
		char c = inputString[i];
		newString[length - i] = c;
	}
	strcpy_s(inputString, 128, newString);
	return inputString;
}