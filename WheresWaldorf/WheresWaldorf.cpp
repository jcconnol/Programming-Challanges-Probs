/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 31, 2018, 5:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    //find starting letter
    //search all around it and if second letter is equal
    //go in that direction until end of string. if not equal stop and keep looking
    
    int runs;
    scanf("%d", &runs);
    
    char blank[1];
    scanf("%[^\n]", blank);
    
    for(int i = 0; i < runs; i++){
        
        int x, y;
        scanf("%d%d", &y, &x);
        
        char board[y][x];
        cout << endl << endl;
        //read in board and put into array
        
        for(int j = 0; j < y; j++){
            char row[50];
            scanf("%s", row);
            for(int k = 0; k < x; k++){
                board[j][k] = row[k];
            }
            
        }
        
        int find_num;
        scanf("%d", &find_num);
        
        for(int j = 0; j < find_num; j++){
            string name;
            scanf("%s", &name);
            cout << name << endl;
            int size = name.size();
            int x_and_y[2];
            
            for(int k = 0; k < y; k++){
                for(int m = 0; m < x; m++){
                    string name_comp = "";
                    if(board[k][m] == name[0]){
                        if(m > 0 && k > 0 && board[k-1][m-1] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k-n][m-n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                            
                        }
                        else if(m > 0 && board[k-1][m] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k-n][m];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(m < x-2 && k > 0 && board[k-1][m+1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k-n][m+n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(m > 0 && board[k][m-1] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k][m-n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(m < x-2 && board[k][m+1] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k][m+n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(k < y-2 && m > 0 && board[k+1][m-1] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k+n][m-n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(k < y-2 && board[k+1][m] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k+n][m];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                        else if(k < y-2 && m < x-2 && board[k+1][m+1] == name[1]){
                            for(int n = 0; n < size; n++){
                                name_comp += board[k+n][m+n];
                            }
                            if(name_comp == name){
                                k=y;
                                x_and_y[0] = k;
                                x_and_y[1] = m;
                                break;
                            }
                        }
                    }
                }
            }
            
            cout << x_and_y[0] << " " << x_and_y[1] << endl;
        }
    }
    
    
    return 0;
}


