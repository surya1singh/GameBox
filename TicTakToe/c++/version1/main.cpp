#include "mainClasses.cpp"
#include "mainFunctions.cpp"

int main()
{
    string user1, user2;
    Board gameBoard;
    int row, col, result;
    row = 5;
    col = 5;
    result = 0;

    setUsername(user1, user2);
    printTheBoard(gameBoard);

    for (int i=0; i<8; i++)
    {
        printUserPrompt(gameBoard, user1, 'x', row, col);
        cout << '\n';
        setPosition(gameBoard, 'x', row, col);
        printTheBoard(gameBoard);
        result = checkWin(gameBoard, 'x');
        if (result==1)
        {
            cout << user1 << "wins!";
            break;
        }

        printUserPrompt(gameBoard, user2, 'y', row, col);
        cout << '\n';
        setPosition(gameBoard, 'y', row, col);
        printTheBoard(gameBoard);
        result = checkWin(gameBoard, 'y');
        if (result==1)
        {
            cout << user2 << "wins!";
            break;
        }

    }
    if (result == 0)
    {
        cout << "Game tied!";
    }

}
