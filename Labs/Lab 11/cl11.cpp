#include <iostream>
#include <string>
using namespace std;

void exerciseOne()
{
	int integer = 10;
	string word = "string";
	float floatNum = 2.1;

	cout << &integer << "=" << integer << endl;
	cout << &word << "=" << word << endl;
	cout << &floatNum << "=" << floatNum << endl;
}

void exerciseTwo()
{
	int array[5];

	for (int i = 0; i < 5; i++)
	{
		array[i] = i;
	}
	cout << "Array address:" << array << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << "Item " << j << " address:" << &array[j] << endl;
	}
}

void exerciseThree()
{
	int integer = 10;
	string word = "string";
	float floatNum = 2.1;

	int* ptrInt = &integer;
	string* ptrString = &word;
	float* ptrFloat = &floatNum;

	cout << ptrInt << "=" << *ptrInt << endl;
	cout << ptrString << "=" << *ptrString << endl;
	cout << ptrFloat << "=" << *ptrFloat << endl;
}

void exerciseFour()
{
	char choice;
	cout << "[i]nteger, [f]loat, [b]oolean, or [d]ouble? ";
	cin >> choice;
	
	if (choice == 'i')
	{
		int choiceI;
		int* ptrInt = &choiceI;
		cout << "Integer size: " << sizeof(choiceI) << ", address: " << ptrInt << endl;
	}
	else if (choice == 'f')
	{
		float choiceF;
		float* ptrFloat = &choiceF;
		cout << "Float size: " << sizeof(choiceF) << ", address: " << ptrFloat << endl;
	}
	else if (choice == 'b')
	{
		bool choiceB;
		bool* ptrBool = &choiceB;
		cout << "Boolean size: " << sizeof(choiceB) << ", address: " << ptrBool << endl;
	}
	else if (choice == 'd')
	{
		double choiceD;
		double* ptrDouble = &choiceD;
		cout << "Double size: " << sizeof(choiceD) << ", address: " << ptrDouble << endl;
	}
	else
	{
		cout << "invalid choice" << endl;
	}
}

void exerciseFive()
{
	float priceHamburger = 4.99;
	float priceFries = 1.99;
	float priceSalad = 3.99;


	char choice;
	cout << "[h]amburger, [f]ries, or [s]alad?: ";
	cin >> choice;

	float* ptrPrice;
	float taxAmt = 0.065;

	if (choice == 'h')
	{
		ptrPrice = &priceHamburger;

	}
	else if (choice == 'f')
	{
		ptrPrice = &priceFries;

	}
	else if (choice == 's')
	{
		ptrPrice = &priceSalad;

	}
	else
	{
		ptrPrice = 0;
	}
	cout << "Original price: $" << *ptrPrice << endl;
	cout << "With tax price: $" << *ptrPrice + (*ptrPrice * taxAmt) << endl;

}

void exerciseSix()
{
	string students[3];
	students[0] = "Steve";
	students[1] = "Bob";
	students[2] = "Fred";

	string* ptrStudent;
	int choice;
	cout << "0, 1, or 2?: ";
	cin >> choice;


	if (choice == 0)
	{
		ptrStudent = &students[0];
	}
	else if (choice == 1)
	{
		ptrStudent = &students[1];
	}
	else if (choice == 2)
	{
		ptrStudent = &students[2];
	}
	else
	{
		ptrStudent = 0;
	}
	cout << "New name: ";
	cin >> *ptrStudent;

	for (int i = 0; i < 3; i++)
	{
		cout << "Student " << i <<" = " << students[i] << endl;
	}
}

int main()
{
	exerciseOne();
	exerciseTwo();
	exerciseThree();
	exerciseFour();
	exerciseFive();
	exerciseSix();

	while (true);

	return 0;

}