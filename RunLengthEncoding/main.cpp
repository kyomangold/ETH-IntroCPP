//
//  main.cpp
//  Run Length Encoding
//
//  Created by Kyo Mangold on 01.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
// Run-length encoding and decoding of a byte sequence (simple variant)
#include <iostream>
#include <cassert>

// PRE:  n/a
// POST: returns true if value equals the maximal run-length
bool is_max_runlength(unsigned int value)
{
    return value == 255;
}

// PRE:  n/a
// POST: outputs value and adds a space
void out_byte(unsigned int value)
{
    std::cout << value << " ";
}

// PRE:  n/a
// POST: returns true if 0 <= value <= 255, otherwise false
bool is_byte(int value)
{
    return 0 <= value && value <= 255;
}

// PRE:  1 <= runlength <= 255, and value is a byte.
// POST: outputs run length encoded bytes of tuple
void output(unsigned int run_length, unsigned int value)
{
    assert(1 <= run_length && run_length <= 255);
    assert(is_byte(value));
    
    out_byte(run_length);
    out_byte(value);
}

// PRE:  n/a
// POST: outputs error if value does not indicate end of sequence
void check_end_of_sequence(int value)
{
    if (value != -1) {
        std::cout << "error\n";
    }
}

// PRE:  n/a
// POST: reads byte sequence and outputs encoded bytes
void encode()
{
    std::cout << "encoding: enter byte sequence, terminate with -1\n";
    
    // output start of sequence
    std::cout << "1 ";
    
    int value;
    std::cin >> value;
    
    if (is_byte(value)) {
        int prev_value = value;
        unsigned int run_length = 1;
        
        while(true) {
            
            // read next byte, stop if invalid or end of sequence
            std::cin >> value;
            if (!is_byte(value)) {
                break;
            }
            
            // output if value has changed or maximal runlength is reached
            // otherwise increase length of current run
            if (value != prev_value || is_max_runlength(run_length)) {
                output(run_length, prev_value);
                run_length = 1;
                prev_value = value;
            } else {
                ++run_length;
            }
        }
        
        output(run_length, prev_value);
    }
    
    // output "error" if sequence terminated incorrectly
    check_end_of_sequence(value);
    
    // output end of sequence
    std::cout << "-1";
}

// PRE:  n/a
// POST: reads byte sequence and outputs decoded bytes
void decode()
{
    std::cout << "decoding: enter byte sequence, terminate with -1\n";
    
    // output start of sequence
    std::cout << "0 ";
    
    int value;
    while(true) {
        
        // read run length, stop if invalid or end of sequence
        std::cin >> value;
        if (!is_byte(value)) {
            break;
        }
        unsigned int run_length = value;
        
        // next must be a valid byte, otherwise this is an error
        std::cin >> value;
        if (!is_byte(value)) {
            value = 0; // trigger error in case value = -1
            break;
        }
        
        // output uncompressed tuple
        for(unsigned int i = 0; i < run_length; ++i) {
            out_byte(value);
        }
    }
    
    // output "error" if sequence terminated incorrectly
    check_end_of_sequence(value);
    
    // output end of sequence
    std::cout << "-1";
}

int main()
{
    std::cout << "select mode: 0 = encode / 1 = decode\n";
    unsigned int mode;
    std::cin >> mode;
    
    if (mode == 0) {
        encode();
    } else if (mode == 1) {
        decode();
    } else {
        std::cout << "unknown mode, must be 0 (encode) or 1 (decode)\n";
    }
    
    return 0;
}
