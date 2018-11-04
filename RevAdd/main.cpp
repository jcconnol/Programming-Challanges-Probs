/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 7, 2018, 7:15 AM
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

template<typename ValueType>
std::string stringulate(ValueType v)
{
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

bool palendrome(string number){
    int size = number.size();
    
    for(int i = 0; i < size/2; i++){
        if(number[i] != number[size-i-1]){
            return false;
        }
    }
    
    return true;
}

long StringToInt(string number){
    
    long num;
    stringstream ss(number);
    ss >> num;
    return num;
    
}

string flipString(string str){
    long size = str.size();
    string newStr;
    for(int i = size-1; i >= 0; i--){
        newStr += str[i];
    }
    
    return newStr;
}

int main(int argc, char** argv) {
    string runs_str;
    getline(cin, runs_str);

    int runs = StringToInt(runs_str);
    
    for(int i = 0; i < runs; i++){
        string num_orig;
        int iterations = 0;
        getline(cin, num_orig);
        
        do{
            iterations++;
            
            long orig = StringToInt(num_orig);
            string num_rev = flipString(num_orig);
            long rever = StringToInt(num_rev);
            
            long sum = orig + rever;
            
            num_orig = stringulate(sum);
            
        } while(num_orig.size() && palendrome(num_orig) == 0);
        
        cout <<  iterations << " " << num_orig << endl;
    }
    
    return 0;
}

