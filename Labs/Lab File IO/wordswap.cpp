#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    cout<<"What word are you searching for?: ";
    string word;
    cin>>word;

    cout<<"What word would you like to replace it with?: ";
    string wordNew;
    cin>>wordNew;
    string buffer;

    ifstream input;
    input.open("story_original.txt");
    ofstream output;
    output.open("story_modified.txt");

    while(input>>buffer)
    {
        if(buffer==word)
        {
            output<<wordNew<<" ";
        }
        else
        {
            output<<buffer<<" ";
        }
    }
    input.close();
    output.close();

    return 0;
}
