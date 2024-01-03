//
//  SUDOKU_IO.h
//  Sudoku Solver
//
//  Created by Kyo Mangold on 06.05.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//

#ifndef SUDOKU_IO_h
#define SUDOKU_IO_h

#ifndef SUDOKU_IO
#define SUDOKU_IO

void printSudoku(int (&sudoku)[9][9]) {
    // output the sudoku nicely
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int n = sudoku[i][j];
            if (n == 0) {
                std::cout << "- ";
            } else {
                std::cout << n << " ";
            }
            
            if (j == 2 || j == 5) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        
        if (i == 2 || i == 5) {
            std::cout << "-----------------------" << std::endl;
        }
    }
}

void putLine(int (&sudoku)[9][9], int row, int c1, int c2, int c3, int c4,
             int c5, int c6, int c7, int c8, int c9) {
    // fill a line with the values specified in c1 to c9
    // use '0' for blanks.
    sudoku[row][0] = c1;
    sudoku[row][1] = c2;
    sudoku[row][2] = c3;
    sudoku[row][3] = c4;
    sudoku[row][4] = c5;
    sudoku[row][5] = c6;
    sudoku[row][6] = c7;
    sudoku[row][7] = c8;
    sudoku[row][8] = c9;
}

void readSudokuFromInput(int (&sudoku)[9][9]) {
    int c1, c2, c3, c4, c5, c6, c7, c8, c9;
    for (int i = 0; i < 9; ++i) {
        std::cin >> c1 >> c2 >> c3 >>
        c4 >> c5 >> c6 >>
        c7 >> c8 >> c9;
        putLine(sudoku, i, c1, c2, c3, c4, c5, c6, c7, c8, c9);
    }
}

#endif

#endif /* SUDOKU_IO_h */
