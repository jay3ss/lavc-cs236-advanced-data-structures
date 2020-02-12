#include "TicTacToe.h"

// Default constructor
ticTacToe::ticTacToe()
{
    restart();
}

// Prints the board
void ticTacToe::displayBoard() const
{
    const int numCellsAndRows = 3;
    const string dividerString = "______|_____|_____\n";
    const string spaceString = "      |     |\n";

    cout << "1     2     3\n\n";

    for (int i = 0; i < numCellsAndRows; i++)
    {
        if (i == 1)
        {
            cout << spaceString;
        }

        cout << i + 1;

        for (int j = 0; j < numCellsAndRows; j++)
        {
            cout << "   " << board[i][j] << (j < 2 ? " |" : "\n");

        }

        cout << (i < 2 ? dividerString : spaceString);
    }
}

// Determines the current status of the game
status ticTacToe::gameStatus()
{
    const int numCellsAndRows = 3;

    // if the number of moves is equal to the maximum number of possible
    // moves, then the game is at a draw
    if (noOfMoves == maxNoOfMoves)
    {
        return DRAW;
    }

    // check if any rows, columns, or diagonals are the same
    // if they are, then the game is won
    for (int i = 0; i < numCellsAndRows; i++)
    {
        if (isEntireRowXOrO(i) || isEntireColumnXOrO(i))
        {
            return WIN;
        }
    }

    // Diagonals
    if (areDiagonalsAllXOrO())
    {
        return WIN;
    }

    // Otherwise, the game can continue
    return CONTINUE;
}

// Returns the current player's symbol
char ticTacToe::currentPlayer()
{
    const char symbols[] = {'X', 'O'};

    return symbols[noOfMoves % 2];
}

// Puts the player's character at the desired postion (row, column) on the
// board. Must be a valid move (space not already occupied by a player
// character)
bool ticTacToe::makeMove(const int row, const int col)
{
    bool validMove = isValidMove(row, col);

    if (validMove)
    {
        const char symbol = currentPlayer();
        board[col][row] = symbol;
    }

    return validMove;
}

// Gets the move for a player
bool ticTacToe::getXOMove(const char moveSymbol)
{
    // 'X' goes on even numbered turns while 'O' goes on odd ones
    bool isXsMove = noOfMoves % 2 == 0;
    return (isXsMove && moveSymbol == 'X') || (!isXsMove && moveSymbol == 'O');
}

bool ticTacToe::isValidMove(const int x, const int y) const
{
    return (board[x][y] != 'X') && (board[x][y] != 'O');
}

// Restarts the game
void ticTacToe::restart()
{
    initializeBoard();
    noOfMoves = 0;
}

// Initializes the board to have all empty cells (' ' character)
void ticTacToe::initializeBoard()
{
    const int numCellsAndRows = 3;

    for (int i = 0; i < numCellsAndRows; i++)
    {
        for (int j = 0; j < numCellsAndRows; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Determines if an entire row is an 'X' or a 'O'
bool ticTacToe::isEntireColumnSame(const int col) const
{
    return (board[col][0] == board[col][1]) && (board[col][1] == board[col][2]);
}

// Determines if an entire column has the same character in each cell
bool ticTacToe::isEntireColumnXOrO(const int col) const
{
    bool colIsSame = isEntireColumnSame(col);
    return (colIsSame && (board[col][0] == 'X' || board[col][0] == 'O'));
}

// Determines if an entire row is an 'X' or a 'O'
bool ticTacToe::isEntireRowSame(const int row) const
{
    return (board[0][row] == board[1][row]) && (board[1][row] == board[2][row]);
}

// Determines if an entire column has the same character in each cell
bool ticTacToe::isEntireRowXOrO(const int row) const
{
    bool rowIsSame = isEntireRowSame(row);
    return (rowIsSame && (board[0][row] == 'X' || board[0][row] == 'O'));
}

// Determines if either of the diagonals is all 'X's or 'O's
bool ticTacToe::areDiagonalsSame() const
{
    bool firstDiag = board[0][0] == board[1][1] && board[1][1] == board[2][2];
    bool secondDiag = board[0][2] == board[1][1] && board[1][1] == board[2][0];
    return firstDiag || secondDiag;
}

// Determines if either of the diagonals is all 'X's or 'O's
bool ticTacToe::areDiagonalsAllXOrO() const
{
    return areDiagonalsSame() && (board[1][1] == 'X' || board[1][1] == 'O');
}
