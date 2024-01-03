//
//  grid.h
//  Tic-Tac-Toe
//
//  Created by Kyo Mangold on 10.04.18.
//  Copyright © 2018 Kyo Mangold. All rights reserved.
//
#pragma once

#include <array>
#include <stdexcept>
#include <vector>

class Grid {
public:
    Grid(int numRows, int numCols) : mNumRows{numRows}, mNumCols{numCols} {
        mState.resize(numRows * numCols, '_');
    }
    
    Grid(const Grid &g) {
        mState = std::vector<char>(g.mState);
        mNumRows = g.mNumRows;
        mNumCols = g.mNumCols;
    }
    
    char& operator()(int row, int col) {
        if (row < 0 || row >= mNumRows || col < 0 || col >= mNumCols) {
            throw std::runtime_error{"Invalid board position."};
        }
        
        return mState[row * mNumCols + col];
    }
    
    int numRows() const {
        return mNumRows;
    }
    
    int numCols() const {
        return mNumCols;
    }
private:
    int mNumRows;
    int mNumCols;
    std::vector<char> mState;
};

#ifdef GRID_EXTERN
extern Grid grid;
#else
Grid grid{3, 3};
#endif
