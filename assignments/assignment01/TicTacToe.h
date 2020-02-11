#include <string>

using namespace std;
enum status {WIN, DRAW, CONTINUE};

class ticTacToe
{
public:
    // Default constructor
    // Postcondition: initializes the board to an empty state;

    // Starts the game
    void play();

    // Prints the board
    void displayBoard() const;

    // Determines if a move is valid
    bool isValidMove(int x, int y) const;

    // Gets the move for a player
    bool getXOMove(char moveSymbol);

    // Determines the current status of the game
    status gameStatus();

    // Restarts the game
    void restart();

private:
    char board[3][3];
    int noOfMoves;

    void initializeBoard();
};
