//
//  main.cpp
//  Binary Expansion
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//


#include <iostream>

using namespace std;
int main(){
    
    double x;
    cout << "Enter a decimal value for x: ";
    cin >> x;
    if (x >= 0 && x < 2)
    {
        int binaryNumber [15], i = 0;
        int b;
        //determine the value of b0,b1,b2,...,b15
        for (int a = 0; a  <= 15; a++)
        {
            if (x >= 1)
            {
                b = 1;
            }
            else
            {
                b = 0;
            }
            
            binaryNumber[i] = b;
            i++;
            
            x = 2 * (x - b);
        }
        //Output of the binary expansion in the form b0.b1b2b3b4b5b6...b15
        cout << "The binary expansion of " << x << " is: ";
        cout << binaryNumber[0] << ".";
        for (int j = 1; j <= i-1; j++ )
        {
            cout << binaryNumber[j];
        }
        cout << "\n";
        return 0;
    }
    else return 0;
}




