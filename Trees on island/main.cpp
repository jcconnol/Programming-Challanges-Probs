/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on March 5, 2018, 9:24 AM
 */

#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct coord {
    int x;
    int y;
};
vector<coord> coordlist;

long long GCD(long long first, long long second){
    if (first == 0 || second == 0)
       return 0;
 
    if (first == second)
        return first;
 
    if (first <= second)
        return GCD(first, second-first);
    return GCD(first-second, second);
}

int main(int argc, char** argv) {
    //Pick's theorem
    int input;
    while(scanf("%d", &input) != EOF){
        if(input == 0){
            break;
        }
        
        coordlist.clear();
        
        for(int i = 0; i < input; i++){
            int x,y;
            scanf("%d%d", &x, &y);
            coord holder;
            holder.x = x;
            holder.y = y;
            
            coordlist.push_back(holder);
        }

        int size = coordlist.size();
        long long area = 0;
        for(int i=1;i<size;i++){
            int holder;
            if(i+1 < size){
                holder = i+1;
            }
            else{
                holder = i+1-size;
            }
            area += (long long)coordlist[i].x * (coordlist[holder].y - coordlist[i-1].y);
        }
        area +=(long long)coordlist[0].x*(coordlist[1].y-coordlist[size-1].y);

        if(area < 0){
           area = -area;
        }
        
        long long extPoint = input;
        for(int i=0,j=input-1;i<input;j=i++){
            coord holder;
            holder.x = abs(coordlist[j].x - coordlist[i].x);
            holder.y = abs(coordlist[j].y - coordlist[i].y);

            if(holder.x==0){
                extPoint += holder.y-1;
            }
            else if(holder.y==0){
                extPoint += holder.x-1;
            }
            else{
                extPoint += GCD(holder.x, holder.y) -1;
            }
        }
        
        cout << (long long) ((area-extPoint)/2)+1 << endl;
    }
    
    return 0;
}