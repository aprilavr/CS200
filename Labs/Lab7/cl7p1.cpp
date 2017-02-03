#include<iostream>
#include<string>
using namespace std;

// Input: A percent value (0% - 100%, no percent sign though)
// Output: The decimal equivalent (0.0 - 1.0)
float PercentToDecimal(float percent)
{
	float decimal = percent / 100;
	return decimal;
}

int main()
{
	float a, b, c;

	a = PercentToDecimal(50);
	b = PercentToDecimal(12.5);
	c = PercentToDecimal(99.9);

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;

	while (true); //keeps running

	return 0;
}