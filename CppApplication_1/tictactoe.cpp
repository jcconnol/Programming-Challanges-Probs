// tictactoe.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    srand (time(0));

    player = 1;           // who starts first?
    totalTurns = 0;

    // new player setup
    numberPlayers = 2;
    playerType[1] = 1;  // playerType[player] is human (1)
    playerType[2] = 0;  // playerType[player] is computer (0)
    //playerType[3] = 0;  // playerType[player] is computer (0)

    //for (int &i : pos)  // new C++0x feature
    //    i = 0;

    for (int i = 0; i < 9; i++)
        pos[i] = 0;

}

void TicTacToe::drawBoard()
{

    std::cout   << std::endl
                << pos[0] << " │ " << pos[1] << " │ " << pos[2]
                << "\n──┼───┼──\n"
                << pos[3] << " │ " << pos[4] << " │ " << pos[5]
                << "\n──┼───┼──\n"
                << pos[6] << " │ " << pos[7] << " │ " << pos[8]
                << std::endl;

}

void TicTacToe::printTurn()
{
    std::cout << "\nPlayer " << player << "'s turn.\n";
}

void TicTacToe::nextTurn()
{
    totalTurns++;

    if (++player > numberPlayers)
        player = 1;
}

bool TicTacToe::playerHuman()
{
    return playerType[player];
}

void TicTacToe::humanMove()
{

    std::cout << "\nEnter your move: ";
    int move;

    do
    {
        std::cin >> move;
        move--;     // so user can enter 1-9 instead of 0-8
    }
    while (move < 0 || move > 8 || pos[move] != 0);

    pos[move] = player;
}

void TicTacToe::computerMove()
{

    int move;

    do
    {
        move  = rand() % 9;     // just pick a random number
    }
    while (move < 0 || move > 8 || pos[move] != 0);

    pos[move] = player;

}

bool TicTacToe::Winner()
{
    int board[8][3] = {{0,1,2},
                       {3,4,5},
                       {6,7,8},
                       {0,3,6},
                       {1,4,7},
                       {2,5,8},
                       {0,4,8},
                       {2,4,6}}; // winning possibilities

    for (int i = 0; i < 8; i++) // scroll through possibilities
    {
        if ((pos[board[i][0]] == pos[board[i][1]])
            && (pos[board[i][1]] == pos[board[i][2]])
            && pos[board[i][0]] != 0)
        {

            std::cout << "\nPlayer " << pos[board[i][0]]
                      <<  " wins!\n\n";

            return 1;    // return winner true
        }
    }

    return 0;   // winner false
}

bool TicTacToe::fullBoard()
{
    if (totalTurns == 9)
    {
        std::cout << "\nTie game!\n\n";
        return 1;
    }
    else
        return 0;
}