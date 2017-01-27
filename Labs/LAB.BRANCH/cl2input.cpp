#include <iostream>
#include <string>
using namespace std;

int main()
{
	int choice;

	cout << "What is your favorite fruit?" << endl;
	cout << "i. Apple" << endl;
	cout << "ii. Banana" << endl;
	cout << "iii.Pear" << endl;
	cout << "iv.Strawberry" << endl;
	cin >> choice;

	if (choice < 1 || choice>4)
	{
		cout << "Invalid Choice";
	}
	else
	{
		cout << "Good choice!";
	}

	while (true); //keeps running

	return 0;
}