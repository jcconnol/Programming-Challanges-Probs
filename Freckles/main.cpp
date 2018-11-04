/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 2, 2018, 9:01 AM
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

struct coord{
    float x;
    float y;
};

struct lengths{
    coord vert;
    float edge;
};

vector<coord> coord_vect;
vector<lengths> edge_vect;
vector<int> node_list;

float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

int find(int i) {
    if(node_list[i] == i){
        return i;
    }
    else{
        return (node_list[i] = find(node_list[i]));
    }
}

bool sortStruct(const lengths &first, const lengths &second){
    return first.edge < second.edge;
}

int main(int argc, char** argv) {
    
    int cases;
    scanf("%d", &cases);
    
    for(int i = 0; i < cases; i++){
        string holder;
        getline(cin, holder);
        
        coord_vect.clear();
        
        int freckNum;
        scanf("%d", &freckNum);
        for(int j = 0; j < freckNum; j++){
            float x,y;

            scanf("%f %f", &x, &y);
            coord curr;
            curr.x = x;
            curr.y = y;
            
            coord_vect.push_back(curr);
        }
        
        edge_vect.clear();
        for(int i = 0; i < freckNum; i++){
            for(int j = i+1; j < freckNum; j++){
                coord first = coord_vect[i];
                coord second = coord_vect[j];
                float dist = distance(first.x, first.y, second.x, second.y);
                coord holder;
                holder.x = i;
                holder.y = j;
                lengths leng_inclu;
                leng_inclu.edge = dist;
                leng_inclu.vert = holder;
                edge_vect.push_back(leng_inclu);
            }
        }
        
        sort(edge_vect.begin(), edge_vect.end(), sortStruct);
        node_list.clear();
        for(int i = 0; i < freckNum; i++){
            node_list.push_back(i);
        }
        
        double total_dist = 0;
        int size = edge_vect.size();
        
        for(int i = 0; i < size; i++){
            coord coord_hold = edge_vect[i].vert;
            if(!(find(coord_hold.x) == find(coord_hold.y))){
                node_list[find(coord_hold.x)] = find(coord_hold.y);
                total_dist += edge_vect[i].edge;
            }
        }
        cout << std::fixed << setprecision(2) << total_dist << endl;
        if(i != cases-1){
            cout << endl;
        }
    }
    
    return 0;
}