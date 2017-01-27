#include <iostream>
#include <string>
using namespace std;

int main()
{
	int counter = 0;

	while (counter <= 20)
	{
		cout << counter << " ";
		counter = counter + 5;
	}

	cout << endl;
	cout << "Done!" << endl;

	while (true); //keeps running

	return 0;
}