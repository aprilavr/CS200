#include <iostream>
#include <string>
using namespace std;

int main()
{
    int feet;
    int x;

    cout<<"How many feet would you like on your ruler? ";
    cin>>feet;
    cout<<endl;

    for(x=0; x<=(feet*12); x++)
    {
        if (x%12==0)
        {
            cout<<"|";
        }
        else
        {
            cout<<"-";
        }
    }

    return 0;
}
