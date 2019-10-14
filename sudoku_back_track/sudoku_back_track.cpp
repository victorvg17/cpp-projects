#include"sudoku_back_track.hpp"

namespace SudokuSolver{
  using namespace std;
  /**
    Sudoku class used in the project
  **/

  sudoku::bool findUnAssigned(int &row, int &col){
    // bool found = false;
    int N = 9;
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++){
        if (grid[row][col] == 0){
          return true;
        }
      }
    }
    return false; //no unassigned location is available. either soln is wrong or complete.
  }

  sudoku::bool usedInRow(int row, int num){
    int N = 9;
    for (int col = 0; col < N; col++) {
      if (grid[row][col] == num){
        return true;
      }
    }
    return false;
  }

  sudoku::bool usedInCol(int col, int num){
    int N = 9;
    for (int row = 0; row < N; row++) {
      if (grid[row][col] == num){
        return true;
        }
      }
      return false;
    }

  sudoku::bool usedInBox(int row, int col, int num){
    row = row - row%3;
    col = col - col%3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++){
        if (grid[row + i][col + j] == num){
          return true;
        }
      }
    }
    return false;
  }

  sudoku::bool isSafe(int row, int col, int num){
    bool safe = !this->usedInRow(row, num) && !this->usedInCol(col, num) && !this->usedInBox(row, col, num) && (grid[row][col] == 0);
    return safe;
  }

  sudoku::bool solveSudoku(){
    int N = 9;
    int row;
    int col;
    bool unassign = true;
    bool safe = false;

    unassign = this->findUnAssigned(row, col);
    if (!unassign){
      cout<<"\n\nNo unassigned grid. Complete. Exiting .."<<endl;
      return true;
    }
    for (int num = 1; num < N+1; num++) {
      safe = this->isSafe(row, col, num);
      if (safe){
        grid[col][row] = num;

        if(this->solveSudoku()){
          return true;  //a solution is obtained recursively
        }
        //undo the assignment since the assignment was not success
        grid[row][col]=0;
      }
    }
    return false; //we have tried (1-9) for the current level and no correct assignment found. Hence go back one level up and undo the assignment.
  }

  sudoku::void printGrid(){
    int N = 9;
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        cout<<" "<<grid[row][col];
      }
      cout<<endl;
    }
  }

  void setGridInput(int grid_sudoku[9][9]){
    // N = size;
    grid = grid_sudoku;
  }

} //end namespace SudokuSolver
