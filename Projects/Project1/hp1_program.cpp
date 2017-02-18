#include "hp1_program.hpp"

/*
MODIFY THIS FILE
*/

#include <iostream>
using namespace std;

/* Menu Functions **********************************************/

/*
DisplayMenu()
Inputs: None
Outputs: None
This function should just display a simple # list and header, such as:
1. Set mission parameters, 2. View parameters, 3. Run simulation, 4. Quit
*/
void Program::DisplayMenu()
{
    cout<<"1. Set mission parameters, 2. View parameters, 3. Run simulation, 4. Quit";
    cout<<endl;
}

/*
SetParameters()
Inputs: None
Outputs: None
In this function, we will get the user's input for the following fields:
- food grown per day (int)		- cleanup per person per day (int)
- team name	(string)			- team size (int)
- mission length in days (int)	- starting units of food (int)

Create variables for each of these. Prompt the user for each
of these items with a cout command ("please enter ___:"),
and get their input through cin.

Finally, once those are all entered, you will use the following functions
to set these variables in the simulator:
- SetFoodGrown_PerDay(int)		- SetCleanup_PerPersonPerDay(int)
- SetTeamName(string)			- SetTeamSize(int)
- SetMissionLength(int)			- SetFoodCount(int)
*/
void Program::SetParameters()
{
    int foodGrownPerDay;
    cout<<"Please enter food grown per day: ";
    cout<<endl;
    cin>>foodGrownPerDay;

    int cleanup;
    cout<<"Amount of cleanup per person?: ";
    cout<<endl;
    cin>>cleanup;

    string teamName;
    cout<<"Team name?: ";
    cout<<endl;
    cin>>teamName;

    int teamSize;
    cout<<"Team Size?: ";
    cout<<endl;
    cin>>teamSize;

    int missionDays;
    cout<<"Length of mission in days?: ";
    cout<<endl;
    cin>>missionDays;

    int startingFood;
    cout<<"Units of food starting out?: ";
    cout<<endl;
    cin>>startingFood;

    SetFoodGrown_PerDay(foodGrownPerDay);
    SetCleanup_PerPersonPerDay(cleanup);
    SetTeamName(teamName);
    SetTeamSize(teamSize);
    SetMissionLength(missionDays);
    SetFoodCount(startingFood);
}

/*
ViewParameters()
Inputs: None
Outputs: None
In this function, you will just display the parameters that were entered
in the SetParameters() function. You can do this by utilizing the "getter"
functions available to the simulation...:
- GetFoodConsumed_PerPersonPerDay()			- GetWasteCreated_PerPersonPerDay()
- GetOxygenCreated_PerDay()					- GetOxygenUsed_PerPersonPerDay()
- GetFoodGrown_PerDay()						- GetCleanup_PerPersonPerDay()
- GetTeamName()								- GetTeamSize()
- GetMissionLength()

All of these functions *return* a value - either ints or strings.
You can cout each of these, like:
cout << GetOxygenUsed_PerPersonPerDay() << endl;

Just display each value, but also make sure to display a label for each.
*/
void Program::ViewParameters()
{
    cout<<"Food consumed per person each day: "<<GetFoodConsumed_PerPersonPerDay()<<endl;
    cout<<"Waste created per person each day: "<<GetWasteCreated_PerPersonPerDay()<<endl;
    cout<<"Oxygen created per day: "<<GetOxygenCreated_PerDay()<<endl;
    cout<<"Oxygen used per person each day: "<<GetOxygenUsed_PerPersonPerDay()<<endl;
    cout<<"Food grown per day: "<<GetFoodGrown_PerDay()<<endl;
    cout<<"Cleanup per person each day: "<<GetCleanup_PerPersonPerDay()<<endl;
    cout<<"Team name: "<<GetTeamName()<<endl;
    cout<<"Team size: "<<GetTeamSize()<<endl;
    cout<<"Length of mission in days: "<<GetMissionLength()<<endl;
}

/*
AdjustFood()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetFoodGrown_PerDay()		- GetFoodConsumed_PerPersonPerDay()
- GetFoodCount()			- GetTeamSize()

It will calculate the amount of food produced and consumed,
and update the food count.

First, create a temporary local int variable, named something like "foodCount".
Assign it the return value of the GetFoodCount() function.

Then, adjust the food count with the formula:
	new food count = old food count + food grown per day - ( food consumed per person per day * team size )

After the calculation, update the food count using SetFoodCount(int).
*/
void Program::AdjustFood()
{
    int foodCount= GetFoodCount();
    foodCount= foodCount+GetFoodGrown_PerDay()-(GetFoodConsumed_PerPersonPerDay()*GetTeamSize());
    SetFoodCount(foodCount);
}

