/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 25, 2018, 1:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void setup(long long arr[20][20][20]){
    arr[1][1][1] = 1;
    for(int j = 2; j < 14; j++){
        for(int r = 1; r < 14; r++){
            for(int p = 1; p < 14; p++){
                arr[j][r][p] = arr[j-1][r][p]*(j-2);
                arr[j][r][p] += arr[j-1][r-1][p];
                arr[j][r][p] += arr[j-1][r][p-1];
            }
        }
    }
}

int main(int argc, char** argv) {
    
    int times;
    scanf("%d", &times);
    long long arr[20][20][20] = {};
    
    setup(arr);
    
    for(int i = 0; i < times; i++){
        int queue_num, left, right;
       
        scanf("%d%d%d", &queue_num, &left, &right);
        cout << arr[queue_num][left][right] << endl;
        
    }
    
    return 0;
}

