//
//  main.cpp
//  Longest Sequence
//
//  Created by Kyo Mangold on 16.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int array[10], n = 10, start = 0, count = 1;
    cout << "Enter 10 integer values: " << endl;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (array[i] > array[i - 1])
        {
            if (i - start + 1 > count)
            {
                count = i - start + 1;
            }
        }
        else
        {
            start = i;
        }
    }
    cout << "The length of the longest growing sequence is: " << count << endl;
    return 0;
}
