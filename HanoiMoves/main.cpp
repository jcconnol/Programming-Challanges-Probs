/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 13, 2018, 8:24 AM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<long long int> fibonacci;
    fibonacci.push_back(1);
    fibonacci.push_back(1);
        
    long long int first, second;
    while(scanf("%ld %ld", &first, &second)){
        if(first == 0 && second == 0){
            return 0;
        }
        int count = 0;
        
        while(fibonacci.back() <= second){
            if(fibonacci.back() >= first){
                count++;
            }
            
            //add element to end of vector that is addition of prev two
            fibonacci.push_back(*(fibonacci.rbegin()) + *(fibonacci.rbegin()+1));
        }
        
        cout << count << endl;
    }
    
    return 0;
}

