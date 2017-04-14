/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
#include <string>
using namespace std;


/* Setup() - 	Create the list of locations
 *              Allocate needed memory
 * */
void Program::Setup()
{
    //    Location* ptrCurrentLocation;
    //Location* ptrEndLocation;
   //Location* locationList;
    // This is called automatically when the program begins

    locationList= new Location[6];
    locationList[0].name= "Dungeon";
    locationList[0].description= "No way out!";
    locationList[1].name= "Creepy Old Mansion";
    locationList[1].description="A door leads inside, it looks eerily similar to something from Edgar Allan Poe...";
    locationList[2].name= "Grand Foyer";
    locationList[2].description= "This room was once elegant and grand, but now just vastly empty";
    locationList[3].name= "Kitchen";
    locationList[3].description= "Home to old cookware, wood stoves, and lots of dust and cobwebs!";
    locationList[4].name= "Study";
    locationList[4].description= "Nothing beats the smell of old leather bound books";
    locationList[5].name= "Dining Hall";
    locationList[5].description= "A grand large table that once seated dozens of notable people, all now long deceased";

    locationList[1].ptrToNorth= nullptr;
    locationList[1].ptrToSouth= nullptr;
    locationList[1].ptrToWest= nullptr;
    locationList[1].ptrToEast= &locationList[2];

    locationList[2].ptrToNorth= nullptr;
    locationList[2].ptrToSouth= &locationList[4];
    locationList[2].ptrToWest= &locationList[1];
    locationList[2].ptrToEast= nullptr;

    locationList[3].ptrToNorth= &locationList[0];
    locationList[3].ptrToSouth= &locationList[5];
    locationList[3].ptrToWest= &locationList[2];
    locationList[3].ptrToEast= nullptr;

    locationList[4].ptrToNorth= &locationList[2];
    locationList[4].ptrToSouth= nullptr;
    locationList[4].ptrToWest= nullptr;
    locationList[4].ptrToEast= &locationList[5];

    locationList[5].ptrToNorth= &locationList[3];
    locationList[5].ptrToSouth= nullptr;
    locationList[5].ptrToWest= &locationList[4];
    locationList[5].ptrToEast= nullptr;

    locationList[0].ptrToNorth= nullptr;
    locationList[0].ptrToSouth= nullptr;
    locationList[0].ptrToWest= nullptr;
    locationList[0].ptrToEast= nullptr;

    ptrCurrentLocation= &locationList[1];
    ptrEndLocation= &locationList[0];


}



/* Cleanup() - 	Clean up memory allocated
 * */
void Program::Cleanup()
{
    // This is called automatically when the program ends
    if (locationList != nullptr)
    {
        delete [] locationList;
    }
}



/* Main() - Main program loop
 * */
void Program::Main()
{
    bool done = false;

    while (!done)
    {
        DisplayCurrentLocation();
        if (ptrCurrentLocation==ptrEndLocation) //check if player has reached end
        {
            cout<<"You've reached the end..."<<endl;
            done= true;
        }

        string choice= GetUserInput();

        if(choice== "n" && ptrCurrentLocation->ptrToNorth!=nullptr)
        {
            ptrCurrentLocation= ptrCurrentLocation->ptrToNorth;
        }
        else if(choice== "s" && ptrCurrentLocation->ptrToSouth!=nullptr)
        {
            ptrCurrentLocation= ptrCurrentLocation->ptrToSouth;
        }
        else if (choice== "e" && ptrCurrentLocation->ptrToEast!=nullptr)
        {
            ptrCurrentLocation = ptrCurrentLocation->ptrToEast;
        }
        else if (choice=="w" && ptrCurrentLocation->ptrToWest!=nullptr)
        {
            ptrCurrentLocation= ptrCurrentLocation->ptrToWest;
        }
        else if (choice=="q")
        {
            done = true;
        }
        else
        {
            cout<<"\nInvalid Choice"<<endl;
            GetUserInput();
        }


    }
    cout<<"GOODBYE!"<<endl;
}



/* DisplayCurrentLocation() - Use the current location
 *              pointer to display the location's name
 *              and description, as well as which
 *              directions the player can move next.
 * */
void Program::DisplayCurrentLocation()
{
    cout<< ptrCurrentLocation->name<<endl;
    cout<< ptrCurrentLocation->description<<endl;
    cout<< "You may move: ";
    if (ptrCurrentLocation->ptrToNorth!= nullptr)
    {
        cout<< "*north";
    }
    if (ptrCurrentLocation->ptrToSouth != nullptr)
    {
        cout<< "\t*south";
    }
    if (ptrCurrentLocation->ptrToEast != nullptr)
    {
        cout<< "\t*east";
    }
    if (ptrCurrentLocation->ptrToWest != nullptr)
    {
        cout<< "\t*west";
    }
}



/* GetUserInput() - Display the list of options to the
 *                  user, then get their input and return
 *                  their choice.
 * */
string Program::GetUserInput()
{
    string choice;
    cout<< "Options: (n)orth, (s)outh, (e)ast, (w)est, (q)uit "<< endl;
    cin>>choice;
	return choice; // temp - replace me
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
    locationList = nullptr;
    ptrCurrentLocation = nullptr;
    Setup();
}

Program::~Program()
{
    Cleanup();
}
