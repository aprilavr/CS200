#include <iostream>
#include <string>
using namespace std;

int main()
{
	float studentPoints, totalPoints;


	cout << "What was your score?";
	cin >> studentPoints;
	cout << endl;
	cout << "What was the total points?";
	cin >> totalPoints;

	float percent = (studentPoints / totalPoints) * 100;
	cout << "Score: " << percent << "% \t";



	if (percent >= 70)
	{
		cout << "PASS" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}

	while (true); 


	return 0;
}