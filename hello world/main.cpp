/* 
 * Solution for the "Graphical Editor" problem.
 * UVa ID: 10267
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string>

  
   
#define MAX 250
#define OFFSET 1
#define DOS_NAME 12
/* global image bounds */

using namespace std;

int n, m;
/* fills a rectangle with the specified color */
int fillRectangle(int m_ini, int n_ini, int m_end, int n_end, char color, char pTable[][MAX+OFFSET]) {
	int i, j;
	for (i = n_ini; i <= n_end; i++) {
		for (j = m_ini; j <= m_end; j++) {
			pTable[i][j] = color;
		}
	}
	return 0;
}
/* fills a region R with the specified color */
int fillRegion(int x, int y, char oldColor, char newColor, char pTable[][MAX+OFFSET]) {	
	/* (x,y) is in region R */
	pTable[y][x] = newColor;
	
	/* recursively check all 4 directions for neighbours of (x,y) with same color */
	if ((pTable[y][x-1] == oldColor) && (x > OFFSET)) {         
		fillRegion(x-1, y, oldColor, newColor, pTable);
	}
	if ((pTable[y][x+1] == oldColor) && (x < m)) {       
		fillRegion(x+1, y, oldColor, newColor, pTable);
	}
	if ((pTable[y-1][x] == oldColor) && (y > OFFSET)) {        
		fillRegion(x, y-1, oldColor, newColor, pTable);
	}
	if ((pTable[y+1][x] == oldColor) && (y < n)) {        
		fillRegion(x, y+1, oldColor, newColor, pTable);
	}
	return 0;
}
/* outputs the image */
int printImage(int m, int n, char pTable[][MAX+OFFSET]) {
	int i, j;	
	for (i = OFFSET; i < n+OFFSET; i++) {
		for (j = OFFSET; j < m+OFFSET; j++ ) {
			printf("%c", pTable[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/* main */
int main (int argc, const char * argv[]) {
    int what, what2;
    
    scanf("%d", &what);
    scanf("%d", &what2);
    
    cout << what << " " << what2 << endl;
    
    return 0;
}