#include<iostream>
#include<string>
using namespace std;

int main()
{
	float startingWage;
	float percentRaisePerYear;
	float adjustedWage;
	int yearsWorked;

	cout << "What is your starting wage? ";
	cin >> startingWage;
	cout << endl;
	
	cout << "What % of raise per year? >>%";
	cin >> percentRaisePerYear;
	percentRaisePerYear /= 100;
	cout << endl;
	
	cout << "How many years worked? ";
	cin >> yearsWorked;
	cout << endl;

	adjustedWage = startingWage;

	int i;

	for (i = 0; i < yearsWorked; i++)
	{
		adjustedWage += adjustedWage*percentRaisePerYear;
	}

	cout << "Your new wage is $" << adjustedWage << endl;

	while (true); //keeps running

	return 0;
}