/*
 *Course: CS215 - 00x
 *Project: Lab 8 (As part of Project 2)
 *Purpose: It demonstrates the game of Nim played between two computer players
 *         In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *         is a first-player-win if with perfect play the first player to move can always force a win.
 *         This program also shows that the game of Nim is a "CONDITIONAL first-player-win" game using two computer players.
 *Author: (your name)
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

int main()
{
    int seed = static_cast<int>(time(0));
    srand(seed);

    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    // for testing purpose only: we set the initial size of pile to a constant PILE_SIZE_TEST
    // int pileSize = PILE_SIZE_TEST;

    // comment out the testing purpose at line number 27, enable the following statement, which is the general case
    int pileSize = PILE_MIN + rand() % (PILE_MAX - PILE_MIN + 1);

    // create a Nim object with initial pile size = pileSize
    Nim NimGame(pileSize);

    cout << "**********************************************************************" << endl;
    cout << "* In combinatorial game theory:                                      *" << endl;
    cout << "*  a two-player deterministic perfect information turn-based game    *" << endl;
    cout << "*               is a first-player-win, if with perfect play          *" << endl;
    cout << "*       the first player to move, can always force a win.            *" << endl;
    cout << "* I will show you (not prove to you) that                            *" << endl;
    cout << "*       the game of Nim is a CONDITIONAL first-player-win game :)    *" << endl;
    cout << "*                    The game of Nim                                 *" << endl;
    cout << "*   Two players alternate taking at least one but at most half       *" << endl;
    cout << "*                         of the marbles in the pile.                *" << endl;
    cout << "*   The player who takes the last marble loses.                      *" << endl;
    cout << "**********************************************************************" << endl;

    bool PIKE_turn = true;
    cout << "PIKE and SUPER are two computers. " << endl;
    cout << "They play the game of Nim." << endl << endl;
    cout << "PIKE always starts first!!! SUPER plays the second." << endl;
    cout << endl << endl;

    while (NimGame.getPileSize() > 1)
    {
        NimGame.print();
        if (PIKE_turn) //it is PIKE's turn to play
        {
            cout << "It is PIKE's turn:" << endl;
            NimGame.computer_play();
        }
        else   // it is SUPER's turn to play
        {
            cout << "It is SUPER's turn:" << endl;
            NimGame.computer_play();
        }

        PIKE_turn = !PIKE_turn;
    }

    //check the which one has to take the last marble to lose the game
    if (PIKE_turn)  // PIKE's turn (for this program, this will never happen as long as PIKE is the first player!
    {
        cout << "Computer PIKE must take the last marble. "
            << "Computer SUPER wins!" << endl;
    }
    else   // SUPER's turn
    {
        cout << "Computer SUPER must take the last marble. "
            << "Computer PIKE wins!" << endl;
    }
    return 0;
}