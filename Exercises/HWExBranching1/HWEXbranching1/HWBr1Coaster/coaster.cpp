#include <iostream>
#include <string>
using namespace std;
// Boolean variable can only store true or false as a value.
int main()
{
    bool isTallEnoughForRide;
    float feet;

    cout << "What is your height(in feet)? ";
    cin >> feet;

    if(feet>=3)
    {
        isTallEnoughForRide=true;
    }
    else
    {
        isTallEnoughForRide=false;
    }

    if (isTallEnoughForRide==true)
    {
        cout << endl;
        cout << "Permitted to ride the roller coaster.";
    }
    else
    {
        cout << endl;
        cout << "Too short to ride the roller coaster.";
    }

    while (true) {} //temp keep running
    return 0;
}
