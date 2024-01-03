//
//  main.cpp
//  Sudoku Solver
//
//  Created by Kyo Mangold on 06.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#include <iostream>
#include "SUDOKU_IO.h"

int sudoku[9][9];

bool isValid(int num, int row, int col) {
    //checks that number doesn't appear elsewhere on the same row, respectively column
    for(int i = 0; i < 9; i++){
        if(sudoku[i][col] == num) return false;
        if(sudoku[row][i] == num) return false;
    }
    //checks that number doesn't appear elsewhere on the same 3-by-3 subgrid
    int sub_row = 3 * (row/3);
    int sub_col = 3 * (col/3);
    int sub_row1 = (row + 2) % 3;
    int sub_row2 = (row + 4) % 3;
    int sub_col1 = (col + 2) % 3;
    int sub_col2 = (col + 4) % 3;
    
    if(sudoku[sub_row1 + sub_row][sub_col1 + sub_col] == num) return false;
    if(sudoku[sub_row2 + sub_row][sub_col1 + sub_col] == num) return false;
    if(sudoku[sub_row1 + sub_row][sub_col2 + sub_col] == num) return false;
    if(sudoku[sub_row2 + sub_row][sub_col2 + sub_col] == num) return false;
    else return true;
}

bool fillValidNumber(int row, int col) {
      // checks if iterated over the whole sudoku... if so, we're done
    if(row == 9) return true;
      // checks that no (already) set number gets changed
    if(sudoku[row][col]){
        if (col == 8) {
            if(fillValidNumber(row + 1, 0)) return true;
        }
        else{
            if(fillValidNumber(row, col + 1)) return true;
        }
        return false;
    }
    
  // iterates over possible "test"-numbers from 1 to 9
    for(int test_num = 9; test_num > 0; test_num--){
        if(isValid(test_num, row, col)){
            sudoku[row][col] = test_num;
            if (col == 8){
                if(fillValidNumber(row+1, 0)) return true;
            }
            else {
                if(fillValidNumber(row, col+1)) return true;
            }
            // if no solution is found
            sudoku[row][col] = 0;
        }
    }
    return false;
}


int main() {
    std::cout << "Enter your sudoku to be solved: " << std::endl;
    
    // Call util function to fill sudoku array with some input
    readSudokuFromInput(sudoku);
    
    // Solve by starting from first cell in the grid
    bool isSolved = fillValidNumber(0,0);
    
    // Print out the sudoku in its current state
    std::cout << "FINAL RESULT" << std::endl; // solver result after this string
    printSudoku(sudoku);
    
    if (!isSolved) {
        std::cout << "No solution found." << std::endl;
    }
    return 0;
}
