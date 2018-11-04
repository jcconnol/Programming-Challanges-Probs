/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 26, 2018, 9:38 AM
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

struct Cube{
    int bottom, back, right, left, top, front;
};

int main(int argc, char** argv) {
    int input;
    while(scanf("%d", &input) != EOF){
        if(input == 0){
            break;
        }
        
        vector<Cube> cubelist;
        for(int i = 0; i < input; i++){
            Cube cube;
            scanf("%d%d%d%d%d%d", 
                    &cube.front, 
                    &cube.back, 
                    &cube.left,
                    &cube.right, 
                    &cube.top, 
                    &cube.bottom);
            cubelist.push_back(cube);
        }
        
        
    }
    
    return 0;
}

