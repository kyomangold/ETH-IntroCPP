//
//  main.cpp
//  isPrime
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int n, i;
    bool isPrime = true;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    for(i = 2; i <= n / 2; ++i)
    {
        if(n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << "This is a prime number." <<endl;
    else
        cout << "This is not a prime number." <<endl;
    
    return 0;
}


