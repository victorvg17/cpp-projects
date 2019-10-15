#include"sudoku_back_track.hpp"

namespace SudokuSolver{
  using namespace std;
  /**
    Sudoku class used in the project
  **/

  bool sudoku::findUnAssigned(int &row, int &col){
    // bool found = false;
    int N = 9;
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++){
        if (grid[row][col] == 0){
          //  row and col reference assigned value where grid[row][col] == unassigned.
          return true;
        }
      }
    }
    // cout<<"\n\nNo unassigned grid found"<<endl;
    return false; //no unassigned location is available. either soln is wrong or complete.
  }

  bool sudoku::usedInRow(int row, int num){
    int N = 9;
    for (int col = 0; col < N; col++) {
      if (grid[row][col] == num){
        return true;
      }
    }
    return false;
  }

  bool sudoku::usedInCol(int col, int num){
    int N = 9;
    for (int row = 0; row < N; row++) {
      if (grid[row][col] == num){
        return true;
        }
      }
      return false;
    }

  bool sudoku::usedInBox(int row, int col, int num){
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

  bool sudoku::isSafe(int row, int col, int num){
    bool safe = !this->usedInRow(row, num) && !this->usedInCol(col, num) && !this->usedInBox(row, col, num) && (grid[row][col] == 0);
    // bool clear = false;
    // if (safe){
    //     // cout<<"\n\nYo, we are good at row:  "<<row<<"col:  "<<col<<endl;
    //     // cout<<"_"<<endl;
    //     clear = true;
    // }
    return safe;
  }

  bool sudoku::solveSudoku(){
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

  void sudoku::printGrid(){
    int N = 9;
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        cout<<" "<<grid[row][col];
      }
      cout<<endl;
    }
  }

  void sudoku::setGridInput(int grid_sudoku[][9]){
    // N = size;
    // grid = grid_sudoku;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++){
        grid[i][j] = grid_sudoku[i][j];
      }
    }
  }

} //end namespace SudokuSolver
