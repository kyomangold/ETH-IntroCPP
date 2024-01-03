//
//  main.cpp
//  Largest String Alternative
//
//  Created by Kyo Mangold on 30.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
#include <string>
#include <vector>
#include <iostream>

typedef std::string::iterator Iterator;

// PRE: first1, last1 and first2, last2 must be valid iterator pairs
//      representing two strings string1 and string2
// POST: returns if (lexicographic) string1 < string2
bool lexicographic_compare (Iterator first1, Iterator last1,
                            Iterator first2, Iterator last2)
{
    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2) return true;
        else if (*first1 > *first2) return false;
        first1++;
        first2++;
    }
    return first2 != last2; // implies first1 == last1
}

int main ()
{
    // string input
    int n;
    std::cin >> n;
    if (n <= 0) return 0;
    
    std::vector<std::string> strings(n);
    for (int i = 0; i != n; ++i)
        std::cin >> strings[i];
    
    // search lexicographic largest string
    int last = 0;
    for (unsigned i = 1; i != strings.size(); ++i)
        if (lexicographic_compare(strings[last].begin(), strings[last].end(),
                                  strings[i].begin(), strings[i].end()))
            last = i;
    
    // string putput
    std::cout << strings[last] << "\n";
}
