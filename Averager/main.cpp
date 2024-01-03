//
//  main.cpp
//  Averager
//
//  Created by Kyo Mangold on 19.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
class Averager{
    double sum_values;
    int num_values;
public:
    Averager();
    void add_value(double value);
    double get_average();
    void reset();
};

Averager::Averager() : sum_values(0), num_values(0) {}

void Averager::add_value(double value) {
    sum_values += value;
    num_values++;
}

double Averager::get_average(){
    if (num_values > 0)
    {
        return (sum_values/num_values);
    }
    else
    {
        return 0;
    }
}

void Averager::reset(){
    sum_values = 0;
    num_values = 0;
}

int main() {
    Averager averager;
    std::string operation;
    
    // query for new operations until end of stream is reached
    while(std::cin >> operation) {
        if (operation == "add") {
            double value;
            std::cin >> value;
            averager.add_value(value);
            
        } else if (operation == "get") {
            std::cout << averager.get_average() << " ";
            
        } else if (operation == "reset") {
            averager.reset();
        }
    }
}
