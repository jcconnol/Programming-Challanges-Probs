/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 7, 2018, 8:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void printArray(T arr[11]){
    for(int i = 0; arr[i] != '\0'; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void flipArray(char arr[11]){
    int size;
    for(size = 0; arr[size] != '\0'; size++){}
    
    for(int i = 0; i < size/2; i++){
        swap(arr[i], arr[size-1-i]);
    }
    
}

int main(int argc, char** argv) {
    
    char first[11];
    char second[11];
    while(scanf("%s %s", &first, &second) != EOF){
        
        if(first[0] == '0' && second[0] == '0'){
            return 0;
        }
        
        flipArray(first);
        flipArray(second);
        
        int first_int[11];
        int second_int[11];
        for(int i = 0; i < 11; i++){
            first_int[i] = 0;
            second_int[i] = 0;
        }
        
        for(int i = 0; first[i] != '\0'; i++){
            first_int[i] = first[i] - '0';
        }
        for(int i = 0; second[i] != '\0'; i++){
            second_int[i] = second[i] - '0';
        }
        
        //get size of array and make everything after the number zeros and keep parsing the whole arrays
        int operations = 0;
        for(int i = 0; i < 11; i++){
            int sum_dig = first_int[i] + second_int[i];
            if(sum_dig > 9){
                operations++;
                first_int[i+1] = first_int[i+1] + (sum_dig / 10);
            }
        }
        
        if(operations == 0){
            cout << "No carry operation.";
        }
        else if(operations == 1){
            cout << "1 carry operation.";
        }
        else{
            cout << operations << " carry operations.";
        }
        cout << endl;
        
    }
    
    return 0;
}

