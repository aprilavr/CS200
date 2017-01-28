#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number;
    string romanNumeral;

    while (true)
    {   cout<<"Enter a number between 1 and 5: ";
        cin>>number;
        cout<<endl;

        switch(number)
        {
        case 1:
            romanNumeral="I";
            break;

        case 2:
            romanNumeral="II";
            break;

        case 3:
            romanNumeral="III";
            break;

        case 4:
            romanNumeral="IV";
            break;

        case 5:
            romanNumeral="V";
            break;

        default:
            cout<<"Invalid Entry"<<endl;
            break;
        }

        cout<<"Roman Numeral is: "<<romanNumeral<<endl;
        cout<<endl;

    }

    return 0;
}
