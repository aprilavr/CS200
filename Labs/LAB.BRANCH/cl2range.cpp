#include <iostream>
#include <string>
using namespace std;

int main()
{
	float x1, x2;
	x1 = 5.00;

	cout << "Where is x2?";
	cin >> x2;
	cout << endl;

	if ((x1 - 5) <= x2 && (x1 + 5) >= x2)
	{
		cout << "Within 5 units of x1!";
	}
	else
	{
		cout << "Too far away";
	}

	while (true); //keepsrunning

	return 0;
}