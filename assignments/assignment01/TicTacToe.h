#include <iostream>
#include <string>

using namespace std;
enum status {WIN, DRAW, CONTINUE};

class ticTacToe
{
public:
    // Default constructor
    // Postcondition: initializes the board to an empty state
    ticTacToe();

    // Starts the game
    void play();

    // Prints the board
    // Precondition: the board must have been initialized
    void displayBoard() const;

    // Determines if a move is valid
    // Precondition: the board must have been initialized
    bool isValidMove(const int x, const int y) const;

    // Gets the move for a player
    bool getXOMove(const char moveSymbol);

    // Determines the current status of the game
    status gameStatus();

    // Restarts the game
    void restart();

private:
    char board[3][3];
    int noOfMoves;
    const int maxNoOfMoves = 9; // corresponds to a draw

    // Initializes the board to have all empty cells (' ' character)
    void initializeBoard();

    // Determines if an entire column has the same character in each cell
    bool isEntireColumnSame(const int col) const;

    // Determines if an entire column is an 'X' or a 'O'
    bool isEntireColumnXOrO(const int col) const;

    // Determines if an entire row has the same character in each cell
    bool isEntireRowSame(const int row) const;

    // Determines if an entire row is an 'X' or a 'O'
    bool isEntireRowXOrO(const int row) const;

    // Determines if either diagonal has the same character in each cell
    bool areDiagonalsSame() const;

    // Determines if either of the diagonals is all 'X's or 'O's
    bool areDiagonalsAllXOrO() const;
};
