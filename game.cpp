#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void rules()
{                 
    cout << "Welcome to checkers!" << endl << endl << "The rules of the game are as follows:" << endl << endl << "Pieces (black denoted as 'b' and red denoted as 'r') can only move forward (towards the opposing player's side) one piece diagonally on black spaces denoted as 'x' on the board. The only time a piece can move 2 pieces diagonally is when there is an opposing player's piece in between." << endl << endl <<"To kill the opposing player's piece, you have to cross it diagnally." << endl << endl << "Each player has to kill all the pieces of the other player to win the game. Player can choose to quit the game if an invalid move is made, which will result in the player with more pieces left winning." << endl << endl << endl;
}


void initialise(string arr[][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((i%2 && !(j%2)) || (!(i%2) && j%2))
            {
                arr[i][j]="x";
            } 
            else
            {
                arr[i][j]=" ";
            }
        }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((i==0 || i==2)&&j%2)
            {
                arr[i][j] = "b";
            }
            else if(i == 1 && !(j%2))
            {
                arr[i][j] = "b";
            }
            else if((i==5 || i==7)&&!(j%2))
            {
                arr[i][j] = "r";
            }
            else if(i==6 && j%2)
            {
                arr[i][j] = "r";
            }
        }
    }
}

void display(string arr[][8])
{
    cout <<setw(38)<< "  0   1   2   3   4   5   6   7  " << endl;
    for(int i=0; i<8; i++)
    {
        cout <<setw(38)<< "+---+---+---+---+---+---+---+---+" << endl;
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                cout << setw(3)<<i << ". ";
            }

            cout<< "|"<<setw(2)<<arr[i][j]<< " ";
        }
        cout<<"|"<< endl;
    }
    cout<< setw(38) << "+---+---+---+---+---+---+---+---+"<<endl<<endl;
}

