/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 18, 2018, 1:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int cases;
    cin >> cases;
    
    cout << cases << endl;
    
    for(int i = 0; i < cases; i++){
        int num_names;
        
        cin >> num_names;
        
        string names[num_names];
        int votes[num_names] = {0};
        //put all names in array
        for(int j = 0; j < num_names; j++){
            cin >> names[j];
            cout << names[j];
        }
        
        
        //scan through all numbers and add to array
        int ballot;
        int adding = 0;
        while(cin >> ballot){
            if(ballot == '\n'){
                break;
            }
            int holder = 0;
            //const char * str = ballot.c_str();
            //sscanf(str, "%d", &holder);
            //cout << holder << endl;
            
            votes[adding] += ballot;
            adding++;
            if(!(adding < num_names)){
                adding = 0;
            }
        }
        
        for(int i = 0; i < num_names; i++){
            
        }
        
    }
    
    return 0;
}

