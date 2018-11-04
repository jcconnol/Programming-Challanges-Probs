/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 2, 2018, 11:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
    int runs;
    scanf("%d", &runs);
    
    for(int i = 0; i < runs; i++){
        char blank[1];
        scanf("%[^\n]", &blank);
        
        int dayPay[24];
        for(int j = 0; j < 24; j++)
            scanf("%d", &dayPay[j]);
        
        char license[21];
        char on[6];
        char exit[50];
        int month, day, hour, minute;
        
        //check this...
        scanf("%s %d:%d:%d:%d %s %d", &license, &month, &day, &hour, &minute, &on, &exit);
        
        cout << license << endl;
        cout << month << endl;
        cout << day << endl;
        cout << hour << endl;
        cout << minute << endl;
        
    }
    
    return 0;
}

