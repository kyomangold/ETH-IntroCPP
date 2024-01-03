//
//  main.cpp
//  Fibonacci Primes
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int m;
    int i;
    int j = 0;
    int fib0 = 0;
    int fib1 = 1;
    int fibn = 0;
    cout << "Geben Sie bitte eine Zahl ein: \n";
    cin >> m;
    cout << "\n";
    
    if(m == 2){
        cout << "2" << endl;
        cout << "1" << endl;
        return 0;
    }
    
    if((m == 3)||(m == 4)){
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "2" << endl;
        return 0;
    }
    
    
    
    fibn = fib0 + fib1;
    //    berechnet Fibonacci-Glieder bis zum eingegebenen Wert m
    while (fibn <= m){
        
        fib0 = fib1;
        fib1 = fibn;
        fibn = fib0 + fib1;
        
        //    Überprüft, ob fibn (neu berechnetes Fibonacci Glied) eine Primzahl ist oder nicht
        bool istPrim = true;
        
        
        for(i = 2; i <= (fibn / 2); ++i)
        {
            if (fibn % i == 0){
                istPrim = false;
                break;
            }
        }
        
        if (istPrim){ //falls fibn eine Primzahl ist wird sie ausgegeben
            j++;
            cout << fibn << endl;
        }
    }
    cout << j << endl;
    cout << "\n";
    return 0;
}