void game(string arr[][8])
{
    bool end = false;
    bool quitGame = false;
    int turn = 1;
    bool killed = false;
    while (!end) // outer loop which will run until end == false (it will break when end == true)
    {
        display(arr);
        bool valid = false;
        if(killed) 
        {
            cout<<"You have made a kill!"<<endl<<endl;
        }
        cout<<"Player "<<turn<<"'s turn"<<endl<<endl;
        int row, col;
        while(!valid) // to check if cordinates of piece you want to move are correct (position validity). (not be confused with 'move invalid' which will come later.)
        {
            
            killed = false;
            cout<<"Enter position of piece you would like to move:"<<endl;
            cout<<endl<<"Row No: ";
            cin>>row;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Enter valid Row No: ";
                cin>>row;
            }
            cout<<"Col No: ";
            cin>>col;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Enter valid Col No: ";
                cin>>col;
            }
            
            if(!(row>=0 && row<8 && col>=0 && col<8)||!((turn == 1 && arr[row][col] == "b")||(turn == 2 && arr[row][col] == "r"))) // all valid conditions are written and then '!' is added to check for invalidity. first condition checkes if coordinates are within board,2nd and 3rd conditions check if the coordinates you have entered hold either 'b' or 'r'
            {
                cout<<endl<<"Position Invalid"<<endl<<endl;
                continue;
            }
            int rowTo, colTo;
            cout<<endl<<"Enter position you would like to move to:"<<endl;
            cout<<endl<<"Row No: ";
            cin>>rowTo;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Enter valid Row No: ";
                cin>>rowTo;
            }
            cout<<"Col No: ";
            cin>>colTo;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Enter valid Col No: ";
                cin>>colTo;
            }
            if(rowTo>=0 && rowTo<8 && colTo>=0 && colTo<8) // now moving on to move invalidity check. (first and foremost the coordinates entered where you want to move piece should be within board.)
            {
                if(turn == 1)
                {
                    bool killCondition1 = row<=5 && col>=2 && arr[row+1][col-1] == "r" && arr[row+2][col-2]=="x"; // kill condition towards left. in this case 'b' is killing and 'r' is getting killed.
                    bool killCondition2 = row<=5 && col<=5 && arr[row+1][col+1] == "r" && arr[row+2][col+2]=="x"; // kill condition towards right. in this case 'b' is killing and 'r' is getting killed.
                    if(killCondition1 && rowTo==row+2 && colTo == col-2) // checks if kill condition 1 is true and the move of kill is executed.
                    {
                            arr[rowTo][colTo] = "b";
                            arr[row][col] = "x";
                            arr[row+1][col-1] = "x";
                            valid = true;
                            killed = true;
                    }
                    else if(killCondition2 && rowTo==row+2 && colTo == col+2) // checks if kill condition 2 is true and the move of kill is executed.
                    {
                            arr[rowTo][colTo] = "b";
                            arr[row][col] = "x";
                            arr[row+1][col+1] = "x";
                            valid = true;
                            killed = true;
                    } 
                    else if(rowTo - row == 1 && arr[rowTo][colTo] == "x" && (colTo - col == 1 || col - colTo == 1) ) // 3rd valid move available. either moving left or right 1 piece diaganolly.
                    {
                        arr[rowTo][colTo] = "b";
                        arr[row][col] = "x";
                        valid = true;
                    }
                } 
                else
                {
                    bool killCondition1 = row>=2 && col>=2 && arr[row-1][col-1] == "b" && arr[row-2][col-2]=="x"; // in this case, 'r' is killing and 'b' is getting killed. Rest logic is same, only row numbers change in condition because the 'r' pieces move upwards on the board.
                    bool killCondition2 = row>=2 && col<=5 && arr[row-1][col+1] == "b" && arr[row-2][col+2]=="x"; // same as above line^
                    if(killCondition1 && rowTo==row-2&&colTo == col-2)
                    {
                            arr[rowTo][colTo] = "r";
                            arr[row][col] = "x";
                            arr[row-1][col-1] = "x";
                            valid = true;
                            killed = true;
                    }
                    else if(killCondition2 && rowTo==row-2&&colTo == col+2)
                    {
                            arr[rowTo][colTo] = "r";
                            arr[row][col] = "x";
                            arr[row-1][col+1] = "x";
                            valid = true;
                            killed = true;
                    } 
                    else if(row - rowTo == 1 && arr[rowTo][colTo] == "x" && (colTo - col == 1 || col - colTo == 1) ) // 3rd valid move available. either moving left or right 1 piece diaganolly.
                    {
                        arr[rowTo][colTo] = "r";
                        arr[row][col] = "x";
                        valid = true;
                    }
                }
                if(!valid) // now if all valid is still false and none of the above mentioned valid moves were implemented, this if statement will run.
                {
                    cout<<endl<<"Move Invalid"<<endl<<endl;
                    cout<<"Press any character to continue. Press q to quit game: "<<endl;
                    string option;
                    cin>>option;
                    cout<<endl<<endl;
                    if(option == "q")
                    {
                        quitGame = true;
                        break;
                    }
                }
            }
            else // if coordinates of move were outside the board.
            {
                cout<<endl<<"Move Invalid"<<endl<<endl;
                cout<<"Press any character to continue. Press q to quit game: "<<endl;
                string option;
                cin>>option;
                if(option == "q")
                {
                    quitGame = true;
                    break;
                }
            }
        }
        if(quitGame)
        {
            break;
        }
        if(!killed) // to check if turn has to be alternated or not.
        {
            if(turn == 1)
            {
                turn = 2;
            } 
            else
            {
                turn = 1;
            }
        } 
        else
        {
            bool killedAll = true;
            for(int i=0; i<8; i++) // whole array is traversed
            {
                for(int j=0; j<8;j++)
                {
                    if((turn == 1 && arr[i][j] == "r") || (turn == 2 &&  arr[i][j] == "b")) // if its is player's 1 turn, then whole board will be checked to see if there are any opposing player's pieces left. if there are none then 'killedAll' will remain true and 'end' variable will be equated to 'killedAll' making 'end' true and breaking the outer while loop and ending game.
                    {
                        killedAll = false;
                        break;
                    }
                }
                if(!killedAll)
                {
                    break;
                }
            }
            end = killedAll;
            
        }
        system("clear");
        cout<<flush;
    }
    if(quitGame) // if the game was ended due to player quiting after an invalid move the in above code, quitGame variable wouldve turned true. in that case this if statement will run.
    {
        int numOfR = 0;
        int numOfB = 0;
        // in this nested for loop, whole array is traversed and number of 'b' and 'r' pieces are counted at the time game was quitted.
        for(int i = 0; i<8; i++)
        {
            for(int j = 0; j<8; j++) 
            {
                if(arr[i][j] == "r")
                {
                    numOfR++;
                }
                else if(arr[i][j] == "b")
                {
                    numOfB++;
                }
            }
        }
        if(numOfB > numOfR) // quite self explainatory.
        {
            cout<< "Player 1 has won the game!" <<endl;   
        }
        else if(numOfR > numOfB )
        {
            cout<<"Player 2 has won the game!" <<endl;
        }
        else 
        {
            cout<<"Game has been drawn!"<<endl;
        }
    }
    else
    {
        cout<<"Player "<<turn<<" has won the game!"<<endl;
    }
    
}

int main() 
{
    rules();
    string checkers[8][8];
    initialise(checkers);
    game(checkers);
} 