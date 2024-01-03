//
//  main.cpp
//  Parser
//
//  Created by Kyo Mangold on 01.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

// checks if arithmetic expressions involving +, -, *, /, (, ) over double operands are valid

// Syntax in EBNF:
// ---------------
// expression = term { "+" term | "-" term }
// term = factor { "*" factor | "/" factor }
// factor = unsigned_double | "(" expression ")" | -factor

#include<iostream>
#include<istream>
#include<sstream>
#include<cassert>
#include<cmath>

// declarations
// ------------

// PRE: is = expression...
// POST: returns if a valid expression can be extracted from is
bool expression (std::istream& is);

// PRE: is = term...
// POST: returns if a valid term can be extracted from is
bool term  (std::istream& is);

// PRE: is = factor...
// POST: returns if a valid factor can be extracted from is
bool factor  (std::istream& is);

// definitions
// -----------

// POST: leading whitespace characters are extracted
//       from is, and the first non-whitespace character
//       is returned (0 if there is no such character)
char lookahead (std::istream& is)
{
    is >> std::ws;         // skip whitespaces
    if (is.eof())
        return 0;            // end of stream
    else
        return is.peek();    // next character in is
}

// POST: if next chararcer in is is ch, consume c and return
//       true, otherwise return false
bool consume  (std::istream& is, char c)
{
    if (lookahead (is) == c) {
        is >> c;
        return true;
    } else
        return false;
}

// expression = term { "+" term | "-" term }
bool expression (std::istream& is)
{
    if (!term(is)){
        return false;
    }
    while ( consume (is, '+') || consume (is,'-')){
        if (!term(is)) return false;
    }
    return true;
}

// term = factor { "*" factor | "/" factor }
bool term (std::istream& is)
{
    if (!factor(is)){
        return false;
    }
    while ( consume (is, '*') || consume (is,'/')){
        if (!factor(is)) return false;
    }
    return true;
}

// factor = unsigned_double | "(" expression ")" | -factor
bool factor (std::istream& is)
{
    if (consume (is, '(')) {
        return expression(is) && consume(is, ')');
    } else if (consume (is, '-')){
        return factor(is);
    }
    else{
        double value; is >> value; // consume a double
        return !is.fail(); // return if double could be consumed
    }
}

// check if string s provides an expression valid according to the EBNF above.
void check(std::string s){
    std::stringstream input (s);
    if (expression (input)){
        std::cout << s << " is a good expression" << std::endl;
    } else {
        std::cout << s << " is not a valid expression"  << std::endl;
    }
}

int main()
{
    check("1-2*8+(88- -10)");
    check("1-2*8+(88- -10)-");
    return 0;
}
