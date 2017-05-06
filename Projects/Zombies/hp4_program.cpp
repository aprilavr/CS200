/*
MODIFY THIS FILE
*/

#include "hp4_program.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//! Initializes the program state.
/**
    - Seed the random number generator:       srand( time( NULL ) );
    - Set the two pointer variables to nullptr; m_locationList and m_team.
    - Set the m_week variable to 0.
    - Call the Setup() function.
*/
Program::Program()
{
    srand(time(NULL));
    m_locationList=nullptr;
    m_team=nullptr;
    m_week=0;
    Program::Setup();
}

//! Cleans up the program.
/**
    - Call the Cleanup() function.
*/
Program::~Program()
{
        Program::Cleanup();
}

//! Calls functions needed for program setup, and then calls Main().
/**
    - Call SetupDynamicArrays()
    - Call LoadLocations()
    - Call LoadPeople()
    - Call Main()


*/
void Program::Setup()
{
    SetupDynamicArrays();
    LoadLocations();
    LoadPeople();
    Main();
}

//! Cleans up the dynamic memory.
/**
    Safely free the memory allocated by m_team and m_locationList.


*/
void Program::Cleanup()
{
    delete [] m_locationList;
    delete [] m_team;
}

//! Main game loop.
/**
    With the game loop...
        - Increment the week by 1
        - Call DisplayWeekStats()
        - Call UpdateTeam()
        - Call ScavengePhase()
        - Call ZombiePhase()
        - if everyone is dead (call IsEveryoneDead())...
            - done with game loop
        - Call RoundPause()

    - Once the game is over, call DisplaySummary().
*/
void Program::Main()
{
    bool done=false;
    while(!done)
    {
    m_week++;
    DisplayWeekStats();
    UpdateTeam();
    ScavengePhase();
    ZombiePhase();
    if(IsEveryoneDead()==true)
    {
        done=true;
    }
    RoundPause();
    }
    DisplaySummary();
}

//! Display the base's stats and the current week.
/**
    Display the current week, as well as the current ammo and food held by the base.
*/
void Program::DisplayWeekStats()
{
    cout<<"Week "<<m_week<<": "<<endl;
    cout<<"Base ammo: "<<m_base.GetAmmo()<<"\tBase food: "<<m_base.GetFood()<<endl;
}

//! Update the team's hunger and health.
/**
    For each team member:
        - Call their Update() function
        - Look at the person's GetHunger() value, and request that amount of food from the base via TakeFood().
        - Have person Eat() that food.
        - Display that person's stats afterwards.
*/
void Program::UpdateTeam()
{
        for(int i=0; i<m_teamCount; i++)
    {
        m_team[i].Update();
        m_team[i].Eat(m_base.TakeFood(m_team[i].GetHunger()));
        m_team[i].DisplayStats();
    }
}

//! Get player to choose scavenging locations and update base and team stats.
/**
    - Display a list of all the available locations.
    - Ask the user which 3 locations to scavenge at, get their input.
    - Do input validation to make sure they have selected 3 valid indices.
    - Calculate the total amount of ammo salvaged from all 3 locations.
    - Calculate the total amount of food salvaged from all 3 locations.
    - Display the results - amount of food and ammo scavenged (total of each.)
    - Add that amount of ammo and food back to the base.
*/
void Program::ScavengePhase()
{
        for(int i=0;i<m_locationCount; i++)
    {
        cout<< i<< ": "<< m_locationList[i].GetName()<<endl;
    }
    cout<<"Choose 3 locations to scavenge. First location?: ";
    int choice1,choice2,choice3;
    cin>>choice1;
    while(choice1>=m_locationCount)
    {
        cout<< "Invalid choice, first location?: ";
        cin>>choice1;
    }
    cout<<"\nSecond location?: ";
    cin>>choice2;
    while(choice2>=m_locationCount)
    {
        cout<< "Invalid choice, second location?: ";
        cin>>choice2;
    }
    cout<<"\nThird location?: ";
    cin>>choice3;
    while(choice3>=m_locationCount)
    {
        cout<< "Invalid choice, third location?: ";
        cin>>choice3;
    }
    int ammo= m_locationList[choice1].GetAmmo()+m_locationList[choice2].GetAmmo()+m_locationList[choice3].GetAmmo();
    int food= m_locationList[choice1].GetFood()+m_locationList[choice2].GetFood()+m_locationList[choice3].GetFood();
    cout<<"Ammo found: "<<ammo<<"\tFood found: "<<food<<endl;
    m_base.AddFood(food);
    m_base.AddAmmo(ammo);
}

