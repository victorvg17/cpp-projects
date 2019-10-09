#include "reportCard.hpp"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
using namespace reportCard;

/**
  function declarations
**/
void write_student();	//write the record in binary file
void display_all();	//read all records from binary file
void display_sp(int roll_no);	//accept rollno and read record from binary file
void modify_student(int roll_no);	//accept rollno and update record of binary file
void delete_student(int roll_no);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();		//display result menu
void intro();		//display welcome screen
void entry_menu();	//display entry menu on screen

/**
  main function
**/
int main(){
  char ch;
  intro();
  do{
    system("clear");
    cout<<"\n\n\tMain menu"<<endl;
    cout<<"\n\n\t01. New student entry"<<endl;
    cout<<"\n\n\t02. Display all students entry"<<endl;
    // cout<<"\n\n\t03. Display specific student entry"<<endl;
    // cout<<"\n\n\t04. Modify student entry"<<endl;
    // cout<<"\n\n\t05. Delete student entry"<<endl;
    cout<<"\n\n\t03. Entry menu for specific student records"<<endl;
    cout<<"\n\n\t04. Result of the class"<<endl;
    cout<<"\n\n\t05. Exit the system"<<endl;
    cout<<"\n\n\tSelect your option (1-5):"<<endl;
    cin>>ch;
    system("clear");

    switch (ch){
      case '1':
        write_student();
        break;
      case '2':
        display_all();
        break;
      case '3':
        entry_menu();
        break;
      case '4':
        class_result();
        break;
      case '5':
        cout<<"\n\n\tThank you for using the report card system. Have a nice day"<<endl;;
        break;
      default:
        cout<<"\a";
    }
    cin.ignore();
    cin.get();
  } while(ch != '7'); //leave the application once user has pressed 7. or else keep app running
  return 0;
}

/**
  introduction function
**/
void intro(){
  cout<<"\n\n\n\t  REPORT CARD SYSTEM";
	cout<<"\n\n\t reference: http://www.cppforschool.com/project/student-report-card-project.html"<<endl;
  cin.get();
}
