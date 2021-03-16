#include <stdio.h>

int main() {
	printf("Hello world!\n");

	// Seconds in December calculation
	int daysInDecember = 31;
	int secondsInDecember = (daysInDecember * 24 * 60 * 60);

	// Circle
	double pi = 3.14159;
	double radius = 6.2;
	double area = pi * (radius * radius);

	printf("There are %i days in December, which means that there are %i seconds.\n", daysInDecember, secondsInDecember);
	printf("The area of a circle with %f radius is %f \n", radius, area);
	// It truncates the 0.5 to just 0.
	printf("Int division test of 1/2 gets %i", (1 / 2));



	return 0;
}