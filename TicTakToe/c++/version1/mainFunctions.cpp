#include <iostream>
#include <string>

using namespace std;

void setUsername(string &user1, string &user2);
void printTheBoard(Board gameBoard);
void printTheBoardForInput();
void printUserPrompt(string name, char c, int &row, int &col);
void setPosition(Board &gameBoard, char c, int row, int col);

void setUsername(string &user1, string &user2)
{
    cout << "Enter first user name\n";
    cin >> user1;
    cout << "Enter second user name\n";
    cin >> user2;
}

void printTheBoard(Board gameBoard)
{
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << "|"<< gameBoard.getPosition(i,j);
        }
        cout << "|\n";
    }
    cout << "\n";
}

void printTheBoardForInput()
{
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << "|" << i << " " << j;
        }
        cout << "|\n";
    }
}

void printUserPrompt(Board &gameBoard, string name, char c, int &row, int &col)
{
    char position_char;
    int userInput = -1;
    cout << name << " where would you like to place an " << c << "?\n";
    printTheBoardForInput();
    do
    {
        cin >> row >> col;
        position_char = gameBoard.getPosition(row, col);
        if(position_char != '_' or row>3 or col>3 or row <0 or col<0)
        {
            cout<<"\nThat postition is taken or invalid position";
        }
        else
        {
            userInput = 0;
        }
    }while(userInput == -1);

}

void setPosition(Board &gameBoard, char c, int row, int col)
{
    gameBoard.setPosition(c, row, col);
}

int checkWin(Board &gameBoard, char c)
{
    int row, col, f_diag, b_diag;
    char position_char;
    f_diag = 0;
    b_diag = 0;
    for (int i=0; i<4; i++)
    {
        row = 0;
        col = 0;
        for(int j=0; j<4; j++)
        {
            position_char = gameBoard.getPosition(i,j);
            if (position_char == c)
            {
                row++;
                if (i == j)
                {
                    f_diag++;
                }
                if ( i == (3-j) )
                {
                    b_diag++;
                }
            }
            position_char = gameBoard.getPosition(j,i);
            if (position_char == c)
            {
                col++;
            }
        }
        if (row == 4 or col == 4)
        {
            return 1;
        }
    }
    if (f_diag==4 or b_diag==4)
    {
        return 1;
    }
    return 0;
}
