#include <iostream>
#include <string>
using namespace std;

int main()
{
	float battery;

	cout << "What is your current battery charge?";
	cin >> battery;
	cout << endl;

	if (battery >= 75)
	{
		cout << "[****]";
	}
	else if (battery >= 50)
	{
		cout << "[*** ]";
	}
	else if (battery >= 25)
	{
		cout << "[**  ]";
	}
	else
	{
		cout << "[*   ]";
	}
	
	while (true);
	return 0;

}