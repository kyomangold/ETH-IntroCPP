//
//  main.cpp
//  Money Partitions
//
//  Created by Kyo Mangold on 30.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include<iostream>

// PRE: [begin, end) is a valid nonempty range that describes
//      a sequence of denominations d_1 > d_2 > ... > d_n > 0
// POST: return value is the number of ways to partition amount
//       using denominations from d_1, ..., d_n
unsigned int partitions (const unsigned int amount,
                         const unsigned int* begin,
                         const unsigned int* end)
{
    
    if (amount == 0)
    {
        return 1;
    }
    else
    {
        unsigned int ways = 0;
        for(const unsigned int* i = begin; i!= end; ++i)
        {
            if(amount >= *i)
            {
                ways += partitions(amount - *i, i, end);
            }
        } return ways;
    }
}

int main()
{
    // the 13 denominations of CHF
    unsigned int chf[] = {100000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    
    // input
    std::cout << "in how many ways can I own x CHF-centimes for x =?\n";
    unsigned int x;
    std::cin >> x;
    
    // computation and output
    std::cout << partitions (x, chf, chf + 13) << "\n";
    
    return 0;
}
