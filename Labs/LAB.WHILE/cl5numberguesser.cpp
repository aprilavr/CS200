#include <iostream>
#include <string>
using namespace std;

int main()
{
	int secretNumber = 25;
	int playerGuess;

	do
	{
		cout << "Enter a number: ";
		cin >> playerGuess;
		cout << endl;

		if (playerGuess < secretNumber)
		{
			cout << "Too low!" << endl;
		}
		else if (playerGuess > secretNumber)
		{
			cout << "Too high!" << endl;
		}
	} while (playerGuess != secretNumber);

	cout << "You win!" << endl;

	while (true); //keeps running

	return 0;
}