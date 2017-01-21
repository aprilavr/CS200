#include <iostream>
#include <string>
using namespace std;
//for 'a' and 'A', displays "Second comes first"
//in ascii, uppercase have lower values.
int main()
{
    char letter1;
    char letter2;

    //user inputs letters
    cout<< "Enter a letter: ";
    cin >> letter1;
    cout<<endl;
    cout<< "Enter a second letter: ";
    cin >> letter2;

    if(letter1<letter2)
    {
        cout<<endl;
        cout<< "First letter comes first.";
    }
    else
    {
        cout<<endl;
        cout<< "Second letter comes first.";
    }

    while (true) {}//temp- keeps running
    return 0;
}
