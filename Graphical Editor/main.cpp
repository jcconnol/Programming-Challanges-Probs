/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on January 18, 2018, 6:14 PM
 */
   
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int fill (char table[250][250], int top, int side, int x, int y, char region, char color){
    //find if in region and go through all around it until hit something else
    table[y][x] = color;
    
    //goes to the side boundary
    if((x < side-1) && (table[y][x+1] == region)){
        fill(table, top, side, x+1, y, region, color);    
    }
    //goes to lower boundary
    if((y < top-1) && (table[y+1][x] == region))
        fill(table, top, side, x, y+1, region, color);
    
    //goes to left boundary
    if((x > 0) && (table[y][x-1] == region))
        fill(table, top, side, x-1, y, region, color);
    
    //goes to upper boundary
    if((y > 0) && (table[y-1][x] == region))
        fill(table, top, side, x, y-1, region, color);
    
    return 0;
}

int main() {
    char input;
    char table[250][250];
    char name[50];
    int vert = 0;
    int hori = 0;
    
    while(scanf("%c", &input) != EOF){
        if(input == 'X')
            return 0;
        
        if(input == 'I'){
            
            scanf("%d %d", &hori, &vert);
            
            for(int i = 0; i < vert; i++)
                for(int j = 0; j < hori; j++)
                    table[i][j] = 'O';
            
        }
        
        if(input == 'C'){
            for(int i = 0; i < vert; i++){
                for(int j = 0; j < hori; j++){
                    table[i][j] = 'O';
                }
            }
        }
        
        if(input == 'L'){
            int y;
            int x;
            char color;
            scanf("%d %d %c", &x, &y, &color);
            
            table[y-1][x-1] = color;
        }
        
        if(input == 'V'){
            int x;
            int y1;
            int y2;
            char color;
            
            scanf("%d %d %d %c", &x, &y1, &y2, &color);
            
            if(y1 > y2) {
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }
            
            if(y1 < 1){
                y1 = 1;
            }
            if(y2 > vert)
                y2 = vert;
            
            if(x < 1)
                x = 1;
            if(x > hori)
                x = hori;
            
            //char color = input_letter.at( input_letter.length() - 1 );
            for(int i = y1; i <= y2; i++)
                table[i-1][x-1] = color;
        }
        
        if(input == 'H'){
            int x1;
            int x2;
            int y;
            char color;
            
            scanf("%d %d %d %c", &x1, &x2, &y, &color);
            
            if(x1 > x2) {
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }
            
            if(y < 1){
                y = 1;
            }
            if(y > vert)
                y = vert;
            
            if(x1 < 1)
                x1 = 1;
            if(x2 > hori)
                x2 = hori;
            
            for(int i = x1; i <= x2; i++)
                table[y-1][i-1] = color;
            
            
        }
        
        if(input == 'K'){
            int x1;
            int y1;
            int x2;
            int y2;
            char color;
            
            scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
            
            if(x1 > x2) {
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }
            
            if(y1 > y2) {
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }
            
            if(y1 < 1)
                y1 = 1;
            if(y2 > vert)
                y2 = vert;
            
            if(x1 < 1)
                x1 = 1;
            if(x2 > hori)
                x2 = hori;
            
            
            for(int n = x1; n <= x2; n++)
                for(int i = y1; i <= y2; i++)
                    table[i-1][n-1] = color;
                    
        }
        
        if(input == 'F'){
            int x;
            int y;
            char color;
            
            scanf("%d %d %c", &x, &y, &color);
            
            char region = table[y-1][x-1];

            //recursion would be easier for this
            if(region != color)
                fill(table, vert, hori, x-1, y-1, region, color);
            
        }
        
        if(input == 'S'){
            //output name
            scanf("%s", &name);
            cout << name << endl;
            //output picture
            for(int i = 0; i < vert; i++){
                for(int j = 0; j < hori; j++)
                    cout << table[i][j];
                cout << endl;
            }
            
        }
    }
    
    return 0;
}

