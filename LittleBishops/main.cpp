/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 27, 2018, 3:57 PM
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(int argc, char** argv) {
    
    int board_size, pieces_num;
    while(scanf("%d %d", &board_size, &pieces_num)){
        
        if(board_size == 0 && pieces_num == 0){
            break;
        }
        int evens[10] = {0, 2, 2, 4, 4, 6, 6, 8};
        int odds[10] = {0, 1, 1, 3, 3, 5, 5, 7, 7};
        
        int board[10][70];
        int board2[10][70];
        
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= 69; j++){
                board[i][j] = 0;
                board2[i][j] = 0;
            }
        }
        
        for (int i = 0; i <= board_size; i++){
            board[i][0] = 1;
            board2[i][0] = 1;
        }
        
        for (int i = 1; i <= board_size; i++){
            for (int j = 1; j <= odds[i] && j <= pieces_num; j++){
                board[i][j] = board[i - 1][j] + board[i - 1][j - 1] * (odds[i] - j + 1);
            }
        }
        
        for (int i = 1; i <= board_size-1; i++){
            for (int j = 1; j <= evens[i] && j <= pieces_num; j++){
                board2[i][j] = board2[i - 1][j] + board2[i - 1][j - 1] * (evens[i] - j + 1);
            }
        }
        
        int total = 0;
        for(int i = 0; i <= pieces_num; i++){
            total += board[board_size][i] * board2[board_size-1][pieces_num-i];
        }
        
        cout << total << endl;
    }
    
    return 0;
}

