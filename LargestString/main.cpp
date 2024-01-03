//
//  main.cpp
//  Largest String
//
//  Created by Kyo Mangold on 28.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using Iterator = std::string::iterator;

bool lexicographic_compare(Iterator first1, Iterator last1, Iterator first2, Iterator last2);


int main() {
    int N;
    std::cout << "Enter the number of strings you want to enter: ";
    std::cin >> N;
    std::cout << std::endl;
    
    if (N <= 0){
        return 0;
    }
    else{
        
        std::vector<std::string> strings(N);
        std::cout << "Enter " << N << " strings: " << std::endl;
        for(int i = 0; i < N; ++i){
            std::cin >> strings[i];
        }
        
        int largest = 0;
        for (unsigned int i = 1; i < N; ++i){
            if(lexicographic_compare(strings[largest].begin(), strings[largest].end(), strings[i].begin(), strings[i].end())){
                largest = i;
            }
        }
        std::cout << "The largest string is: " << strings[largest]  << std::endl;
        return 0;
        
    }
    
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

