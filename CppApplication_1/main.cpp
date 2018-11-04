/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 21, 2017, 4:04 PM
 */

#include <iostream>
#include "tictactoe.h"

int main()
{

    TicTacToe Game;
    Game.drawBoard();

    do
    {

        Game.printTurn();

        if (Game.playerHuman())     // human turn?
            Game.humanMove();
        else
            Game.computerMove();

        Game.drawBoard();
        Game.nextTurn();

    }
    while (!Game.Winner() && !Game.fullBoard());

    return 0;
}
