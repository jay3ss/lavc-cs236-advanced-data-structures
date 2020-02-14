#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>

using namespace std;
enum status {WIN, DRAW, CONTINUE};

class ticTacToe
{
public:
    /** Constructor
    @post: initializes the board to an empty state and sets the number of moves
    to zero (0) */
    ticTacToe();

    /** Starts and plays the game of tic tac toe.
    @post: the board will change according to the choices of the players */
    void play();

    /** Prints the board to the terminal
    @pre: the board must have been initialized */
    void displayBoard() const;

    // Determines if a move is valid
    // Precondition: the board must have been initialized
    bool isValidMove(const int x, const int y) const;

    // Returns the current player's symbol
    char currentPlayer() const;

    // Gets the move for a player
    bool getXOMove(const char moveSymbol);

    // Gets a player's move
    void getPlayerMove(int &row, int &col) const;

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

#endif // TICTACTOE_H
