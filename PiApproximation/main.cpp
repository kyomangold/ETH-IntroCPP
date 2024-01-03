//
//  main.cpp
//  Pi Approximation
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    
    double n;
    cout << "Geben Sie eine Zahl n ein: ";
    cin >> n;
    
    // COMPUTE SUM1
    double sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum1 += ( (pow((-1), (i-1))) / (2*i - 1) );
        
        if(i == n) {
            cout << "Sum1 = " << 4 * sum1 << endl;
        }
    }
    
    // COMPUTE SUM2
    double sum2 = 0;
    for (int k = 1; k <= n; k++)
    {
        //compute numerator
        int a = k-1;
        double numerator = 1;
        if(a != 0)
        {
            for (a = a; a > 0; --a){
                numerator *= a;
            }
        }
        //compute denominator
        int b = 2*k-1;
        double denominator = 1;
        double d = 1;
        if(b != 0)
        {
            for (b = b; b > 0; --b){
                d *= b;
            }
        }
        
        denominator = d/((pow(2, k-1)) * numerator);
        
        sum2 += (numerator / denominator);
        
        if(k == n){
            cout << "Sum2 = " << 2 * sum2 << endl;
        }
    }
    return 0;
}

