/* 
 * File:   main.cpp
 * Author: John Connolly
 *
 * Created on August 25, 2017, 9:18 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void max_seq_loop(int array[], int size){
    int largest_so_far = 0;
    int final = 0;
    
    for(int at = 0; at < size; at++){
        final = final + array[at];
        if(final < 0){
            final = 0;
        }
        if(largest_so_far < final)
            largest_so_far = final;
    }
    cout << "max sequence addition is: " << largest_so_far << endl;
}



int main(int argc, char** argv) {
    
//    int array[] = {-2,-3,4,-1,-2,1,5,-3};
//    int num1 = sizeof(array)/sizeof(array[0]);
//    //can time everything with clock_t variable = clock();
//    max_seq_loop(array, num1);
    
    string str = "this is a test of ttt";
    cout << str.find_first_of("sss", 35, 7) << endl;
    
    return 0;
}

