//
//  main.cpp
//  Resistor
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>

int main() {
    
    int r1, r2, r3, r4;
    std::cout << "Input for resistance R1: ";
    std::cin >> r1;
    std::cout << "Input for resistance R2: ";
    std::cin >> r2;
    std::cout << "Input for resistance R3: ";
    std::cin >> r3;
    std::cout << "Input for resistance R4: ";
    std::cin >> r4;
    
    //computing the serial resistance for R1 and R2
    int r12;
    r12 = r1 + r2;
    //computing the serial resistance for R3 and R4
    int r34;
    r34 = r3 + r4;
    //computing the equivalent resistance REQ;
    int req;
    req = ((r12 * r34) + ((r12 + r34)/2)) / (r12 + r34);
    
    std::cout << "\nThe equivalent resistance is: " << req << "\n\n" << std::endl;
    
    return 0;
}

