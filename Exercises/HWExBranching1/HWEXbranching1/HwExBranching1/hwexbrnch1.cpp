#include <iostream>
#include <string>
using namespace std;
//Age can be 0-12 or 13 and greater
//Ticket price can be only 5 or 7
int main()
{
    int age;
    float ticketPrice;

    cout << "Age? ";
    cin >> age;

    if (age<13){
        ticketPrice = 5.00;
    }
    else{
        ticketPrice = 7.00;
    }

    cout << endl;
    cout << "Ticket Price: $"<< ticketPrice<<endl;

    while (true) {} //temp- don't let program quit

    return 0;
}
