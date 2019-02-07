#include <ctime>
#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::time;

int main() {
	// This describes the size of the grid
	int highNmbr = 64;
	int lowNmbr = 1;
	// Generates seed of rand
	srand(time(0) - 64);
	//Generates a random number
	int number = ((rand() % 64) + 1);
	// Binary Number
	int binaryNum = 0;
	// Human Number
	int humanNum = 0;
	// Guessed number
	int guess;

	// displays welcome message and pauses so the user can read
	cout << "Welcome to Project Skynet: HK-Aerial \n";
	system("pause");
	cout << "\n";

	// This block makes up the binary functions
	while (highNmbr >= lowNmbr) {
		// Binary searches 
		int Bsearch = ((highNmbr - lowNmbr) / 2) + lowNmbr;
		if (Bsearch < number) {
			// This increments the binary number
			++binaryNum;
			// Once incremented, perform this.
			lowNmbr = lowNmbr + Bsearch;
		}
		if (Bsearch > number) {
			++binaryNum;
			highNmbr = highNmbr - Bsearch;
		}
		// Afterwards, run this and see if it is correct. 
		else if (Bsearch = number) {
			// declares the seed of rand()
			srand(time(0) - 64);
			// Calculates random number
			int number = ((rand() % 64) + 1);
			// User imputs their guesses
			cout << " To find the correct location, please guess a number between 1 and 64. ";
			cin >> guess;
			while (guess != number)
			{	
				// if guess is too low
				 if (guess < number)
				{
					++humanNum;
					cout << "Guessed number too low, try again: ";
					cin >> guess;

				}
				// if the guess was too high
				 else if (guess > number)
				 {
					 ++humanNum;
					 cout << "Guessed number too high, try again: ";
					 cin >> guess;
				 }
			}
			// if the guessed number is correct, run this
			if (guess == number)
			{
				++humanNum;
				// Displays the result of the searches
				cout << "Correct! \n";
				cout << humanNum << " Human search(s) preformed \n";
				cout << binaryNum << " Binary search(s) preformed \n";
				cout << number << " linear search(s) preformed \n";
				// pauses so user can read
				system("pause");
				cout << "\n";
			}	
		}
	}
	return 0;
}