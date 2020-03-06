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
    status currentStatus = CONTINUE;

    // if the number of moves is equal to the maximum number of possible
    // moves, then the game is at a draw
    if (noOfMoves == maxNoOfMoves)
    {
        currentStatus = DRAW;
    }

    // check if any rows, columns, or diagonals are the same
    // if they are, then the game is won
    for (int i = 0; i < numCellsAndRows; i++)
    {
        if (isEntireRowXOrO(i) || isEntireColumnXOrO(i))
        {
            currentStatus = WIN;
        }
    }

    // Diagonals
    if (areDiagonalsAllXOrO())
    {
        currentStatus = WIN;
    }

    // Otherwise, the game can continue
    return currentStatus;
}

// Returns the current player's symbol
char ticTacToe::currentPlayer() const
{
    const char symbols[] = {'X', 'O'};

    return symbols[noOfMoves % 2];
}

// Starts the game
void ticTacToe::play()
{
    int row, col;
    char player;

    while (gameStatus() == CONTINUE)
    {
        player = currentPlayer();
        getPlayerMove(row, col);

        // Keep looping until a valid move is entered
        while (!makeMove(row, col))
        {
            cout << "Invalid move, please try again.\n";
            getPlayerMove(row, col);
        }

        cout << endl;
        displayBoard();
    }

    switch (gameStatus())
    {
        case DRAW:
            cout << "\nThis game is a draw!\n";
            break;
        case WIN:
            cout << "\nPlayer " << player <<  " wins!\n";
            break;
    }
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
        board[row - 1][col - 1] = symbol;
        noOfMoves++;
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

// Gets a valid (1 <= (row, col) <= 3) move for a player
void ticTacToe::getPlayerMove(int &row, int &col) const
{
    cout << "\nPlayer " << currentPlayer() << " enter move (row col): ";
    cin >> row >> col;
    cin.ignore();
}

// Determines if a move is valid. A valid move is one in which the x- and
// y-coordinates are both 1 <= (x, y) <= 3 and the space is not occupied
// (neither and 'X' or 'O' character occupies that space)
bool ticTacToe::isValidMove(const int x, const int y) const
{
    bool coordsInRange = (0 < x && x < 4) && (0 < y && y < 4);

    // make sure that the coordinates are in range, otherwise we may be
    // checking space that's out of range for the board array
    bool spaceIsntOccupied = coordsInRange ? board[x - 1][y - 1] == ' ' : false;

    return spaceIsntOccupied && coordsInRange;
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
bool ticTacToe::isEntireRowSame(const int row) const
{
    return (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]);
}

// Determines if an entire row has the same character in each cell
bool ticTacToe::isEntireRowXOrO(const int row) const
{
    return isEntireRowSame(row) && board[row][0] != ' ';
}

// Determines if an entire column is an 'X' or a 'O'
bool ticTacToe::isEntireColumnSame(const int col) const
{
    return (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]);
}

// Determines if an entire column has the same character in each cell
bool ticTacToe::isEntireColumnXOrO(const int col) const
{
    return isEntireColumnSame(col) && board[0][col] != ' ';
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
    return areDiagonalsSame() && board[1][1] != ' ';
}
