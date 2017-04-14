#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Option
{
    string title;
    int count;
};
struct Poll
{
    string question;
    Option options[4];
};

int main()
{
    Poll myPoll;
    myPoll.question = "What is the best food?";

    myPoll.options[0].title = "Pizza";
    myPoll.options[0].count = 0;

    myPoll.options[1].title = "Veggie Taco";
    myPoll.options[1].count = 0;

    myPoll.options[2].title = "Samosas";
    myPoll.options[2].count = 0;

    myPoll.options[3].title = "Sushi";
    myPoll.options[3].count = 0;
    bool done=false;
    while (!done)
    {
        cout<< myPoll.question;
        cout<<endl;
        for (int i=0; i<4; i++)
        {
            cout<<i<<"\t"<<myPoll.options[i].title<<endl;
        }
        cout<<"4    EXIT"<<endl;
        cout<<"What is your choice?: ";
        int choice;
        cin>>choice;
        if(choice==4)
        {
            done=true;
        }
        else
        {
            myPoll.options[choice].count++;
        }
    }
    ofstream output;
    output.open("results.txt");
    output<<"QUESTION"<<endl<<myPoll.question<<endl;
    for(int i=0; i<4; i++)
    {
        output<<i<<". "<<myPoll.options[i].title<<"..."<<myPoll.options[i].count<<" votes"<<endl;
    }

    output.close();
    return 0;
}
