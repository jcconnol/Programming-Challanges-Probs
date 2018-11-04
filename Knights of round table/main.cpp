/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on April 19, 2018, 8:53 PM
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

using namespace std;

int main(int argc, char** argv) {
    
    double side1,side2, side3;
    while(scanf("%lf %lf %lf", &side1, &side2, &side3) != EOF){
        long double area, perim;
        perim = side1 + side2 + side3;
        if(perim != 0){
            long double pHalf = perim/2;
            area = sqrt((pHalf) * (pHalf - side1) * (pHalf - side2) * (pHalf - side3));
        }
        else{
            perim = 1;
            area = 0;
        }
        cout << "The radius of the round table is: ";
        cout << fixed << setprecision(3) << (2*area / perim) << endl;
    }
    
    return 0;
}

