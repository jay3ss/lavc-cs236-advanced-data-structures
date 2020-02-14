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

    /** Prints the board to the terminal. An empty board will print as

    1     2     3

    1     |     |
    ______|_____|_____
          |     |
    2     |     |
    ______|_____|_____
    3     |     |
          |     |

    and a board that is in play will look similar to

    1     2     3

    1   O |   X |   X
    ______|_____|_____
          |     |
    2     |   O |   X
    ______|_____|_____
    3     |     |
          |     |

    @pre: the board must have been initialized */
    void displayBoard() const;

    /** Determines if a move is valid. A valid move is one in which the x- and
        y-coordinates are both 1 <= (x, y) <= 3 and the space is not occupied
        (neither and 'X' or 'O' character occupies that space)
    @param x: the desired x-coordinate
    @param y: the desired y-coordinate
    @pre: the board must have been initialized
    @return: true if a move is valid and false if not */
    bool isValidMove(const int x, const int y) const;

    /** Returns the current player's symbol
    @return: 'X' for the 'X' player (player 1) and an 'O' character for the 'O'
    player (player 2) */
    char currentPlayer() const;

    /** Determines if it is the move for the passed-in character
    @pre: moveSymbol is either 'X' or 'O'
    @param moveSymbol: the char to be checked against (should be an 'X' or an
        'O')
    @return: true if the player's character move matches moveSymbol, false if
        not */
    bool getXOMove(const char moveSymbol);

    /** Gets a player's move
    @pre: 1 <= (row, col) <= 3
    @param row: the desired row
    @param col: the desired column
    @post: will change the board to be the player's character at the desired
        location (row, col) */
    void getPlayerMove(int &row, int &col) const;

    /** Determines the current status of the game
    @return: WIN if a player has won the game, DRAW if a stalemate has been
        reached, or CONTINUE if the game is still in progress */
    status gameStatus();

    /** Puts the player's character at the desired postion (row, column) on the
        board. Also checks if the desired move is a valid move (desired space
        not already occupied by a player character and 1 <= (row, column) <= 3)
    @param row: the desired row
    @param col: the desired column
    @return: true if the move succeeded (a valid move was given), false if the
        move did not succeed (an invalid move was given) */
    bool makeMove(const int row, const int col);

    /** Restarts the game
    @post: The board will be cleared of all moves */
    void restart();

private:
    char board[3][3];
    int noOfMoves;
    const int maxNoOfMoves = 9; // corresponds to a draw

    /** Initializes the board to have all empty cells (' ' character)
    @post: the board array will consist entirely of ' ' characters */
    void initializeBoard();

    /** Determines if an entire column has the same character in each cell
    @pre: 1 <= col <= 3
    @param col: the column to be checked
    @return: true if the column has the same character in each cell */
    bool isEntireColumnSame(const int col) const;

    /** Determines if an entire column is an 'X' or a 'O'
    @pre: 1 <= col <= 3
    @param col: the column to be checked
    @return: true if the column has only an 'X' or an 'O' in each cell */
    bool isEntireColumnXOrO(const int col) const;

    /** Determines if an entire row has the same character in each cell
    @pre: 1 <= row <= 3
    @param row: the row to be checked
    @return: true if the row has the same character in each cell */
    bool isEntireRowSame(const int row) const;

    /** Determines if an entire row is an 'X' or a 'O'
    @pre: 1 <= row <= 3
    @param row: the row to be checked
    @return: true if the row has only an 'X' or an 'O' in each cell */
    bool isEntireRowXOrO(const int row) const;

    /** Determines if either diagonal has the same character in each cell
    @return: true if either of the diagonals have all of the same character
        in each cell */
    bool areDiagonalsSame() const;

    /** Determines if either of the diagonals is all 'X's or 'O's
    @return: true if either of the diagonals of the board are all 'X's or all
    'O's in each cell */
    bool areDiagonalsAllXOrO() const;
};

#endif // TICTACTOE_H
