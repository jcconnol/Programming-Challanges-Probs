/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 31, 2018, 8:30 AM
 */

#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;


int main() {
    
    //qwerty array
    char qwerty[4][13] = 
    {
        {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
        {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
        {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '+', '+'},
        {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', '+', '+', '+'}
    };
    
    string input;
    while(getline(cin, input)){
        int size = input.size();
        for(int i = 0; i < size; i++){
            if(input[i] == ' '){
                cout << " ";
            }
            else{
                //search qwerty
                for(int j = 0; j < 4; j++)
                    for(int k = 0; k < 13; k++)
                        if(qwerty[j][k] == input[i]){
                            cout << qwerty[j][k-1];
                        }

            }
        }
        cout << endl;
    }
    
    
    return 0;
}