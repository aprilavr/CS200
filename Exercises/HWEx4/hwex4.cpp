#include <iostream>
#include <string>
using namespace std;

// Input/Output functions

string GetHindi( string english )
{
    if(english=="cat")
    {
        return "billee";
    }
    else if (english=="dog")
    {
        return "kutta";
    }
    else if (english=="frog")
    {
        return "medhak";
    }
    else if (english=="rabbit")
    {
        return "khargosh";
    }
    else
    {
        return "word not found";
    }
}

string GetEnglish( string hindi )
{
    if(hindi=="billee")
    {
        return "cat";
    }
    else if(hindi=="kutta")
    {
        return "dog";
    }
    else if (hindi=="medhak")
    {
        return "frog";
    }
    else if (hindi=="khargosh")
    {
        return "rabbit";
    }
    else
    {
        return "word not found";
    }
}

// Menu functions

void DisplayMenu()
{
    cout<<"1. English to Hindi"<<endl;
    cout<<"2. Hindi to English"<<endl;
    cout<<"3. Quit"<<endl;
}

void EnglishToHindi()
{
    string english;
    cout<<"English: ";
    cin>>english;

    string hindi= GetHindi(english);
    cout<<"Hindi: "<<hindi<<endl;
    cout<<endl;
}

void HindiToEnglish()
{
    string hindi;
    cout<<"Hindi: ";
    cin>>hindi;

    string english= GetEnglish(hindi);
    cout<<"English: "<<english<<endl;
    cout<<endl;
}

int main()
{
    bool isDone=false;
    while (isDone==false)
    {
        DisplayMenu();
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            EnglishToHindi();
            break;

        case 2:
            HindiToEnglish();
            break;

        case 3:
            isDone=true;
            break;
        }
    }

    return 0;
}
