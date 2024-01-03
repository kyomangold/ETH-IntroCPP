//
//  main.cpp
//  Parabola
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    double x;
    cout << "Type in a value for x: ";
    cin >>  x;
    cout << "\n";
    double y;
    cout << "Type in a value for y: ";
    cin >>  y;
    cout << "\n";
    
    double g;
    g = 0.9 * x * x + 1.3 * x - 0.7;
    
    
    if ((g-y) < 0.001)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}

