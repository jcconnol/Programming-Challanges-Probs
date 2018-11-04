/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 4, 2018, 12:41 AM
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <ios>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct coord{
    int left;
    int right;
};

int boundry;
int pairs[55];
vector<coord> ordPairs;
int graph[55][55];

void swapCoord(int place){
    coord swapp = ordPairs[place];
    
    int tmp = swapp.left;
    swapp.left = swapp.right;
    swapp.right = tmp;
    
}

void addPoints(int left, int right){
    graph[left][right]++;
    graph[right][left]++;
    pairs[left]++;
    pairs[right]++;
}

void euclid(int start){
    for(int i = 1; i <= boundry; i++){
        if(graph[start][i]){
            graph[start][i]--;
            graph[i][start]--;
            euclid(i);
            coord startCoord;
            startCoord.left = start;
            startCoord.right = i;
            ordPairs.push_back(startCoord);
            
        }
    }
}

int main(int argc, char** argv) {

    int cases;
    scanf("%d", &cases);
    
    for(int i = 1; i <= cases; i++){
        
        for(int j = 0; j < 50; j++){
            pairs[j] = 0;
            for(int k = 0; k < 50; k++){
                graph[j][k] = 0;
            }
        }
        
        cout << "Case #" << i << endl;
        
        int beads;
        scanf("%d", &beads);
        boundry = 0;
        for(int j = 1; j <= beads; j++){
            int left, right;
            scanf("%d %d", &left, &right);
            
            addPoints(left, right);
            
            int largest = 0;
            if(left > right){
                largest = left;
            } else { largest = right; }
            if(largest > boundry){
                boundry = largest;
            }
            
        }
        
        bool missing = false;
        for(int j = 0; j < boundry; j++){
            if(pairs[j]%2 != 0){
                missing = true;
                break;
            }
        }
        
        if(missing){
            cout << "some beads may be lost" << endl;
        }
        else{
            ordPairs.clear();
            euclid(boundry);
            int size = ordPairs.size();
            if(ordPairs[0].right != ordPairs[size-1].left || size != beads){
                cout << ordPairs[0].left << " and " << ordPairs[size-1].right << endl;
                cout << "some beads may be lost?" << endl;
            }
            else{
                if(ordPairs[size-1].left != ordPairs[0].right){
                    swapCoord(size-1);
                }
                for(int j = 1; j < size; j++){
                    if(ordPairs[j-1].right != ordPairs[j].left){
                        swapCoord(j);
                    }
                }
                
                for(int j = size-1; j > -1; j--){
                    cout << ordPairs[j].left << " " << ordPairs[j].right << endl;
                }
            }
        }
        
        if(i != cases){
            cout << endl;
        }
    }
    
    return 0;
}

