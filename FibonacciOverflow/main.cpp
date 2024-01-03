//
//  main.cpp
//  Fibonacci Overflow
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    unsigned int n;
    int j = 2;
    unsigned int fib0 = 0;
    unsigned int fib1 = 1;
    unsigned int fibn = 0;
    cout << "Geben Sie bitte eine Zahl ein: \n";
    cin >> n;
    cout << "\n";
    
    if (n > 0)
    {
        cout << fib0 << endl;
        
    }
    
    if (n > 1)
    {
        cout << fib1 << endl;
        
    }
    
    else
    {
        j = 1;
    }
    
    while (j < n)
    {
        fibn = fib0 + fib1;
        
        if (fibn < fib1)
        {
            break;
        }
        
        cout << fibn << endl;
        
        fib0 = fib1;
        fib1 = fibn;
        
        j++;
        
    }
    if (n == 0)
    {
        j = 0;
    }
    cout << j << " of " << n << endl;
    return 0;
}


