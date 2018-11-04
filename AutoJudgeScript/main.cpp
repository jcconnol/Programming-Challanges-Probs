/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 31, 2018, 6:07 PM
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

int main(int argc, char *argv[]) {
    
    int run = 1;
    while(true){
        
        int answer_num, input_num;
        string ans_string, inp_string;
        int level = 3;
        
        //convert  string to int
        getline(cin, ans_string);
        stringstream convert(ans_string);
        convert >> answer_num;
        
        if(answer_num == 0)
            return 0;
        
        vector<string> answer;
        vector<string> input;
        
        for(int i = 0; i < answer_num; i++){
            string holder;
            getline(cin, holder);
            answer.push_back(holder);
        }
        
        getline(cin, inp_string);
        stringstream convert2(inp_string);
        convert2 >> input_num;
        
        
        for(int i = 0; i < input_num; i++){
            string holder;
            getline(cin, holder);
            input.push_back(holder);
        }
        
        //level 3 is accepted
        if(level == 3){
            if(input_num == answer_num){
                for(int i = 0; i < answer_num; i++){
                    if(answer[i] != input[i]){
                        level--;
                        break;
                    }
                }
            }
            else
                level--;
        }
        
        //level 2 is presentation error
        if(level < 3){
            string ans_digits;
            string inp_digits;
            
            for(int i = 0; i < answer.size(); i++)
                for(int j = 0; j < answer[i].length(); j++)
                    if(isdigit(answer[i][j]))
                        ans_digits += answer[i][j];
                
            for(int i = 0; i < input.size(); i++)
                for(int j = 0; j < input[i].length(); j++)
                    if(isdigit(input[i][j]))
                        inp_digits += input[i][j];
            
            if(ans_digits != inp_digits){
                level--;
            }
        }
        
        cout << "Run #" << run << ": ";
        if(level == 3)
            cout << "Accepted";
        else if(level == 2)
            cout << "Presentation Error";
        else
            cout << "Wrong Answer";
        cout << endl;
        
        run++;
    }
    
    return 0;
}

