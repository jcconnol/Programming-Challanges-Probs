/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 7, 2018, 9:41 AM
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
//TODO change height to weight
//use two bool functions

struct elephant{
    int weight;
    int IQ;
    int ind;
};

vector<elephant> all_eleph;
//int order[size];
vector<int> order;
vector<int> points;
//int dp[size];

bool sortStruct(const elephant &first, const elephant &second){
    return first.weight < second.weight;
}

elephant highestIQ(elephant ele1, elephant ele2){
    if(ele1.IQ > ele2.IQ){
        return ele1;
    }
    return ele2;
}

elephant highestHeight(elephant ele1, elephant ele2){
    if(ele1.weight > ele2.weight){
        return ele1;
    }
    return ele2;
}

void checking(int i){
    int size = all_eleph.size();
    for(int j = i+1; j < size; j++){
        if(all_eleph[i].weight < all_eleph[j].weight && all_eleph[i].IQ > all_eleph[j].IQ){
            if((1+points[j]) > points[i]){
                points[i]=1+points[j];
                order[i]=j;
            }
        }
    }
}

int main(int argc, char** argv) {
    int height, IQ;
    int size = 0;
    while(scanf("%d %d", &height, &IQ) != EOF){
        elephant ele;
        ele.weight = height;
        ele.IQ = IQ;
        ele.ind = size+1;
        all_eleph.push_back(ele);
        size++;
    }
    
    sort(all_eleph.begin(), all_eleph.end(), sortStruct);
    
    order.assign(size, 0);
    points.assign(size, 0);
    int answer = 0;
    int start;
    //int size = all_eleph.size();
    for(int i = size-1; i >= 0; i--){
        points[i] = 1;
        order[i] = -1;
        
        checking(i);
        
        if(points[i]>answer){
            answer=points[i];
            start=i;
        }
    }
    
    cout << answer << endl;
    for(int i = start; i != -1; i = order[i]){
        cout << all_eleph[i].ind << endl;
    }
    
    return 0;
}

