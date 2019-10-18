#include"sudoku_back_track.hpp"
#include<iostream>
#include<stdlib.h>

using namespace std;
using namespace SudokuSolver;

int main(){
  // 0 means unassigned cells
  int grid[9][9] = {{0, 0, 0, 8, 0, 0, 9, 0, 0},
                    {8, 0, 0, 4, 0, 0, 5, 0, 0},
                    {0, 1, 6, 0, 9, 0, 0, 7, 4},
                    {0, 5, 0, 0, 0, 0, 6, 0, 1},
                    {0, 0, 0, 0, 5, 0, 0, 0, 0},
                    {7, 0, 2, 0, 0, 0, 0, 9, 0},
                    {9, 2, 0, 0, 6, 0, 3, 5, 0},
                    {0, 0, 8, 0, 0, 5, 0, 0, 9},
                    {0, 0, 4, 0, 0, 2, 0, 0, 0}};
    sudoku sud;
    sud.setGridInput(grid);
    if (sud.solveSudoku() == true){
      sud.printGrid();
    }
    // int grid_test[9] = {34, 45, 56, 67, 54, 66, 67, 76, 89};
    // sud.setArrayTest(grid_test);
    else{
      cout<<"\n\nNo solution for the given sudoku"<<endl;
    }
    return 0;
}
