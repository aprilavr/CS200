#include <iostream>
#include <string>
using namespace std;

struct College
{
	string name;
	string state;
};

struct Student
{
	string name;
	College* ptrSchool;
};

int main()
{
	College colleges[3];
	colleges[0].name = "JCCC";
	colleges[1].name = "MCCKC";
	colleges[2].name = "KCKCC";
	colleges[0].state = "KS";
	colleges[1].state = "MO";
	colleges[2].state = "KS";

	Student students[5];

	for (int i = 0; i < 5; i++)
	{
		cout <<"Student "<< i << endl;
		cout << "Student name?: ";
		cin >> students[i].name;

		for (int i = 0; i < 3; i++)
		{
			cout <<i<< " "<< colleges[i].name<<" "<< colleges[i].state << endl;
		}
		cout << "Select college(enter number): ";
		int choice;
		cin >> choice;
		students[i].ptrSchool = &colleges[choice];

		
	}

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].name << " ID number: " << i << " College: " << students[i].ptrSchool->name <<" "<< students[i].ptrSchool->state << endl;
	}

	while (true);


	return 0;



}