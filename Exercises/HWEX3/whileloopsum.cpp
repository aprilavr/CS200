#include <iostream>
#include <string>
using namespace std;

int main()
{
    int sum=0;
    bool isDone= false;

    while (!isDone)
    {
        int number;

        cout<<"Enter a number: ";
        cin>>number;
        cout<<endl;

        sum=sum+number;
        char letter;
        cout<<"Press (Q) to quit, or press (A) to enter another number. ";
        cin>>letter;
        cout<<endl;

        if(letter=='q')
        {
            isDone=true;
        }

    }
    cout<<"The sum is "<<sum<<endl;

    return 0;
}
