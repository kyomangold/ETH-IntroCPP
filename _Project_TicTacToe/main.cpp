//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Kyo Mangold on 29.03.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include "grid.h"
using namespace std;

char player = 'O';

void print_grid(int i, int j){ // print empty grid
    cout << endl;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << grid(i,j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool is_valid_move(int i, int j){ // check if input is in the grid and if it's not already occupied
    if (((i>=0 && i <= 2) && (j>=0 && j <= 2)) && (grid(i,j) == '_')) return true;
    else return false;
}

void input(){ // take players input
    int i, j;
    cout << player << "'s turn: ";
    cin >> i;
    cin >> j;
    if (is_valid_move(i, j) == true)
    {
        grid(i,j) = player;
    }
    else
    {
        while(is_valid_move(i, j) == false){
        cout << "Invalid move!" << endl;
        cout << player << "'s turn: ";
        cin >> i;
        cin >> j;
        }
        grid(i,j) = player;
    }
}

void change_player(){ // alternate players
    if (player == 'O') player = 'X';
    else player = 'O';
}

char winner(){
// check if player O has a winning triplet
    // check rows
     if ((grid(0,0) == 'O') && (grid(0,1) == 'O') && (grid(0,2) == 'O')) return 'O';
     if ((grid(1,0) == 'O') && (grid(1,1) == 'O') && (grid(1,2) == 'O')) return 'O';
     if ((grid(2,0) == 'O') && (grid(2,1) == 'O') && (grid(2,2) == 'O')) return 'O';
    // check columns
     if ((grid(0,0) == 'O') && (grid(1,0) == 'O') && (grid(2,0) == 'O')) return 'O';
     if ((grid(0,1) == 'O') && (grid(1,1) == 'O') && (grid(2,1) == 'O')) return 'O';
     if ((grid(0,2) == 'O') && (grid(1,2) == 'O') && (grid(2,2) == 'O')) return 'O';
    // check diagonals
     if ((grid(0,0) == 'O') && (grid(1,1) == 'O') && (grid(2,2) == 'O')) return 'O';
     if ((grid(2,0) == 'O') && (grid(1,1) == 'O') && (grid(0,2) == 'O')) return 'O';
    
    
// check if player X has a winning triplet
    // check rows
    if ((grid(0,0) == 'X') && (grid(0,1) == 'X') && (grid(0,2) == 'X')) return 'X';
    if ((grid(1,0) == 'X') && (grid(1,1) == 'X') && (grid(1,2) == 'X')) return 'X';
    if ((grid(2,0) == 'X') && (grid(2,1) == 'X') && (grid(2,2) == 'X')) return 'X';
    // check columns
    if ((grid(0,0) == 'X') && (grid(1,0) == 'X') && (grid(2,0) == 'X')) return 'X';
    if ((grid(0,1) == 'X') && (grid(1,1) == 'X') && (grid(2,1) == 'X')) return 'X';
    if ((grid(0,2) == 'X') && (grid(1,2) == 'X') && (grid(2,2) == 'X')) return 'X';
    // check diagonals
    if ((grid(0,0) == 'X') && (grid(1,1) == 'X') && (grid(2,2) == 'X')) return 'X';
    if ((grid(2,0) == 'X') && (grid(1,1) == 'X') && (grid(0,2) == 'X')) return 'X';
    
    return '-';
    
}

int main() {
    int n = 0;
    print_grid(2,2); // prints a 3 x 3 Grid of '_'
    while(1){
        n++;
        input();
        print_grid(2, 2);
            if (winner() == 'O')
            {
                cout << "O won!" << endl;
                return 0;
            }
            else if (winner() == 'X')
            {
                cout << "X won!" << endl;
                return 0;
            }
            else if((winner() == '-') && (n == 9))
            {
                cout << "Draw!" << endl;
                return 0;
            }
        change_player();
    }
    return 0;
}
