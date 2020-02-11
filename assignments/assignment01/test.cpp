#include <cassert>
#include <iostream>
#include "TicTacToe.h"

using namespace std;

void displayStatus(ticTacToe &);

int main()
{

    ticTacToe game;

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

    // - 'O' doesn't start the game
    assert(!game.getXOMove('O'));

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
