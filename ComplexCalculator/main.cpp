//
//  main.cpp
//  Complex Calculator
//
//  Created by Kyo Mangold on 14.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <string>
#include <iostream>

typedef struct Complex {
    double x; // real part
    double y; // imaginary part
    
    Complex(double x, double y)
    : x(x), y(y) {}
    
    // implementation of arithmetic operators
    
    Complex operator+ (const Complex& other) const
    {
        return Complex(x + other.x, y + other.y);
    }
    
    Complex operator- (const Complex& other) const
    {
        return Complex(x - other.x, y - other.y);
    }
    
    Complex operator* (const Complex& other) const
    {
        return Complex((x * other.x) - (y * other.y), (x * other.y) + (other.x * y));
    }
    
    Complex operator/ (const Complex& other) const
    {
        return Complex(((x * other.x) + (y * other.y))/((other.x * other.x) + (other.y * other.y)) , ((other.x * y) - (x * other.y))/((other.x * other.x) + (other.y * other.y)));
    }
    
    // implementation of negation operator
   
//    Complex operator (const Complex& other) const
//    {
//        return Complex(-x, -y);
//    }
    
    // implementation of comparison operators
    
    bool operator==(const Complex& other) const
    {
        return x == other.x && y == other.y;
    }
    
    bool operator!=(const Complex& other) const
    {
        return !(*this == other); // returns the opposite of bool operator==()
    }
    
}Complex;

// implementation of input/output operators

std::istream& operator>>(std::istream& istream, Complex& other)
{
    char ch;
    istream >> ch;
    istream >> other.x;
    istream >> ch;
    istream >> other.y;
    istream >> ch;
    return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Complex& other)
{
    ostream << "[" << other.x << "," << other.y << "]";
    return ostream;
}



int main() {
    // input operation and operands
    std::string op;
    Complex c1, c2;
    std::cin >> op >> c1;
    if (op != "inout" && op != "neg") {
        std::cin >> c2;
    }
    
    // execute operation
    if      (op == "add")   { std::cout << c1 + c2;    }
    else if (op == "sub")   { std::cout << c1 - c2;    }
    else if (op == "mul")   { std::cout << c1 * c2;    }
    else if (op == "div")   { std::cout << c1 / c2;    }
    else if (op == "eq")    { std::cout << (c1 == c2); }
    else if (op == "ne")    { std::cout << (c1 != c2); }
    else if (op == "inout") { std::cout << c1;         }
    else if (op == "neg")   { std::cout << -c1;        }
    std::cout << "\n";
}
