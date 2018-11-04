/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on February 17, 2018, 5:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <ios>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    
    vector<int> factors;
    int primes[50000];
    bool finding[50000];

    factors.push_back(2);
    
    for(int i = 0; i < 50000; i++)
        finding[i] = true;
    
    finding[0] = false;
    finding[1] = false;

    for(int i = 3; i * i <= 50000; i += 2) {
        if(finding[i]) {
            for ( int j = i * i; j < 50000; j += 2 * i ) {
                    finding[j] = false;
            }
        }
    }

    for(int i = 3; i < 50000; i += 2) {
        if(finding[i])
            factors.push_back(i);
    }
    
    long first_num;
    long second_num;
    while(scanf("%d %d", &first_num, &second_num) != EOF){
        
        long second_holder = second_num;

        if(first_num >= second_num) {
                cout << second_num << " divides " << first_num << "!" << endl;
        }
        else {

                bool prime_factor = true;
                
                for(int i = 0; i < 50000; i++)
                    primes[i] = 0;
                
                int size1 = factors.size();
                for(int i = 0; i < size1; i++) {
                        for(int tmp = (int) first_num; tmp != 0; tmp /= factors[i]) {
                                primes[factors[i]] += tmp / factors[i];
                        }
                }

                for(int i = 0; factors[i] * factors[i] <= second_num; i++) {
                        while(second_num % factors[i] == 0) {
                                primes[factors[i]]--;
                                second_num /= factors[i];
                        }
                }

                if(second_num > 1 && first_num < second_num) {
                        prime_factor = false;
                }

                int size = factors.size();
                for(int i = 0; i < size && prime_factor; i++) {
                        if(primes[factors[i]] < 0) {
                                prime_factor = false;
                        }
                }

                if(prime_factor) {
                        cout << second_holder << " divides " << first_num << "!" << endl;
                }
                else {
                        cout << second_holder << " does not divide " << first_num << "!" << endl;
                }
        } 
    }
    
    return 0;
}

