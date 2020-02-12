#include <cassert>
#include <iostream>
#include "TicTacToe.h"

using namespace std;

void displayStatus(ticTacToe &);

int main()
{

    ticTacToe game;
    game.displayBoard();

    // When starting the game:
    // - its status should be CONTINUE
    assert(game.gameStatus() == CONTINUE);
    displayStatus(game);

    // - every move should be a valid move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(game.isValidMove(i, j));
        }
    }

    // - 'X' starts the game
    assert(game.getXOMove('X'));
    assert(game.currentPlayer() == 'X');

    // - 'O' doesn't start the game
    assert(!game.getXOMove('O'));
    assert(game.currentPlayer() != 'O');

    // A move can be made
    assert(game.makeMove(1, 1));

    // - attempting to make a move on that position is invalid
    assert(!game.isValidMove(1, 1));

    // - the current player has changed
    assert(game.currentPlayer() == 'O');
    assert(game.currentPlayer() != 'X');

    game.displayBoard();
}

void displayStatus(ticTacToe &game)
{
    cout << "The current game status is ";

    switch (game.gameStatus())
    {
    case WIN:
        cout << "WIN\n";
        break;
    case DRAW:
        cout << "DRAW\n";
        break;
    default:
        cout << "CONTINUE\n";
        break;
    }
}
