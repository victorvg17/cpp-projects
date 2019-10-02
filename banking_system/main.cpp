#include<accountClass.h>
#include<iostream>

/**
  function declaration
**/
void write_account(); //function to write record in a binary file
void display_account_details(int); //function to display account details
void modify_account_details(int); //function to modify account details
void delete_account(int); //function to delete account
void display_all(); //function to display account details
void deposit_withdraw(int, int); //function to deposit/withdraw
void intro(); //introductory screen function

/**
  main function
**/
int main(){
  char ch;
  int num;
  intro();

  do{
    system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
    cin>>ch;
    system("cls");

    switch (ch) {
      case '1':
          write_account();
          break;
      case '2':
          cout<<"\n\nEnter account num"<<endl;
          cin>>num;
          deposit_withdraw(num, 1); //deposit amount given by num
          break;
      case '3':
          cout<<"\n\nEnter account num"<<endl;
          cin>>num;
          deposit_withdraw(num, 2); //withdraw amount given by num
          break;
      case '4':
          cout<<"\n\nEnter account num"<<endl;
          cin>>num;
          display_account_details(num);
          break;
      case '5':
          display_all();
          break;
      case '6':
          cout<<"\n\nEnter account num"<<endl;
          cin>>num;
          delete_account(num);
          break;
      case '7':
          cout<<"\n\nEnter account num"<<endl;
          cin>>num;
          modify_account_details(num); //withdraw amount given by num
          break;
      case '8':
          cout<<"\n\nThank you for using the banking system."
          break;
      default: cout<<"\a"
    }
    cin.ignore();
    cin.get();
  }while(ch != '8');
  return 0;
}
/**
  function to write in file
**/
void write_account(){
  account ac;
  
}