/*
AdjustWaste()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetWasteCount()		- GetWasteCreated_PerPersonPerDay()
- GetTeamSize()			- GetCleanup_PerPersonPerDay()

Create a temporary variable and assign it the value of GetWasteCount().

Calculate the new waste count with the formula:
	new waste count = old waste count + (waste created per person per day * team size) - (cleanup per person per day * team size)

After the calculation, update the waste count using SetWasteCount(int).
*/
void Program::AdjustWaste()
{
    int wasteCount= GetWasteCount();
    wasteCount= wasteCount+(GetWasteCreated_PerPersonPerDay()*GetTeamSize())-(GetCleanup_PerPersonPerDay()*GetTeamSize());

    SetWasteCount(wasteCount);
}

/*
AdjustOxygen()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetOxygenCount()		- GetOxygenCreated_PerDay()
- GetTeamSize()			- GetOxygenUsed_PerPersonPerDay()

Create a temporary variable and assign it the value of GetOxygenCount().

Calculate the new oxygen count with the formula:
	new oxygen count = old oxygen count + oxygen created per day - (oxygen used per person per day * team size)

After the calculation, update the oxygen count using SetOxygenCount(int).
*/
void Program::AdjustOxygen()
{
    int oxygenCount= GetOxygenCount();
    oxygenCount= oxygenCount+GetOxygenCreated_PerDay()- (GetOxygenUsed_PerPersonPerDay()*GetTeamSize());

    SetOxygenCount(oxygenCount);
}

/*
RunSimulation()
Inputs: None
Outputs: None
The simulation runs through each day, adjusting values to see if
the astronauts can survive for the set amount of days.
Follow the comments below for the steps.
*/
void Program::RunSimulation()
{
	cout << endl << "RUN SIMULATION" << endl;

	// Set up the simulation:
	// * Create an integer variable called day, and initialize it to 1.
	// * Use SetOxygenCount(int) to initialize the oxygen count to 100.
	// * Use SetWasteCount(int) to initialize the waste count to 0.
	// * Create a boolean variable called missionSuccess, and set it to true.
	int day=1;
	SetOxygenCount(100);
	SetWasteCount(0);
	bool missionSuccess= true;



	// Create a while loop. This will continue looping while
	// the day is less than the mission length (GetMissionLength()),
	// and while missionSuccess is true.
	while ( day<(GetMissionLength()/2)&& missionSuccess == true)
	{
		// Adjust current supplies via the AdjustFood(), AdjustWaste(), and AdjustOxygen() functions.
		AdjustFood();
		AdjustWaste();
		AdjustOxygen();


		// Display the following values, and make sure to label them as well.
		// e.g., cout << "LABEL: " << values << endl;

		cout<<"Mission day "<<day<<endl;// * The current day
		cout<<"Food grown: "<<GetFoodGrown_PerDay()<<endl;// * Food grown				GetFoodGrown_PerDay()
		cout<<"Waste cleaned: "<<GetCleanup_PerPersonPerDay()<<endl; // * Waste cleaned			GetCleanup_PerPersonPerDay()
		cout<<"Oxygen created: "<<GetOxygenCreated_PerDay()<<endl; // * Oxygen created			GetOxygenCreated_PerDay()
		cout<<"Food consumed: "<<GetFoodConsumed_PerPersonPerDay()<<endl; // * Food consumed			GetFoodConsumed_PerPersonPerDay()
		cout<<"Waste created: "<<GetWasteCreated_PerPersonPerDay()<<endl; // * Waste created			GetWasteCreated_PerPersonPerDay
		cout<<"Oxygen consumed: "<<GetOxygenUsed_PerPersonPerDay()<<endl; // * Oxygen consumed		GetOxygenUsed_PerPersonPerDay
		cout<<"Current food count: "<<GetFoodCount()<<endl; // * Current food count		GetFoodCount()
		cout<<"Current waste count: "<<GetWasteCount()<<endl; // * Current waste count	GetWasteCount()
		cout<<"Current oxygen count: "<<GetOxygenCount()<<endl; // * Current oxygen count	GetOxygenCount()
		cout<<endl;




		// Check to see if resources have been depleted.
		// If so, then the mission is a failure.

		// If food count is less than 0, display a message that they ran out of food and set missionSuccess to false.
		if (GetFoodCount()<0)
        {
            cout<< "You have run out of food!"<<endl;
            missionSuccess= false;
        }


		// If waste count is greater than 20, display a message that they drowned in trash and set missionSuccess to false.
		else if (GetWasteCount()>20)
        {
            cout<<"You have drowned in trash!"<<endl;
            missionSuccess=false;
        }


		// If oxygen count is less than 0, display a message that they ran out of air and set missionSuccess to false.
		else if (GetOxygenCount()<0)
        {
            cout<<"You have run out of air!"<<endl;
            missionSuccess=false;
        }


		// Increment the day variable by 1.
		else
        {
            day++;
        }
	}

	// After the while loop: Display the results.
	// If missionSuccess is true, display "MISSION SUCCESS!"
	// Otherwise, display "MISSION FAILURE!"

	cout << endl << "RESULTS" << endl;
	if (missionSuccess==true)
    {
        cout<<"MISSION SUCCESS!"<<endl;
    }
    else
    {
        cout<<"MISSION FAILURE!"<<endl;
    }
}



