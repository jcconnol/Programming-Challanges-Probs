/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 30, 2018, 8:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    
    //maps names to ranks of people
    map<string, int> name_ranks;
    
    int scenario;
    scanf("%d", &scenario);
    
    for(int i = 0; i < scenario; i++){
        int num_papers, num_people;
        
        //maps one string to a vector of strings 
        map<string, vector<string> > ordered_people;
        cout << "Scenario " << i+1 << endl;
        scanf("%d%d", &num_papers, &num_people);
        
        
        
        string papers;
        cin.ignore();
        
        //put all names into array in order
        for(int t = 0; t < num_papers; t++){
            vector<string> list_people;
            
            getline(cin, papers);
            
            string person;
            int list_num = 0;
            int size = papers.size();
            int num = 0;
            for(int j = 0; j < size; j++){
                if(papers[j] == ',' && num == 1){
                    num = 0;
                    list_people.push_back(person);
                    list_num++;
                    j++;
                    person = "";
                }
                else if(papers[j] == ':'){
                    list_people.push_back(person);
                    list_num++;
                    person = "";
                    break;
                }
                else if(papers[j] == ',' && num != 1){
                    num++;
                    person += papers[j];
                }
                else
                    person += papers[j];
            }
            
            size = list_people.size();
            for(int j = 0; j < size; j++){ name_ranks[list_people[j]] = -50; }
            
            for(int j = 0; j < size; j++){
                
                for(int k = 0; k < size; k++){
                    if((list_people[k] != list_people[j]) && (ordered_people[list_people[j]].end() == find(ordered_people[list_people[j]].begin(), ordered_people[list_people[j]].end(), list_people[k]))){
                        ordered_people[list_people[j]].push_back(list_people[k]);
                    }
                }
            }
        }
        
        name_ranks["Erdos, P."] = 0;
        
        //set all people who authored with erdos to 1
        int erdo_size = ordered_people["Erdos, P."].size();
        for(int j = 0; j < erdo_size; j++){
            string holder = ordered_people["Erdos, P."][j];
            name_ranks[holder] = 1;
        }
        
        vector<string> second = ordered_people["Erdos, P."];
        
        while(!second.empty()){
            vector <string> first;
            
            int size = second.size();
            for(int j = 0; j < size; j++){
                int order_size = ordered_people[second[j]].size();
                for(int k = 0; k < order_size; k++){
                    if(name_ranks[ordered_people[second[j]][k]] < 0 
                            || (name_ranks[ordered_people[second[j]][k]] > name_ranks[second[j]] + 1)){
                        //go through ordered people from vector second and get number for rank if greater than switch
                        name_ranks[ordered_people[second[j]][k]] = name_ranks[second[j]] + 1;
                        first.push_back(ordered_people[second[j]][k]);
                    }
                }
            }
            second = first;
            first.clear();
        }
        //...please, never again.
        
        //start scanning names to output
        for(int i = 0; i < num_people; i++){
            string name;
            getline(cin, name);
            cout << name << " ";
            
            map<string, int>::iterator iter = name_ranks.find(name);
            if(iter == name_ranks.end() || iter->second < 0)
                cout << "infinity" << endl;
            else
                cout << iter->second << endl;
            
        }
    }
    return 0;
}


