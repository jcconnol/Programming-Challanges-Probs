#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    int i = 0;
    int rolls[5];
    int highest[15] = {0};

    while(scanf("%d%d%d%d%d", &rolls[0], &rolls[1], &rolls[2], &rolls[3], &rolls[4]) != EOF){
	int scores[15] = {0};
	int sum = 0;
	
	//gets all rolls and adds to each respective score
	for(int j = 0; j < 5; j++){
	    sum += rolls[j];
	    if(rolls[j] == 1)
		scores[0] += 1;
	    if(rolls[j] == 2)
		scores[1] += 2;
	    if(rolls[j] == 3)
		scores[2] += 3;
	    if(rolls[j] == 4)
		scores[3] += 4;
	    if(rolls[j] == 5)
		scores[4] += 5;
	    if(rolls[j] == 6)
		scores[5] += 6;
	}

	//adds bonus if applicable
	scores[6] = sum;
	int score_sum = 0;
	for(int j = 0; j < 6; j++){
	    score_sum += scores[j];
	}
										
	if(score_sum >= 63)
	    scores[13] = 35;

	int three_of_kind = 0;
	int four_of_kind = 0;
	//checks 3,4 and 5 of a kind
	for(int j = 0; j < 6; j++){
	    if(scores[j] == (j+1)*5){
		scores[9] = 50;
		scores[8] = sum;
		scores[7] = sum;
		scores[12] = 40;
		break;
	    }
	    else if(scores[j] == (j+1)*4){
		scores[8] += sum;
		scores[7] += sum;
		four_of_kind = j+1;
		break;
	    }
	    else if(scores[j] == (j+1)*3){
		scores[7] += sum;
		three_of_kind = j+1;
		break;
	    }
	}

	//short straight, could use recursion... don't really want to
	for(int j = 0; j < 2; j++){
	    if(rolls[j] == j+1){
		if(rolls[j+1] == j+2)
		    if(rolls[j+2] == j+3)
			if(rolls[j+3] == j+4)
			    scores[10] = 25;
	    }
	    else if(rolls[j] = j+2){
		if(rolls[j+1] == j+3)
		    if(rolls[j+2] == j+4)
			if(rolls[j+3] == j+5)
			    scores[10] = 25;
	    }
	}

	//long straight
	if(rolls[0] == 1){
            if(rolls[1] == 2)
                if(rolls[2] == 3)
                    if(rolls[3] == 4)
			if(rolls[4] == 5)
                            scores[11] = 35;
        }
        else if(rolls[0] == 2){
            if(rolls[1] == 3)
                if(rolls[2] == 4)
                    if(rolls[3] == 5)
			if(rolls[4] == 6)
                            scores[11] = 35;
        }

	//full house
	if(four_of_kind){
	    int num1 = 0;
	    for(int j = 0; j < 5; j++){
		if(rolls[j] == four_of_kind)
		    num1++;
	    }
	    if(num1 == 5)
		scores[8] = sum;
	}

	if(three_of_kind){
	    int num1 = 0;
	    int num2 = 0;
	    for(int j = 0; j < 5; j++)
		if(rolls[j] != three_of_kind)
		    num1 = rolls[j];
		else if(rolls[j] != three_of_kind && num1 != 0)
		    num2 = rolls[j];
	    
	    if(num2 == num1)
		scores[12] = 40;
	}

	//total
	for(int j = 0; j < 14; j++)
	    scores[14] += scores[j];
	
	for(int j = 0; j < 15; j++) cout << scores[j] << " ";
	cout << endl;
	//highest comparing
	if(scores[14] > highest[14])
	    for(int j = 0; j < 15; j++)
		highest[j] = scores[j];
	i++;
	//end of one set of rolls
	if(i > 12){
	    for(int t = 0; t < 15; t++){
		cout << highest[t] << " ";
		highest[t] = 0;
	    }
	    cout << endl;
	    i = 0;
	}
    }//end of scanf loop for rolls

    return 0;
}
