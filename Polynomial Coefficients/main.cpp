/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 12, 2018, 11:31 PM
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
    
    int power, num;
    //to calculate the coefficiten of an element, n!/(n1! * n2! ...)
    while(scanf("%d %d", &power, &num) != EOF){
        
        long int denom = 1;
        for(int i = 0; i < num; i++){
            int holder;
            scanf("%d", &holder);
            
            long int fact = 1;
            for(int i = holder; i > 0; i--){
                fact *= i;
            }
            
            denom *= fact;
        }
        
        long int numerator = 1;
        for(int i = power; i > 0; i--){
            numerator *= i;
        }
        
        cout << numerator/denom << endl;
        
    }
    
    return 0;
}

