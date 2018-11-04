/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 17, 2018, 11:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

/*
 * 
 */
int main() {
    
    int counter;
    
    long long int i;
    int j;

    while(scanf("%d%d", &i, &j) != EOF){
        bool switching = 0;
        int highest = 0;
        if(i > j){
            int temp = j;
            j=i;
            i=temp;
            switching = 1;
        }
            
        
        for(int n = j; n >= i; n--){
            counter = 0;
            long long int hold = n;
            while(hold != 1){            
                if(hold%2)
                    hold = 3 * hold + 1;

                else
                    hold = hold / 2;
                                
                counter++;   
            }
            if(hold == 1)
                counter++;

            if(counter > highest)
                highest = counter;
        }
        if(switching)
            cout << j << " " << i << " " << highest << endl;
        else
            cout << i << " " << j << " " << highest << endl;
    }
    
    return 0;
}