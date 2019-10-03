#include<iostream>
#include<fstream>
#include<iomanip>

namespace bank{
using namespace std;

/**
Account class used in the project
**/
class account{
  int account_no;
  char account_name[50];
  int deposit;
  char account_type;

public:
  void create_account(); //for getting data from customer
  void show_account() const; //function to show data on screen
  void modify_account();  //function to add new data
  void deposit_amount(int amount);  //to accept deposit and add to current deposit
  void draw_amount(int amount); //to draw amount deposit and reduce from current deposit
  void report() const;  //to show account details in tabular form; const: read only
  int return_account_no() const;  //to return account number
  int return_deposit_amount() const;  //to return current amount in deposit
  char return_account_type() const; //return type of account
};

} //namespace bank
