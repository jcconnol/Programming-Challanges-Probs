/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 2, 2018, 11:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    
    int runs;
    
    scanf("%d", &runs);
    
    for(int i = 0; i < runs; i++){
        
        int relatives;
        scanf("%d", &relatives);
        
        if(relatives == 1){
            cout << "0" << endl;
        }
        else{
            int street_nums[30000];

            //read in street nums
            for(int j = 0; j < relatives; j++){
                scanf("%d", &street_nums[j]);
            }

            //sort street nums
            int temp;
            for(int j = relatives-1; j > 0; j--){
                for(int k = 0; k < j; k++){
                    if(street_nums[k] > street_nums[k+1]){
                        temp = street_nums[k];
                        street_nums[k] = street_nums[k+1];
                        street_nums[k+1] = temp;

                    }
                }
            }

            //find median for vitos house
            long median = 0.0;
            if((relatives%2) == 0)
                median = (street_nums[relatives/2]+street_nums[(relatives/2)-1])/2.0;
            else
                median = street_nums[(relatives/2)];
                        
            //find difference and add up
            long distance = 0;
            for(int j = (relatives/2)-1; j < relatives; j++){
                distance += abs(median - (long)street_nums[j]);
            }

            for(int j = 0; j < (relatives/2)-1; j++){
                distance += abs(median - (long)street_nums[j]);
            }

            cout << distance << endl;
        
        }
    }
    
    return 0;
}

