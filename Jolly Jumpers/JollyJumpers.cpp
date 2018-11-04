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
#include <cmath>

using namespace std;

int main() {
    
    int diff;
    while(scanf("%d", &diff) != EOF){
	if(diff > 1){
	    int first, second;
	    bool jolly = true;

	    scanf("%d", &second);
	    int diff2 = diff-1;
	    int check[diff2];
	    
	    for(int i = 0; i < diff; i++)
		check[i] = 0;
	    
	    for(int i = diff2; i > 0; i--){
		
	        first = second;
	        scanf("%d", &second);
		
	        if(abs(second - first) < diff+1)
		    check[abs(second - first)] = 1;
	    }
	    
	    for(int i = 1; i <= diff2; i++){
		if(check[i] == 0){
		    jolly = false;
		    break;
		}
	    }

	    if(jolly)
	        cout << "Jolly\n";
	    else
	        cout << "Not jolly\n";
	}

	else{
	    int holder;
	    for(int i = diff; i > 0; i--)
		scanf("%d", &holder);
	     cout << "Jolly\n";
    	}
    }

    return 0;
}
