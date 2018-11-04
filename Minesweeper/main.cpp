/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 17, 2018, 4:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    int count = 1;
    int vert, hori;
    
    //goes through one board at a time and outputs
    while(scanf("%d%d", &vert, &hori) != EOF){
        if(vert != 0 && hori != 0){
            int board[vert][hori];

            for (int i = 0; i < vert; i++)
                for (int j = 0; j < hori; j++)
                  board[i][j] = 0;

            for(int i = 0; i < vert; i++){
                char str[hori];
                scanf("%s", str);
                for(int j = 0; j < hori; j++){
                    if(str[j] == '*'){
                        board[i][j] = 10;
                        //add one to neighbors
                        if(i >= 1){
                            if(j >= 1)
                                board[i-1][j-1]++;
                            if(j+1 < hori)
                                board[i-1][j+1]++;

                            board[i-1][j]++;

                        }

                        if(j+1 < hori)
                            board[i][j+1]++;
                        if(j >= 1)
                            board[i][j-1]++;

                        if(i+1 < vert){
                            if(j >= 1)
                                board[i+1][j-1]++;
                            if(j+1 < hori)
                                board[i+1][j+1]++;

                            board[i+1][j]++;

                        }
                    }
                }
            }

            //go through array and output numbers
            //if larger than 8 then output a '*'
            if(vert != 0 && hori != 0){
                if(count != 1){
                    cout << "\n";
                }
                cout << "Field #" << count << ":\n";
                for(int i = 0; i < vert; i++){
                    for(int j = 0; j < hori; j++){
                        if(board[i][j] < 10)
                            cout << board[i][j];
                        else
                            cout << "*";
                    }
                    cout << "\n";
                }
                
            }
        }
        count++;
    }
    
    return 0;
}