/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 19, 2018, 2:47 PM
 */

#include <cstdlib>
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
#include <tgmath.h>

using namespace std;

int main(int argc, char** argv) {
    
    double input;
    while(scanf("%lf", &input) != EOF){
        long double x,y,z;
        long double pi = 3.14159265358979323846;
        long double square = pow(input, 2.0);
        
        z = square - square* pi/4;
        z -= square * pi/4 - square * pi/6 - (square * pi/6 - square * sqrt(3.0)/4);
        z *= 4;
        
        y = 4 * (square - square * pi/4 - z/2);
        
        x = square - y - z;
        
        cout << fixed << setprecision(3) << x << " " << y << " " << z << endl;
    }
    
    return 0;
}