//
//  main.cpp
//  Arithmetic Stack
//
//  Created by Kyo Mangold on 31.01.19.
//  Copyright © 2019 Kyo Mangold. All rights reserved.
//

#include <iostream>

class arithmetic_stack{
    double stack[8];
    int position;
    
public:
    arithmetic_stack(){
        position = 0;
    }
    //    PRE: position < 8;
    //    POST: pushes value to new stack top
    void push(double value){
        stack[position++] = value;
    }
    //    PRE: position > 0
    //    POST: pops and returns value at stack top
    double pop(){
        return stack[--position];
    }
    //    PRE: position > 1
    //    POST: replaces two top-most stack values by the sum
    void add(){
        push(pop() + pop());
    }
    //    PRE: position > 1
    //    POST: replaces two top-most stack values by the product
    void mul(){
        push(pop() * pop());
    }
};

int main() {
    arithmetic_stack stack;
    stack.push(30);
    stack.push(20);
    stack.push(10);
    stack.add();
    stack.mul();
    std::cout<< stack.pop() <<std::endl;
}
