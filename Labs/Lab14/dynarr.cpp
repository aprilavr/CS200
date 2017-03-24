#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Person
{
	string name;
	Person* ptrFriend;
};
struct Employee
{
	string name;
};
struct Manager
{
	string name;
	Employee* employees;
	int employeeCount;
};

void ExerciseOne()
{
	int* myInt;
	string* myStr;
	float* myFloat;

	myInt = new int;
	myStr = new string;
	myFloat = new float;

	*myInt = 20;
	*myStr = "April";
	*myFloat = 199.99;

	cout << *myInt << "\t" << *myStr << "\t" << *myFloat << endl;

	delete myInt;
	delete myStr;
	delete myFloat;
}

void ExerciseTwo()
{
	Person* personA = new Person;
	Person* personB = new Person;
	Person* personC = new Person;

	(*personA).name = "James";
	(*personB).name = "Steve";
	(*personC).name = "Mandy";

	(*personA).ptrFriend = personB;
	(*personB).ptrFriend = personC;
	(*personC).ptrFriend = personA;

	cout << "Person A: " << (*personA).name << ", Friend: " << (*personA).ptrFriend->name << endl;
	cout << "Person B: " << (*personB).name << ", Friend: " << (*personB).ptrFriend->name << endl;
	cout << "Person C: " << (*personC).name << ", Friend: " << (*personC).ptrFriend->name << endl;

}
void ExerciseThree()
{
	cout << "Number of Lotto balls?: ";
	int size;
	cin >> size;

	int* lottoNumbers;
	lottoNumbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		lottoNumbers[i] = rand()%100;
		cout << lottoNumbers[i] << "\t";
	}
	delete[]lottoNumbers;
}
void ExerciseFour()
{
	string names[6]{ "Dane", "Brent", "Crystal", "Jason", "Amanda", "Charlie" };
	cout << endl;
	cout << "How many managers?: ";
	int managerCount;
	cin >> managerCount;
	Manager* managers = new Manager[managerCount];

	for (int i = 0; i < managerCount; i++)
	{
		managers[i].name = names[rand() % 6];
		managers[i].employeeCount = rand() % 3;
		if (managers[i].employeeCount > 0)
		{
			managers[i].employees = new Employee[managers[i].employeeCount];
			for (int m = 0; m < managers[i].employeeCount; m++)
			{
				managers[i].employees[m].name = names[rand() % 6];
			}
		}
	}
	for (int m = 0; m < managerCount; m++)
	{
		cout << endl;
		cout << "Manager:           "
			<< managers[m].name << endl;
		cout << "Underling Count:   "
			<< managers[m].employeeCount << endl;

		for (int e = 0; e < managers[m].employeeCount; e++)
		{
			cout << "\t" << e + 1 << ". "
				<< managers[m].employees[e].name << endl;
		}
	}
}
int main()
{
	srand(time(NULL));
	ExerciseOne();
	ExerciseTwo();
	ExerciseThree();
	ExerciseFour();

	while (true);

	return 0;
}