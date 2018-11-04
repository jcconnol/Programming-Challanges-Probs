/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 2, 2018, 11:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int day = 1;
    int runs = 0;
    
    while(scanf("%d", &runs) != EOF){
        
        int minutes[481];
        for(int i = 0; i < 480; i++)
            minutes[i] = 1;
        
        for(int i = 0; i < runs; i++){
            int start_min, start_hour;
            int end_min, end_hour;
            char description[250];
            
            scanf("%d:%d %d:%d%[^\n]", &start_hour, &start_min, &end_hour, &end_min, &description);
            
            end_min  = end_min + end_hour * 60;
            start_min = start_min + start_hour * 60;
                        
            for(int j = start_min; j < end_min; j++)
                minutes[j - 600] = 0;
            
        }
        
//        for(int i = 0; i < 480; i++)
//            cout << minutes[i];
//        cout << endl;
        
        //search for longest string of 1's
        int count = 0;
        int longest = 0;
        int start_nap;
        int beg = 0;
        
        for(int i = 0; i < 481; i++){
            if(minutes[i] == 1){
                count++;
                if(count == 1){
                    beg = i;
                }
            }
//            if(i == 479){
//                cout << "got here "<< endl;
//            }
            if(minutes[i] == 0 || i == 480){
                if(count > longest){
                    longest = count;
                    start_nap = beg+600;
                    beg = 0;
                }
                count = 0;
            }
        }
        
        cout << "Day #" << day << ": "
             << "the longest nap starts at " 
             << (start_nap)/60 << ":";
        
        if(((start_nap)%60) < 10)
            cout << "0";
        
        cout << ((start_nap+600)%60)
             << " and will last for ";
        
        if(longest/60){
            cout << longest/60 << " hours and " <<  longest%60 << " minutes.\n";
        }
        else{
            cout << longest << " minutes.\n";
        }
        
        day++;
    }
    
    return 0;
}