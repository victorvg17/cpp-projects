#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

void rules();
void drawLine(int n, char ch);

int main(){
  rules();
  
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
