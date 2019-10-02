#include<accountClass.h>

using namespace std;

void account::create_account(){
  cout<<"\nEnter account no: \n"<<endl;
  cin>>account_no;
  cout<<"Enter account holder name"<<endl;
  cin.ignore();
  cin.getline(account_name, 50);
  cout<<"Enter type of account (C/ S)"<<endl;
  cin>>account_type;
  account_type = toupper(account_type);
  cout<<"Enter the initial deposit"<<endl;
  cin>>deposit;
  cout<<"Account:"<<account_no<<" created"<<endl;
}

void account::show_account() const{
  cout<<"\nAccount number: "<<account_no<<endl;
  cout<<"\n Account holder name: "<<endl;
  cout<<account_name
  cout<<"\n Account type: "<<account_type<<endl;
  cout<<"\n Account balance: "<<deposit<<endl;
}

void account::modify_account(){
  cout<<"\nAccount number: "<<account_no<<endl;
  cout<<"\nModify account holder name: "<<endl;
  cin.ignore();
  cin.getline(account_name, 50);
  cout<<"\nModify account type: "<<endl;
  cin>>account_type;
  account_type = toupper(account_type);
  cout<<"\nModify account balance: "<<endl;
  cin>>deposit;
}

void account::deposit_amount(int amount){
  deposit += amount;
}

void account::draw_amount(int amount){
  deposit -= amount;
}

void account::report() const{
  cout<<account_no<<setw(10)<<" "<<account_name<<setw(10)<<" "<<deposit<<setw(10)<<" "<<account_type<<endl;
}

int account::return_account_no() const{
  return account_no;
}

int account::return_deposit_amount() const{
  return deposit;
}

char account::return_account_type() const{
  return account_type;
}
