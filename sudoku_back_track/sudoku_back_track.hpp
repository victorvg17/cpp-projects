#include<iostream>
#include<stdlib.h>

namespace SudokuSolver{
  using namespace std;
  /**
    Sudoku class used in the project
  **/
  class sudoku{
    // int N;  //dim of Sudoku
    int grid[9][9];

    // int grid_test[9];

  public:
    void setGridInput(int grid_sudoku[][9]);  //function to assign grid at runtime to be solved.
    // void setArrayTest(int grid_sudoku[9]);  //test function to set 1-D array.

    void printGrid(); //function for printing the sudoku grid
    bool isSafe(int row, int col, int num);  //for checking if a particular location (row, col) is safe to be assigned value.
    bool solveSudoku();
    bool findUnAssigned(int &row, int &col);

    // void assignGrid(int grid_sudoku[9][9]);

    bool usedInRow(int row, int num);
    bool usedInCol(int col, int num);
    bool usedInBox(int row, int col, int num);

  };

} //end namespace SudokuSolver
