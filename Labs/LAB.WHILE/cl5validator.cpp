#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please enter a number between 0 and 5: ";

	int choice;
	cin >> choice;
	cout << endl;

	while (choice < 0 || choice>5)
	{
		cout << "Invalid entry. Try again: ";
		cin >> choice;
		cout << endl;
	}

	cout << "Thank you." << endl;

	while (true);

	return 0;
}