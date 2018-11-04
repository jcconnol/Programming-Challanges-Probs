/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 19, 2018, 10:56 PM
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

struct coord{
    int x;
    int y;
};

int input;
vector<coord> coordlist;

bool parsing(int A, int B){
    int lows = 0;
    int highs = 0;
    int evens = 0;
    int size = coordlist.size();
    for(int i = 0; i < size; i++){
        int answer = coordlist[i].x * A + coordlist[i].y * B;
        if(answer < 0){
            lows++;
        }
        else if(answer > 0){
            highs++;
        }
        else{
            evens++;
        }

        if(evens > 0){
            break;
        }

        if(lows > input || highs > input){
            break;
        }
    }
    
    if(evens == 0 && lows == input && highs == input){
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    
    while(scanf("%d", &input) != EOF){
        if(input == 0)
            break;
        
        int x,y;
        coordlist.clear();
        for(int i = 0; i < 2 * input; i++){
            scanf("%d%d", &x, &y);
            coord holder;
            holder.x = x;
            holder.y = y;
            coordlist.push_back(holder);
        }
        
        for(int A = -500; A <= 500; A++){
            for(int B = -500; B <= 500; B++){
                if(parsing(A, B)){
                    cout << A << " " << B << endl;
                    goto fin;
                }
            }
        }
        fin:;
    }
    
    return 0;
}