/* Utility Functions **********************************************/

/*
GetValidInput(int, int)
Inputs: min (int), max (int)
Outputs: int
This function takes in a minimum and maximum value that
can be entered by the user.

First, prompt the user for input with a cout statement.
Create a variable (int) to store their decision,
and get the user's input with cin.

Then, create a while loop that will keep asking the user
to re-enter their selection, WHILE the input is invalid.

Invalid input is if it is < min or > max.

After the while loop (once the input is valid), return
the variable that is storing the user's choice.
*/
int Program::GetValidInput(int min, int max)
{
	// Create an integer variable to store the user's choice
	int value=0;

	// Output to console: Ask the user to enter a value
	cout<<"Enter a value: ";
	cout<<endl;
	cin>>value;

	// Get the user's input and store it in your choice variable

	// While the input is invalid...
		// Display "invalid input"
		// Get the user's input again, and store it in the same choice variable
		while(value<min || value>max)
        {
            cout<<"Invalid input"<<endl;
            cout<<"Enter a value: ";
            cout<<endl;
            cin>>value;
        }

	// Return the choice variable after the while loop

	return value;
}


/*
DO NOT MODIFY BELOW
*/

/* Setter Functions **********************************************/

void Program::SetFoodGrown_PerDay(int value)
{
	foodGrown_PerDay = value;
}

void Program::SetCleanup_PerPersonPerDay(int value)
{
	cleanup_PerPersonPerDay = value;
}

void Program::SetTeamSize(int value)
{
	teamSize = value;
}

void Program::SetMissionLength(int value)
{
	missionLengthInDays = value;
}

void Program::SetTeamName(string value)
{
	teamName = value;
}

void Program::SetFoodCount(int value)
{
	countFood = value;
}

void Program::SetWasteCount(int value)
{
	countWaste = value;
}

void Program::SetOxygenCount(int value)
{
	countOxygen = value;
}


/* Getter Functions **********************************************/

int Program::GetFoodGrown_PerDay()
{
	return foodGrown_PerDay;
}

int Program::GetCleanup_PerPersonPerDay()
{
	return cleanup_PerPersonPerDay;
}

int Program::GetTeamSize()
{
	return teamSize;
}

int Program::GetMissionLength()
{
	return missionLengthInDays;
}

string Program::GetTeamName()
{
	return teamName;
}

int Program::GetFoodConsumed_PerPersonPerDay()
{
	return foodConsumed_PerPersonPerDay;
}

int Program::GetWasteCreated_PerPersonPerDay()
{
	return wasteCreated_PerPersonPerDay;
}

int Program::GetOxygenUsed_PerPersonPerDay()
{
	return oxygenUsed_PerPersonPerDay;
}

int Program::GetOxygenCreated_PerDay()
{
	return oxygenCreated_PerDay;
}

int Program::GetFoodCount()
{
	return countFood;
}

int Program::GetWasteCount()
{
	return countWaste;
}

int Program::GetOxygenCount()
{
	return countOxygen;
}




