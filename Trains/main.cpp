//
//  main.cpp
//  Trains
//
//  Created by Kyo Mangold on 01.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include <istream>
#include <sstream>
#include <string>

//function definitions for each production rule
bool train(std::istream& is);
bool open(std::istream& is);
bool loco(std::istream& is);
bool cars(std::istream& is);
bool compositions(std::istream& is);
bool composition(std::istream& is);
//additional function definitions from lecture
char lookahead (std::istream& is);
bool consume(std::istream& is, char ch);

int main() {
    std::cout << "Enter a train formation: " << std::endl;
    std::string train_formation;
    std::cin >> train_formation;
    std::stringstream input(train_formation);
    
    if(train(input)){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "invalid" << std::endl;
    }
    return 0;
}

bool train(std::istream& is)
{
    bool valid;
    if (lookahead(is) == '<'){
        valid = compositions(is);
    }
    else{
        valid = open(is);
    }
    valid = valid && lookahead(is) == 0;
    return valid;
}

bool open(std::istream& is){
    bool valid;
    if(loco(is) && cars(is)){
        valid = true;
    }
    else{
        valid = false;
    }
    return valid;
//    return loco(is) && cars(is);
}

bool loco(std::istream& is){
    bool valid;
    valid = consume(is, '*');
    if(lookahead(is) == '*'){
        valid = valid && loco(is);
    }
    return valid;
}

bool cars(std::istream& is){
    bool valid;
    valid = consume(is, '-');
    if(lookahead(is) == '-'){
        valid = valid && cars(is);
    }
    return valid;
}

bool compositions(std::istream& is){
    bool valid;
    valid = composition(is);
    while(valid && lookahead(is) == '<'){
        valid = valid && composition(is);
    }
    return valid;
}

bool composition(std::istream& is){
    bool valid;
    if (consume(is, '<') && open(is) && loco(is) && consume(is, '>')){
        valid = true;
    }
    else{
        valid = false;
    }
    return valid;
//    return consume(is, '<') && open(is) && loco(is) && consume(is, '>');
}

char lookahead(std::istream& is){
    if (is.eof()){
        return 0;
    }
    is >> std::ws;
    if (is.eof()){
        return 0;
    }
    return is.peek();
}

bool consume(std::istream& is, char ch2){
    bool valid;
    char ch1;
    is >> ch1;
    if(ch1 == ch2){
        valid = true;
    }
    else{
        valid = false;
    }
    return valid;
    
//    return (a == ch);
}
