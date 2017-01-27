#include <iostream>
#include <string>
using namespace std;

int main()
{
	int countDown = 10;

	while (countDown > 0)
	{
		cout << countDown << " ";
		countDown--;
	}

	cout << endl;
	cout << "done!" << endl;

	while (true); //keeps running

	return 0;
}