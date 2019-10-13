#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>

using namespace std;

void rules();
void drawLine(int n, char ch);

int main(){
  rules();
  int guess[3];
  // int guess;
  int no_chance = 3;
  char playerName[10];

  int amount;
  int bettingAmount;

  int dice;
  int dice_seed = 10;
  char choice;

  bool game_win = false; //WIN: true; LOSE: false;

  srand(time(0)); //Seed ramdom generator

  drawLine(60, '_');
  cout<<"\n\n\nCasino number guessing name\n\n\n"<<endl;
  drawLine(60, '_');

  cout<<"\n\nEnter player name:"<<endl;
  cin.getline(playerName, 10);
  // cout<<"player name: "<<playerName<<endl;
  cout<<"\n\nEnter amount to play:"<<endl;
  cin>>amount;

  do {

    do {
      /* code */
      cout<<"\n\nEnter amount to bet now:"<<endl;
      cin>>bettingAmount;
      // cin.ignore();
      // cin.get();
      if (bettingAmount > amount){
        cout<<"\n\nInsufficient balance to bet the amount: "<<bettingAmount<<endl;
      }
    } while(bettingAmount > amount);

    for (int i = 0; i < no_chance; i++) {
      /* code */
      do {
        /* code */
        cout<<"\n\nEnter your guess "<<i+1<<": "<<endl;
        cin>>guess[i];

        if((guess[i] < 0) || (guess[i] > 10)){
          cout<<"\n\nOnly number (1-10) allowed"<<endl;
        }
      } while((guess[i] < 0) || (guess[i] > 10));
    }


    dice = rand()%dice_seed + 1;

    int win_itr = 0;
    for (int i = 0; i < no_chance; i++) {
      if (guess[i] == dice){
        game_win = true;
        win_itr = i+1;
        break;
      }
    }

    if(game_win == true){
      amount = amount + bettingAmount*10;
      cout<<"\n\nCongrats! You won with chance "<<win_itr<<"."<<"Your updated balance: "<<amount<<endl;
    }
    else{
      amount = amount - bettingAmount;
      cout<<"\n\nSad! You lost. Your updated balance: "<<amount<<endl;
    }

    cout<<"\n\nDo you want to play again: (y / n)?"<<endl;
    cin>>choice;
  } while(choice == 'y' );

  cout<<"\n\nThank you for playing with casino."<<endl;
  cout<<"\n\nYour take home amount is: "<<amount<<endl;
  return 0;
}

void drawLine(int n, char ch){
  for (int i = 0; i < n;i++){
    cout<<ch;
  }
  cout<<"\n"<<endl;

}

void rules()
{
    system("clear");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}

// END OF PROGRAM
