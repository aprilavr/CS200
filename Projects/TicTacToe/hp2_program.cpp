/*
MODIFY THIS FILE
*/

#include "hp2_program.hpp"
#include "cuTEST/Menu.hpp"

#include <iostream>
using namespace std;

/* Main() - Program entry point
 * */
void Program::Main() // DONE
{
    Setup();
    bool done = false;

    while ( !done )
    {
        ClearBoard();
        GameLoop();

        // If we get to this point, it means one of the players
        // has won. We want to see if they want to play again!

        cout << "Play again? \t 1. YES \t 2. NO" << endl;
        int choice = GetValidInput( 1, 2 );
        if ( choice == 2 )  // quit
        {
            done = true;
        }
        // Otherwise we will loop again and
        // another game will start.
    }
}

/* Setup() - 	Should initialize all ELEMENTS of the gameBoard to a space character: ' '
 * 				Set the turn marker to 0
 * 				Set playerWins for both players to 0
 * 				Set playerMarker for each player: 'x' and 'o'.
 * */
void Program::Setup()
{
    for(int i = 0; i<3; i++)    //initialize board elements to ' '
    {
        for(int j=0; j<3; j++)
        {
            gameBoard[i][j]= ' ';
        }
    }
    turn=0; // set turn to zero

    for(int i=0; i<2; i++)  //set playerWins to zero for both players
    {
        playerWins[i]= 0;
    }
    playerMarker[0]= 'x';   //set player markers
    playerMarker[1]= 'o';
}

/* ClearBoard() -	Clear the game board of all pieces
 * */
void Program::ClearBoard() // DONE
{
    // Set up game board
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            gameBoard[x][y] = ' ';
        }
    }
}

/* GameLoop() -		Create a game loop that will keep running until the user quits.
 * 					Each cycle of the loop, call DrawStats() and DrawBoard(),
 * 					then have the player choose an x, y coordinate.
 *
 * 					Use the PlaceMarker function to attempt to place the player's
 * 					marker at the given x, y. If successful, then go to the other
 * 					player's turn. (Otherwise, they will have to select again.)
 *
 *
 * */
void Program::GameLoop()
{
    bool done= false;
    while(!done)
    {
        DrawStats();
        DrawBoard();
        int x;
        int y;
        cout<<"Player "<<GetCurrentPlayerTurn()<<", enter an X coordinate: "; //get player choice
        cin>>x;
        cout<<"\nPlayer "<<GetCurrentPlayerTurn()<<", enter a Y coordinate: ";
        cin>>y;

        PlaceMarker(x,y, playerMarker[GetCurrentPlayerTurn()]);
        SwapTurn();
        CheckForWinner();
        if (CheckForWinner()!=-1)  //check for winner
        {
            playerWins[GetCurrentPlayerTurn()]++;
            cout<<"Player "<<GetCurrentPlayerTurn()<<" wins!"<<endl;
            done=true;
        }
    }
}

/* GetValidInput( int min, int max ) - Get user to enter their decision.
 * 	While their input is invalid (< min or > max), have them re-enter their selection.
 * 	Return the user's input once valid input has been provided.
 * */
int Program::GetValidInput( int min, int max )
{
    int choice;
    cin>>choice;
    while(choice<min || choice>max)
    {
     cout<<"Invalid, please re-enter: ";
    }

    return choice;
}

/* DrawStats() - 	Display game stats, such as how many wins per player, and whose turn it is.
 * */
void Program::DrawStats()
{
    cout<<"Player 1 wins: "<<playerWins[0]<<"\tPlayer 2 wins: "<<playerWins[1]<<endl;
    cout<<"Current turn: Player "<<GetCurrentPlayerTurn()<<endl;

}

/* DrawBoard() - 	Draw the 2D game board
 * */
void Program::DrawBoard() // Done
{
    cout << "\t";
    for ( int x = 0; x < 3; x++ )
    {
        cout << "\t";
        if ( x != 0 ) { cout << "\t"; }
        cout << x;
    }
    cout << endl;

    for ( int y = 0; y < 3; y++ )
    {
        if ( y != 0 ) { cout << endl << "\t---------------------------------------------------"; }
        cout << endl << y << "\t\t";

        for ( int x = 0; x < 3; x++ )
        {
            if ( x != 0 ) { cout << "\t|\t"; }
            cout << gameBoard[x][y];
        }
    }
    cout << endl << endl;
}

/* GetCurrentPlayerTurn() - Return the value of the *turn* variable.
 * */
int Program::GetCurrentPlayerTurn()
{
    return turn;
}

/* SwapTurn()	- Change to the other player's turn.
 * */
void Program::SwapTurn()
{
    if(turn==0)
    {
        turn=1;
    }
    else
    {
        turn=0;
    }
}

/* PlaceMarker( int x, int y, char marker ) - Set the location on
 * 	the game board to a specific marker (will be player's 'x' or 'o'...)
 * 	However, you need to check to see if that spot on the board is available.
 *  If it is available, place the marker there, and return true.
 *  Otherwise, if it is unavailable ('x' or 'o' is already there), return false.
 * */
bool Program::PlaceMarker( int x, int y, char marker )
{
    if(gameBoard[x][y]==' ')
    {
        gameBoard[x][y]= marker;
        return true;
    }
    else
    {
        return false;
    }

}

/* CheckForWinner() -	Check the gameBoard for various win-scenarios.
 * 						Return -1 if nobody has a winning move, otherwise
 * 						return 0 for player 0 win, and return 1 for player 1 win.
 * 						( Player 0 should have 'x', Player 1 should have 'o'. )
 *
 * OPTIONS: You can either use if-statements to make an exhaustive
 * list of all possible win combinations (normal points).
 * There should be 8 possible winning moves, per player.
 * (See documentation)
 *
 * OR:
 *
 * Use a more generic approach, where you can use for-loop(s) to iterate
 * through the game board positions and figure out if there is a winner
 * or not. (Extra credit)
 * */
int Program::CheckForWinner()
{
    int winner=-1;
    for (int i=0; i<3; i++)
    {
        if (gameBoard [i][0]==gameBoard[i][1]&& gameBoard[i][0]==gameBoard[i][2])   //horizontal
        {
            if(gameBoard[i][0]=='x')
            {
                winner= 0;
            }
            else if(gameBoard[i][0]=='o')
            {
                winner= 1;
            }
        }
        else if (gameBoard [0][i]==gameBoard[1][i]&& gameBoard[0][i]==gameBoard[2][i])  //vertical
        {

            if(gameBoard[0][i]== 'x')
            {
                winner= 0;
            }
            else if (gameBoard[0][i]=='o')
            {
                winner=1;
            }

        }
        else if(gameBoard[0][0]== gameBoard[1][1]&& gameBoard[0][0]==gameBoard[2][2])   //diagonals
        {
            if(gameBoard[0][0]=='x')
            {
                winner=0;
            }
            else if(gameBoard[0][0]=='o')
            {
                winner=1;
            }
        }
        else if(gameBoard[2][0]==gameBoard[1][1] && gameBoard[2][0]==gameBoard[0][2])
        {
            if(gameBoard[2][0]=='x')
            {
                winner=0;
            }
            else if(gameBoard[2][0]== 'o')
            {
                winner=1;
            }
        }
        else
        {
            winner=-1;
        }

    }

 	return winner;

}
