//
//  main.cpp
//  Dec2Bin
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    unsigned int n;
    int bin[100], i = 0, j;
    
    cout << "Geben Sie bitte eine Zahl ein: ";
    cin >> n;
    if (n == 0){
        cout << "Die eingegebene Zahl sieht im Binär-System so aus: " << n << endl;
        return 0;
    }
    
    while (n > 0){
        bin[i] = n % 2; // Rest der Division durch 2 wird in Array gespeichert
        i++;
        n /= 2;
    }
    cout << "Die eingegebene Zahl sieht im Binär-System so aus: ";
    //Ausgeben der im Array gespeicherten Werte in der richtigen ("umgekehrten") Reihenfolge
    for(j=i-1; j>=0; --j){
        cout << bin[j];
    }
    cout << endl;
    
    return 0;
}



