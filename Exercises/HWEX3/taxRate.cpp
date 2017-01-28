#include <iostream>
using namespace std;

int main()
{
    float price;
    string city;
    float tax;

    cout<<"What is the item price?";
    cin>>price;
    cout<<endl;

    cout<<"What city do you live in?";
    cin>>city;
    cout<<endl;

    if (city=="Olathe")
    {
        tax=0.065;
    }
    else if (city=="OverlandPark")
    {
        tax=0.0935;
    }
    else if (city=="Raytown")
    {
        tax=0.08225;
    }
    else if (city=="Independence")
    {
        tax=0.07725;
    }
    else
    {
        tax=0.08;
    }

    float total= price+(price*tax);

    cout<<"Total price is $"<<total<<"."<<endl;

    return 0;
}