//! Check for zombie attack, and adjust team health and base stats.
/**
    - Generate a random number between 0 and 3.
    - If the random number is 0, then zombie attack:
        - Randomly select the zombie amount, between 1 and 3.
        - Calculate the total zombie health: 10 x the zombie count.
        - Display a message about the zombie attack, and how many zombies there are.
        - Determine if the base has enough ammo to fend off the zombies.
        - If there is not enough ammo:
            - Display a message that the base is out of ammo.
            - Subtract the amount of ammo the base has from the total zombie health.
            - Base ammo is now 0.
            - Zombies get a chance to attack a person. Randomly select a team member to attack.
            - Display a message of who the zombies attacked.
            - Call that team member's Hurt() function, with a random amount of damage between 10 and 20.
        - If there is enough ammo:
            - Subtract the total zombie health from the ammo count.
            - Display a message that the zombies have been killed, and how much ammo was used (equivalent to total zombie health).
*/
void Program::ZombiePhase()
{
    int num=rand()%3;
    if(num==0)
    {
        int zombies=rand()%3+1;
        int zombieHealth=zombies*10;
        cout<<"There are "<<zombies<<" zombies attacking!"<<endl;
        if(m_base.GetAmmo()<zombies)
        {
            cout<<"Base is out of ammo."<<endl;
            zombieHealth-=m_base.GetAmmo();
            m_base.SetAmmo(0);
            int attack=rand()%m_teamCount;
            cout<<"Zombies attack "<<m_team[attack].GetName()<<endl;
            m_team[attack].Hurt(rand()%20+10);
        }
        else
        {
            m_base.SubtractAmmo(zombieHealth);
            cout<<"Zombies killed, "<<zombieHealth<<" ammo used."<<endl;
        }

    }
}

//! Check if the entire team is dead. If everyone is dead, return true. Otherwise, return false.
/**
    Determine if everybody on the team is dead. If at least one person lives, then this will return false.
    If everybody is dead, return true.

    If everyone is dead, display a message that everyone is dead.

    @return <bool>      true if everyone is dead; false if at least one person is alive.
*/
bool Program::IsEveryoneDead()
{
    int i=0;
    while(i<m_teamCount)
    {
        m_team[i].IsDead();
        if(!m_team[i].IsDead())
        {
            return false;
            break;
        }
        else
            {
            return true;
        }
    i++;

    }
}

//! Display the game summary.
/**
    Display the amount of weeks that the team survived.
*/
void Program::DisplaySummary()
{
        cout<<"Team survived "<<m_week<<" weeks"<<endl;
}

//! Ask the user for input before continuing the program execution.
/**
    Ask the user to enter a value before continuing.
    (Can just be a dummy cin into a variable that doesn't do anything.)
*/
void Program::RoundPause()
{
    int variable;
    cout<<"Number?: ";
    cin>>variable;
    cout<<endl;
}

//! Load location information from the locations.txt file.
/**
    Create an ifstream object and open the locations.txt file.

    Create three temporary variables: name (string), ammo (int), food (int).
    Also create a counter variable i (int) and initialize it to 0.

    Create a while loop, while the counter i is less than the location count m_locationCount...
        - Retrieve name, ammo, and food from the input file
        - Setup location #i via its Setup() function.
        - Increment the counter variable i.

    Close the input file when done.
*/
void Program::LoadLocations()
{
    ifstream input;
    input.open("locations.txt");
    string name;
    int ammo;
    int food;
    int i=0;

    while(i<m_locationCount)
    {
        input>>name;
        input>>ammo;
        input>>food;
        m_locationList[i].Setup(name, ammo, food);
        i++;
    }
    input.close();
}

//! Load a list of names from the names.txt file and randomly assign names to the team.
/**
    Load names:
        - Create an array of strings that will store names that are loaded in. The array size should be 207.
        - Create a counter variable i, initialize it to 0.
        - Create an input file stream, and open names.txt
        - Use a while loop to load data from the input file to the names array
            e.g., while ( input >> names[i] )
        - Within the while loop, increment i by 1.
        - Close the input file once done.

    Assign names to team:
        - For each team member, use the Setup() function.
        - Pass in a random name to the Setup function to assign the person a random name.
*/
void Program::LoadPeople()
{
    ifstream input;
    string nameArray[207];
    int i=0;
    input.open("names.txt");
    while(input>>nameArray[i])
    {
        i++;
    }
    input.close();
     for(int i=0; i<m_teamCount; i++)
     {
         m_team[i].Setup(nameArray[rand()%207]);
     }
}

//! Ask the user how many locations and team members are available, and allocate memory for the dynamic arrays.
/**
    Ask the player how many locations and how many team members to have.

    Max location size is 10. Utilize a while loop to validate that the user has entered
    an amount between 0 and 10.

    Team count has to be 1 or more, use a while loop to validate that the user has entered
    an amount greater than 1.

    Afterward, use the m_locationList and m_team pointers to create
    dynamic arrays with the sizes given.
*/
void Program::SetupDynamicArrays()
{
    cout<<"How many locations?: ";
    cin>>m_locationCount;
    while(m_locationCount<0||m_locationCount>10)
    {
        cout<<"\nPlease enter a number between 1 and 10: ";
        cin>>m_locationCount;
    }
    cout<<"\nHow many team members?: ";
    cin>>m_teamCount;
        while(m_teamCount<1)
    {
        cout<<"\nAt least 1 team member required: ";
        cin>>m_teamCount;
    }

    m_locationList= new Location[m_locationCount];
    m_team= new Person[m_teamCount];
}
