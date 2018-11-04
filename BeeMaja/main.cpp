/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 14, 2018, 11:19 AM
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

map<int, coord> mapping;

void addToMap(int x, int y, int ring){
    coord holder;
    holder.x = x;
    holder.y = y;
    mapping[ring] = holder;
}

void findingAndAdding(int input){
    int ring = 1;
    int count = 0;
        
    while(ring < input){
        count++;
        ring += 6*count;
    }

    int x = count;
    int y = 0;
    while(ring != input){
        while(ring != input && y+count != 0){
            addToMap(x, y, ring);
            y--,ring--;
        }
        while(ring != input && x != 0){
            //addToMap(x, y, ring);
            x--,ring--;
        }
        while(ring != input && y != 0){
            addToMap(x, y, ring);
            x--; y++; ring--;
        }
        while(ring != input && y != count){
            addToMap(x, y, ring);
            y++; ring--;
        }
        while(ring != input && x != 0){
            addToMap(x, y, ring);
            x++; ring--;
        }
        while(ring != input && x != count){
            addToMap(x, y, ring);
            x++; y--; ring--;
        }
    }
    addToMap(x, y, ring);
}

int main(int argc, char** argv) {
    int input;
    while(scanf("%d", &input) != EOF){
        if(mapping.count(input) > 0){
            cout << mapping[input].x << " " << mapping[input].y << endl;
        }
        else{
            findingAndAdding(input);
            //for (map<int,coord>::iterator it=mapping.begin(); it!=mapping.end(); ++it)
            //    cout << it->first << " => " << it->second.x << "  " << it->second.y << '\n';
            
            cout << mapping[input].x << " " << mapping[input].y << endl;
        }
    }
    
    return 0;
}