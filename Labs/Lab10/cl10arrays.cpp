#include <iostream>
#include <string>
using namespace std;

void practiceA()
{
    string names[5]= {"Xia", "Shang", "Zhou", "Qin", "Han"};
    cout<<names[0]<<endl;
    cout<<names[1]<<endl;
    cout<<names[2]<<endl;
    cout<<names[3]<<endl;
    cout<<names[4]<<endl;
}
void practiceB()
{
    string names[5]= {"Xia", "Shang", "Zhou", "Qin", "Han"};
    int index=0;
    int arraySize=5;
    while (index<arraySize)
    {
        cout<<names[index]<<endl;
        index++;
    }
}
void practiceC()
{
    string items[3];
    float prices[3];
    int arraySize=3;
    int itemCount=0;
    while (itemCount<arraySize)
    {
        cout<<"\nEnter item name: ";
        cin>>items[itemCount];
        cout<<"\nEnter item price: ";
        cin>>prices[itemCount];
        itemCount++;
    }
    int counter=0;
    while (counter<itemCount)
    {
        cout<<"Item #"<<counter<<": "<<items[counter]<<" "<<prices[counter]<<endl;
        counter++;
    }
}
void practiceD()
{
    string letters[5] = { "A", "B", "C", "D", "E" };
    for (int i=0; i<5; i++)
    {
        cout<<letters[i]<<endl;
    }
}
void practiceE()
{
      string items[3];
    float prices[3];
    int arraySize=3;
    int itemCount=0;
    for(itemCount=0; itemCount<arraySize; itemCount++)
    {
        cout<<"\nEnter item name: ";
        cin>>items[itemCount];
        cout<<"\nEnter item price: ";
        cin>>prices[itemCount];
    }
    for (int counter=0; counter<itemCount; counter++)
    {
        cout<<"Item #"<<counter<<": "<<items[counter]<<" "<<prices[counter]<<endl;
    }
}
void practiceF()
{
    string cities[20];
    int arraySize = 20;
    cities[0] = "Lee's Summit";
    cities[1] = "Raytown";
    cities[2] = "Independence";
    cities[3] = "Belton";
    int itemCount = 4;
    for (int i=0; i<itemCount; i++)
    {
        cout<<cities[i]<<endl;
    }
}
int main()
{
    practiceA();
    practiceB();
    practiceC();
    practiceD();
    practiceE();
    practiceF();

    return 0;
}


