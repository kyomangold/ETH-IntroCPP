//
//  main.cpp
//  Sort
//
//  Created by Kyo Mangold on 28.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

void input(int* begin, int* end);
void output(const int* begin, const int* end);
void swap(int* element, int* element2);
int* minimum(int* begin, int* end);
void swapFirstWithMinimum(int* begin, int* end);
void sort(int* begin, int* end);

int main() {
    const int N = 10;
    int arr[N];
    input(&arr[0], &arr[N]);
    sort(&arr[0], &arr[N]);
    output(&arr[0], &arr[N]);
    return 0;
}
// a)
void input(int* begin, int* end){
    cout << "Enter 10 integer values: " << endl;
    for(int* i = begin; i != end; ++i)
    {
        cin >> *i;
    }
}
// b)
void output(const int* begin, const int* end){
    cout << "The sorted array in ascending order: ";
    for(const int* i = begin; i != end; ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}
// c)
void swap(int* element, int* element2){
    int temp = *element;
    *element = *element2;
    *element2 = temp;
}
// d)
int* minimum(int* begin, int* end){
    
    int* minimum;
    minimum = begin;
    for(int* i = begin + 1; i != end; ++i)
    {
        if(*minimum > *i)
        {
            minimum = i;
        }
    }
    return minimum;
}
// e)
void swapFirstWithMinimum(int* begin, int* end){
    swap(begin, minimum(begin, end));
}
// f)
void sort(int* begin, int* end){
    for(int* i = begin; i != end; ++i){
        swapFirstWithMinimum(i, end);
    }
}
