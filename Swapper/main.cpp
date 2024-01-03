//
//  main.cpp
//  Swapper
//
//  Created by Kyo Mangold on 14.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

//BubbleSort Algorithm

void swap(int *xp, int *yp){
    int zp = *xp;
    *xp = *yp;
    *yp = zp;
}

void swapper(int array[], int n){
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
            swapped = true;
        }
        if (swapped == false)
            break;
    }
    
}

void print_swapped_array(int array[], int n){
    cout << "The swapped array is: ";
    for(int i = (n-1); i >= 0; i--){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[10];
    int n = 10;
    cout << "Enter 10 integer values: " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    
    swapper(array, n);
    print_swapped_array(array, n);
    
    return 0;
}


