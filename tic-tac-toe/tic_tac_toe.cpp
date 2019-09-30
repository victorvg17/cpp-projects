
#include<iostream>
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

void board();
int checkwin();

int main(){
  int player = 1, choice, game_stat;
  char mark;

  do{
    board();
    player = (player%2)?1:2;
    cout << "Player"<<player<<", enter a number"<<endl;
    cin >> choice;

    mark = (player == 1)?'X' : 'O';

    if (square[1] == '1' && choice == 1){
      square[1] = mark;
    }
    else if (square[2] == '2' && choice == 2){
      square[2] = mark;
    }
    else if (square[3] == '3' && choice == 3){
      square[3] = mark;
    }
    else if (square[4] == '4' && choice == 4){
      square[4] = mark;
    }
    else if (square[5] == '5' && choice == 5){
      square[5] = mark;
    }
    else if (square[6] == '6' && choice == 6){
      square[6] = mark;
    }
    else if (square[7] == '7' && choice == 7){
      square[7] = mark;
    }
    else if (square[8] == '8' && choice == 8){
      square[8] = mark;
    }
    else if (square[9] == '9' && choice == 9){
      square[9] = mark;
    }
    else{
      cout << "Invalid move" << endl; //player lose chance; wait for next turn.
      player--;

      cin.ignore();
    }
    game_stat = checkwin();

    player++;

  }while (game_stat == -1);

  board();
  if(game_stat == 1){
    cout<<"==>\aPlayer "<<--player<<" win ";
  }

  else{
    cout<<"==>\aGame draw";
  }

  cin.ignore();
  cin.get();
  return 0;
}

/**
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**/
int checkwin(){
  if((square[1] == square[2]) && (square[2] == square[3])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[4] == square[5]) && (square[5] == square[6])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[7] == square[8]) && (square[8] == square[9])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[1] == square[4]) && (square[4] == square[7])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[2] == square[5]) && (square[5] == square[8])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[3] == square[6]) && (square[6] == square[9])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[1] == square[5]) && (square[5] == square[9])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if((square[3] == square[5]) && (square[5] == square[7])){
    return 1; //ladies and gentleman, we have a winner
  }
  else if(square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9'){
    return 0; //ladies and gentleman, we have a tie
  }
  else{
    return -1;
  }

}

/**
  Function to draw main board for tic-tac toe game
**/
void board(){
  cout<<"\n\ntic tac toe game \n\n"<<endl;

  cout<<"Player 1 (X) - Player 2 (0) \n\n"<<endl;
  cout<<endl;

  cout << "     |     |     " << endl;
  cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
  cout << "_____|_____|_____" << endl;

  cout << "     |     |     " << endl;
  cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
  cout << "_____|_____|_____" << endl;

  cout << "     |     |     " << endl;
  cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
}
