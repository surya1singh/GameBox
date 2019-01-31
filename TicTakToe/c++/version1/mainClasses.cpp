class Board
{
    char board[4][4];
public:
    Board();
    char getPosition(int row, int col);
    void setPosition(char c, int row, int col);

};

Board::Board()
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            board[i][j] = '_';
        }
    }
}

char Board::getPosition(int row, int col)
{
    return board[row][col];
}

void Board::setPosition(char c, int row, int col)
{
    board[row][col] = c;
}
