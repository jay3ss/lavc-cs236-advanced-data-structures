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

    // Returns the current player's symbol
    char currentPalyer();

    // Gets the move for a player
    bool getXOMove(const char moveSymbol);

    // Determines the current status of the game
    status gameStatus();

    // Puts the player's character at the desired postion (row, column) on the
    // board. Must be a valid move (space not already occupied by a player
    // character)
    bool makeMove(const int row, const int col);

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
