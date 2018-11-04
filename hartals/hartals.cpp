/*
By: John Connolly
Hartels Programming Challenge
*/


#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    
    int tests;
    scanf("%d", &tests);
    
    for(int t = 0; t < tests; t++){
	int num_days;
	scanf("%d", &num_days);
	
	int parties;
	scanf("%d", &parties);
	
	bool schedule[parties][num_days];
	for(int i = 0; i < parties; i++)
	    for(int j = 0; j < num_days; j++)
		schedule[i][j] = 0;

	for(int i = 0; i < parties; i++){
	    int hartal;
	    scanf("%d", &hartal);
	    
	    for(int j = 0; j < num_days; j++){
	        if(j%hartal == hartal-1)
	            schedule[i][j] = 1;
		}
	}

	int days_lost = 0;
	for(int i = 0; i < num_days; i++){
	    if(i%7 == 0 || i%7 == 1 || i%7 == 2 || i%7 == 3 || i%7 == 4){
		for(int j = 0; j < parties; j++){
		    if(schedule[j][i] == 1){
			days_lost++;
			break;
		    }
		}
	    }
	}
	cout << days_lost << endl;
    }

    return 0;
}

