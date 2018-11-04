/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 22, 2018, 12:42 PM
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

int * euclid(int arr[]){
    if(arr[1] == 0){
        return arr;
    }

    int hold_quot = (arr[0]) / (arr[1]);
    int moding = (arr[0]) % (arr[1]);
    
    arr[6] = arr[2] - hold_quot * (arr[4]);
    arr[7] = arr[3] - hold_quot * (arr[5]);
    arr[0] = arr[1];
    arr[1] = moding;
    
    arr[2] = arr[4];
    arr[4] = arr[6];
    
    arr[3] = arr[5];
    arr[5] = arr[7];
    
    euclid(arr);
}

int main(int argc, char** argv) {
    
    int a, b, d;
    
    while(scanf("%d %d", &a, &b)){
        
        int arr[8];
        arr[0] = a;
        arr[1] = b;
        arr[4] = 0;
        arr[5] = 1;
        arr[2] = 1;
        arr[3] = 0;
        
        euclid(arr);
        
        cout << arr[2] << " " << arr[3] << " " << arr[0] << endl;
    }
    
    return 0;
}

