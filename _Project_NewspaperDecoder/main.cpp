//
//  main.cpp
//  NZZ Decoder
//
//  Created by Kyo Mangold on 01.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
#include <iostream>
#include <fstream>

// PRE:  Input string value containing exactly 8 characters. Allowed
//       characters are '0' and '1'.
// POST: Returns true if the string value could be converted to a
//       character, otherwise false. If return value is true then
//       res contains the character corresponding to the input string
//       value, otherwise res is undefined.
bool decode_to_char(unsigned char& res, const std::string& value) {
    if (value.length() != 8) {
        return false;
    }
    
    res = 0;
    for(int i = 0; i < 8; ++i) {
        res *= 2;
        if (value[i] == '1') {
            res += 1;
        } else if (value[i] != '0') {
            return false;
        }
    }
    return true;
}

int main() {
    std::string filename;
    std::cin >> filename;
    
    std::ifstream in(filename.c_str());
    
    std::string value;
    while(in >> value) {
        unsigned char c;
        bool success = decode_to_char(c, value);
        if (!success) {
            std::cout << "input file has incorrect format\n";
            break;
        }
        std::cout << c;
    }
    return 0;
}
