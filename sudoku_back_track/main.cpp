#include"sudoku_back_track.hpp"
#include<iostream>
#include<stdlib.h>

using namespace std;
using namespace SudokuSolver;

int main(){
  // 0 means unassigned cells
  // int grid[9][9] = {{0, 0, 0, 8, 0, 0, 9, 0, 0},
  //                   {8, 0, 0, 4, 0, 0, 5, 0, 0},
  //                   {0, 1, 6, 0, 9, 0, 0, 7, 4},
  //                   {0, 5, 0, 0, 0, 0, 6, 0, 1},
  //                   {0, 0, 0, 0, 5, 0, 0, 0, 0},
  //                   {7, 0, 2, 0, 0, 0, 0, 9, 0},
  //                   {9, 2, 0, 0, 6, 0, 3, 5, 0},
  //                   {0, 0, 8, 0, 0, 5, 0, 0, 9},
  //                   {0, 0, 4, 0, 0, 2, 0, 0, 0}};
  int grid[9][9];

  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      cout<<"Enter element ["<<i+1<<","<<j+1<<"]"<<endl;
      cin>>grid[i][j];
    }
  }

  sudoku sud;
  sud.setGridInput(grid);
  sud.printGrid();

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
