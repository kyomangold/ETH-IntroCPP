//
//  main.cpp
//  Lexicographic Compare
//
//  Created by Kyo Mangold on 28.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using Iterator = std::string::iterator;

bool lexicographic_compare(Iterator first1, Iterator last1, Iterator first2, Iterator last2);

int main() {
    // string input
    std::string name1;
    std::string name2;
    std::cin >> name1;
    std::cin >> name2;
    
    // output result for standard library strings
    if (lexicographic_compare (name1.begin(), name1.end(), name2.begin(), name2.end()))
        std::cout << name1 << " < " << name2 << "\n";
    else
        std::cout << name1 << " >= " << name2 << "\n";
    
    return 0;
}

bool lexicographic_compare(Iterator first1, Iterator last1, Iterator first2, Iterator last2){
    
    while (first1 != last1)
    {
        if ((first2 == last2) || ((*first2) < (*first1))) {
            return false;
        }
        else if ((*first1) < (*first2)){
            return true;
        }
        ++first1;
        ++first2;
    }
return (first2 != last2);
}
