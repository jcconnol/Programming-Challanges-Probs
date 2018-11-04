/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on March 5, 2018, 9:24 AM
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

int node_num, edge_num;
int edge_from;
int edge_to;
vector<int> colors;
vector< vector<int> > graph;

bool coloring(){
    bool bicolorable = true;
    vector<int> order;
    colors.assign(node_num, 10000000);
    colors[0] = 0;
    order.push_back(0);
    
    while(!order.empty() && bicolorable){
        int front = order[0];
        order.erase(order.begin());
        for(int i = 0; i < graph[front].size(); i++){
            int num = graph[front][i];
            if(colors[num] == 10000000) {
                colors[num] = 1 - colors[front];
                order.push_back(num);
            }
            else if(colors[graph[front][i]] == colors[front]){
                return false;
            }
        }
    }
    return bicolorable;
}

void addNodeEdge(){
    graph[edge_from].push_back(edge_to);
    graph[edge_to].push_back(edge_from);
}

int main(int argc, char** argv) {
    while(true){
        graph.clear();
        colors.clear();
        scanf("%d", &node_num);
        
        if(node_num == 0){
            break;
        }
        
        scanf("%d", &edge_num);
        
        for(int i = 0; i <= node_num; i++){
            vector<int> holder;
            graph.push_back(holder);
        }
        
        for(int i = 0; i < edge_num; i++){
            scanf("%d %d", &edge_from, &edge_to);
            addNodeEdge();
        }
        
        if(coloring()){
            cout << "BICOLORABLE.";
        }
        else{
            cout << "NOT BICOLORABLE.";
        }
        cout << endl;
    }
    return 0;
}
