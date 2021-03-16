#include <iostream>
using namespace std;

void changeVariable(int variable);
void changePointer(int* variable);
int getLengthArray(int arr[], int size);
int getLengthPointer(int* arr, int size);
int* createStackArray();
int* createHeapArray(const int size);
int main()
{
	cout << "-----------------------------------------------------------\n";

	// Part 1
	int testInt = 1;
	std::cout << "testInt is currently: " << testInt << "\n";
	changeVariable(testInt);
	std::cout << "testInt is currently: " << testInt << "\n";
	changePointer(&testInt);
	std::cout << "testInt is currently: " << testInt << "\n";
	// In this scenario we are only going to see a change from testInt by the second function.
	// changeVariable makes a copy of testInt while changePointer gets the actually adress of testInt and alters it.

	cout << "-----------------------------------------------------------\n";

	// Part 2
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,-1 };
	int size = sizeof(arr) / sizeof(*arr);
	int* arrPointer = arr;

	std::cout << "Looping with ints for array: " << getLengthArray(arrPointer, size) << endl;
	std::cout << "Looping with pointers for array: " << getLengthPointer(arrPointer, size) << endl;
	// These work the same in terms of the array refrence. As int arr[] is basically int *arr.
	// This might not be required, but I looped the second function using pointers.

	cout << "-----------------------------------------------------------\n";

	// Part 3
	int* stackArr = createStackArray();
	int* heapArr = createHeapArray(5);

	// Seems like for the stack array, we are out of scope.
	// Which means we are now grabbing data we shouldn't have
	// access to.
	cout << "Stack Array:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << stackArr[i] << ", ";
	}
	cout << endl;
	cout << "Heap Array:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << heapArr[i] << ", ";
	}
	cout << endl;
	delete heapArr;
	heapArr = nullptr;
}


void changeVariable(int variable) {
	variable = 23;
	std::cout << "Inside changeVariable(), variable's value is now: " << variable << "\n";
}
void changePointer(int* variable) {
	(*variable) = 24;
	std::cout << "Inside changePointer(), variable's pointer at address: " << variable << " is now: " << *variable << "\n";
}


int getLengthArray(int arr[], int size) {
	int numberBeforeTerm = 0;
	// looping with ints
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == -1) {
			break;
		}
		numberBeforeTerm++;
	}
	return numberBeforeTerm;
}
int getLengthPointer(int* arr, int size) {

	int* end = arr + size;
	int numberBeforeTerm = 0;
	// looping with pointers
	for (int* nums = arr; nums < end; nums++)
	{
		if (*nums == -1) {
			break;
		}
		numberBeforeTerm++;
	}
	end = nullptr;
	return numberBeforeTerm;
}


int* createStackArray() {
	int arr[5] = { 0,1,2,3,4 };
	return arr;
}
int* createHeapArray(const int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	return arr;
}