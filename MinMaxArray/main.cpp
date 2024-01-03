//
//  main.cpp
//  Min Max Array
//
//  Created by Kyo Mangold on 16.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int array[10];
    int n = 10;
    int biggest, smallest;
    cout << "Enter 10 integer values: " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    biggest = smallest = array[0];
    for(int i = 0; i < n; i++){
        if(array[i] < smallest)
            smallest = array[i];
        if(array[i] > biggest)
            biggest = array[i];
    }
    cout << smallest << "/" << biggest << endl;
    return 0;
  
}
