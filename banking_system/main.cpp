#include "accountClass.hpp"
#include<iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;
using namespace bank;
/**
  function declaration
**/
void write_account(); //function to write record in a binary file
void display_account_details(int account_no); //function to display account details
void modify_account_details(int account_no); //function to modify account details
void delete_account(int account_no); //function to delete account
void display_all(); //function to display account details
void deposit_withdraw(int account_no, int choice); //function to deposit/withdraw
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
          cout<<"\n\nThank you for using the banking system.";
          break;
      default: cout<<"\a";
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
  ofstream outFile;
  outFile.open("account.dat", ios::binary|ios::app);
  ac.create_account();
  outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
  outFile.close();
}
/**
  function to read specific record from file
**/
void display_account_details(int account_no){
  account ac;
  bool flag = false;
  ifstream inFile;
  inFile.open("account.dat", ios::binary);
  if (!inFile){
    cout<<"\n\nFile could not be opened. Press any key to exit"<<endl;
    return;
  }
  cout<<"\n\nBalance Details"<<endl;
  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
    if (ac.return_account_no() == account_no){
      ac.show_account();
      flag = true;
    }
  }
  inFile.close();
  if (flag == false){
    cout<<"\n\nAccount details does not exist"<<endl;
  }
}
/**
  function to modify record of file
**/
void modify_account_details(int account_no){
  account ac;
  bool found = false;
  fstream File;
  File.open("account.dat", ios::binary|ios::in|ios::out);
  if (!File){
    cout<<"\n\nFile could not be opened. Press any key to exit"<<endl;
    return;
  }

  while(!File.eof() && found == false)
  {
    File.read(reinterpret_cast<char *> (&ac), sizeof(account));
    if(ac.return_account_no() == account_no)
    {
      ac.show_account();
      cout<<"\n\nEnter new account details"<<endl;
      ac.modify_account();
      int pos = (-1)*static_cast<int>(sizeof(account));
      File.seekp(pos, ios::cur);
      File.write(reinterpret_cast<char *> (&ac), sizeof(account));
      cout<<"\n\nAccount details updated"<<endl;
      found = true;
    }
  }
  File.close();
  if (found == false){
    cout<<"\n\nAccount details does not exist"<<endl;
  }
}
/**
  function to delete record of file
**/
void delete_account(int account_no){
  account ac;
  bool found = false;
  ifstream inFile;
  ofstream outFile;
  inFile.open("account.dat", ios::binary);

  if (!inFile){
    cout<<"\n\nFile could not be opened. Press any key to exit"<<endl;
    return;
  }
  outFile.open("temp.dat", ios::binary);
  inFile.seekg(0, ios::beg);
  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
  {
    if (ac.return_account_no() != account_no)
    {
      outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    }
  }
  inFile.close();
  outFile.close();
  remove("account.dat");
  rename("temp.dat", "account.dat");
  cout<<"Account deleted"<<endl;
}

/**
  function to display all account list
**/
void display_all(){
  account ac;
  ifstream inFile;
  inFile.open("account.dat", ios::binary);
  if (!inFile){
    cout<<"\n\nFile could not be opened. Press any key to exit"<<endl;
    return;
  }
  cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
  {
    ac.report();
  }
  inFile.close();
}

/**
  function to deposit and withdraw amount
**/
void deposit_withdraw(int account_no, int choice){
  account ac;
  fstream File;
  int amount;
  bool found = false;
  File.open("account.dat", ios::binary|ios::in|ios::out);

  if (!File){
    cout<<"\n\nFile could not be opened. Press any key to exit"<<endl;
    return;
  }



  while(!File.eof() && found == false)
  {
    File.read(reinterpret_cast<char *> (&ac), sizeof(account));
    if (ac.return_account_no() == account_no){
      ac.show_account();

      if (choice == 1){
          cout<<"\n\n\tTO DEPOSITE AMOUNT ";
          cout<<"\n\nEnter amount to be deposited"<<endl;
          cin>>amount;
          ac.deposit_amount(amount);
      }

      else if (choice == 2){
          cout<<"\n\n\tTO WITHDRAW AMOUNT ";
          cout<<"\n\nEnter amount to withdraw"<<endl;
          cin>>amount;
          int bal = ac.return_deposit_amount() - amount;
          if (bal < 500 && ac.return_account_type() == 'S'){
            cout<<"\n\nCannot process request. Insufficient balance"<<endl;
          }
          else if (amount < ac.return_deposit_amount()){
            ac.draw_amount(amount);
          }

      }
      int pos = (-1)*static_cast<int>(sizeof(account));
      File.seekp(pos, ios::cur);
      File.write(reinterpret_cast<char *> (&ac), sizeof(account));
      cout<<"\n\nAccount details updated"<<endl;
      found = true;
    }
  }
  File.close();
  if (found == false){
    cout<<"\n\nAccount details does not exist"<<endl;
  }
}

/**
  introduction function
**/

void intro(){
  cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
  cout<<"\n\n\t reference: http://www.cppforschool.com/project/banking-system-project.html"<<endl;
  cin.get();
}
