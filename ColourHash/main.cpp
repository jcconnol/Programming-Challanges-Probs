/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 26, 2018, 6:31 PM
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> move_map;
string possible;
string solved = "034305650121078709t90121";

string LWC(string wheel){
    
    char temp1 = wheel[10];
    char temp2 = wheel[11];
    
    for(int i = 11; i >= 2; i--){
        wheel[i] = wheel[i-2];
    }
    
    wheel[0] = temp1;
    wheel[1] = temp2;
    
    wheel[21] = wheel[9];
    wheel[22] = wheel[10];
    wheel[23] = wheel[11];
    
    return wheel;
}

string RWC(string wheel){
    char temp1 = wheel[12];
    char temp2 = wheel[13];
    
    for(int i = 14; i <= 23; i++){
        wheel[i-2] = wheel[i];
    }
    
    wheel[22] = temp1;
    wheel[23] = temp2;
    
    wheel[9] = wheel[21];
    wheel[10] = wheel[22];
    wheel[11] = wheel[23];
    
    return wheel;
}

string LWCC(string wheel){
    char temp1 = wheel[0];
    char temp2 = wheel[1];
    
    for(int i = 2; i <= 11; i++){
        wheel[i-2] = wheel[i];
    }
        
    wheel[10] = temp1;
    wheel[11] = temp2;
    
    wheel[21] = wheel[9];
    wheel[22] = wheel[10];
    wheel[23] = wheel[11];
    
    return wheel;
}

string RWCC(string wheel){
    char temp1 = wheel[22];
    char temp2 = wheel[23];
    
    for(int i = 23; i >= 14; i--){
        wheel[i] = wheel[i-2];
    }
        
    wheel[12] = temp1;
    wheel[13] = temp2;
    
    wheel[9] = wheel[21];
    wheel[10] = wheel[22];
    wheel[11] = wheel[23];
    
    return wheel;
}

bool forBacktrackBool(string wheel, string answer){
    if(move_map.count(wheel)){
        if(possible == "0" || possible.size() > answer.size() + move_map[wheel].size() 
                || (move_map[wheel].size() == answer.size()  + move_map[wheel].size() && move_map[wheel] > answer)){
            return true;
        }
    }
    
    return false;
}

void forward_backtrack(int prev, int inc, string wheel, string answer){
    if(inc == 9){
        return;
    }
    
    if(forBacktrackBool(wheel, answer)){
        possible = answer + move_map[wheel];
    }
    
    if(prev != 3){
        forward_backtrack(1, inc+1, LWC(wheel), answer+'1');
    }
    if(prev != 4){
        forward_backtrack(2, inc+1, RWC(wheel), answer+'2');
    }
    if(prev != 1){
        forward_backtrack(3, inc+1, LWCC(wheel), answer+'3');
    }
    if(prev != 2){
        forward_backtrack(4, inc+1, RWCC(wheel), answer+'4');
    }
    
}

bool reverseBool(string wheel, string answer){
    if(!move_map.count(wheel) || move_map[wheel].size() > answer.size() 
            || (move_map[wheel].size() == answer.size() && move_map[wheel] > answer)){
        return true;
    }
    return false;
}

void reverse_backtrack(int prev, int inc, string wheel, string answer){
    if(inc == 9){
        return;
    }
    
    //if(reverseBool(wheel, answer)){
    if(reverseBool(wheel, answer)){
        move_map[wheel] = answer;
    }
    
    if(prev != 1){
        reverse_backtrack(3, inc+1, LWCC(wheel), '1'+answer);
    }
    if(prev != 2){
        reverse_backtrack(4, inc+1, RWCC(wheel), '2'+answer);
    }
    if(prev != 3){
        reverse_backtrack(1, inc+1, LWC(wheel), '3'+answer);
    }
    if(prev != 4){
        reverse_backtrack(2, inc+1, RWC(wheel), '4'+answer);
    }
}

int main(int argc, char** argv) {
    
    //3^8 +3^8 much smaller than 3^16
    //10 is 2 digits so make letter
    
    int times;
    scanf("%d", &times);
    
    for(int i = 0; i < times; i++){
        string wheel_string = "";
        
        for(int j = 0; j < 24; j++){
            int input;
            cin >> input;
            if(input != 10)
                wheel_string += '0' + input;
            else
                wheel_string += 't';
        }
        
        if(wheel_string == solved){
            cout << "PUZZLE ALREADY SOLVED" << endl;
        }
        else{
            
            possible = "0";
            reverse_backtrack(0, 0, solved, "");
            forward_backtrack(0,0, wheel_string, "");
//            for(map<string,string>::iterator it = move_map.begin(); it != move_map.end(); it++){
//                cout << it->first << " => " << it->second << '\n';
//            }
            
            if(possible != "0"){
                cout << possible << endl;
            }
            else
                cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
                
        }
    }
    
    return 0;
}

