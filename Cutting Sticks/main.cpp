/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 5, 2018, 7:10 PM
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <ios>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int combin[55][55];

int lower(int one, int two){
    if(one < two)
        return one;
    return two;
}

int main(int argc, char** argv) {
    int length;
    
    while(scanf("%d", &length) != EOF){    
        if(length == 0){
            break;
        }
        
        int cut_num;
        scanf("%d", &cut_num);
        
        vector<int> cuts;
        cuts.push_back(0);
        for(int i = 0; i < cut_num; i++){
            int holder;
            scanf("%d", &holder);
            cuts.push_back(holder);
        }
        cuts.push_back(length);
        
        for(int i = 0; i <= 52; i++){
            for(int j = 0; j <= 52; j++){
                combin[i][j] = 0;
            }
        }
        
        int cost = 100000;
        int m, j, k;
        for(int i = 2; i <= cut_num+1; i++){
            for(j = 0; j <= ((cut_num+1) - i); j++){
                m = j + i;
                combin[j][m] = cost;
                for(k = j+1; k < m; k++){
                    combin[j][m] = lower(combin[j][m], combin[j][k] + combin[k][m] + (cuts[m] - cuts[j]));
                }
            }
        }
        
        cout << "The minimum cutting is " << combin[0][cut_num+1] << "." << endl;
    }
    
    return 0;
}