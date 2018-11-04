/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 3, 2018, 10:00 AM
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

void flipArray(int array[30], int beg, int end){
    for(int i = beg; i <= end; i++){
        int temp = array[i];
        array[i] = array[end];
        array[end] = temp;
        end--;
        
    }
}

void printArr(int array[30], int size){
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    
    cout << endl;
}

int main(int argc, char** argv) { 
    string pan_stack;
    while(getline(cin, pan_stack)){
        
        int stack[30];
        
        stringstream stream(pan_stack);
        
        int size = 0;
        while(stream){
            int num;
            stream >> num;
            stack[size] = num;
            
            size++;
        }
        size--;
        
        printArr(stack, size);
        
        
       for(int i = size-1; i >= 0; i--){
            
            int largest_pos = 0;
            int largest = stack[i];
            
            for(int k = 0; k <= i; k++){
                if(stack[k] >= largest){
                    largest_pos = k;
                    largest = stack[k];
                }
            }
            
            if(largest_pos != i){
                if(largest_pos != 0){
                    cout << size-largest_pos << " ";

                    flipArray(stack, 0, largest_pos);
                }
                cout << size - i << " ";

                flipArray(stack, 0, i);

            }            
       }
       cout << "0" << endl;       
    }
    
    return 0;
}
