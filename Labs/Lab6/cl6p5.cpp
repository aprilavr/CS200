#include<iostream>
#include<string>
using namespace std;

int main()
{	
	float sum = 0;
	int i;

	for (i = 0; i <=10; i++)
	{
		sum = i + sum;
	}

	cout << sum << endl;
	
	while (true); //keeps running


	return 0;
}