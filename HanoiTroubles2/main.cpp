/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on March 1, 2018, 12:36 PM
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <ios>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    
    int times;
    scanf("%d", &times);
    
    for(int i = 0; i < times; i++){
        int peg_num;
        scanf("%d", &peg_num);
        
        vector< vector <int> > peg_sum(peg_num, vector<int>(1,0));
        int num_add = 0;
        int prev_num;
        
        while(true){
            for(int j = 0; j < peg_num; j++){
                if(peg_sum[j].back() == 0){
                    peg_sum[j].push_back(num_add);
                    prev_num = num_add;
                    break;
                }
                
                double square = sqrt(peg_sum[j].back() + num_add);
                int intsquare = square;
                
                if(square == intsquare){
                    peg_sum[j].push_back(num_add);
                    prev_num = num_add;
                    break;
                }
                if(j == peg_num-1){
                    goto cont;
                }
            }
            num_add++;
        }
        cont:
        
        cout << prev_num << endl;
    }
    
    return 0;
}

