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

/**
  function for entering details
*/
void write_student(){
  student st;
  ofstream outFile;
  outFile.open("student.dat", ios::binary|ios::app);
  st.get_data();
  // st.calculate();
  outFile.write(reinterpret_cast <char *> (&st), sizeof(student));
  outFile.close();
}

void display_all(){
  ifstream inFile;
  student st;
  inFile.open("student.dat", ios::binary);
  if (!inFile){
    cout<<"\n\n\tFile could not be opened. Press any key to exit"<<endl;
    return;
  }
  cout<<"\n\n\tRecords of all students"<<endl;
  cout<<"==================================================================================================================\n";
	cout<<"Roll no.      NAME      Physics  Chemistry  Mathematics  English  Computer Science    Percentage    Grade\n";
	cout<<"==================================================================================================================\n";
  while(inFile.read(reinterpret_cast <char *> (&st), sizeof(student))){
    st.show_tabular();
  }
  inFile.close();
}

/**
  function for displaying entry menu allowing for editing and displaying of individual student
**/
void entry_menu(){
  cout<<"\n\n\tEntry Menu"<<endl;
  char ch;
  int roll_no;

  do {
    system("clear");
    cout<<"\n\n\t01. Display specific student entry"<<endl;
    cout<<"\n\n\t02. Modify student entry"<<endl;
    cout<<"\n\n\t03. Exit Entry menu"<<endl;

    cout<<"\n\n\tSelect your option (1-4):"<<endl;
    cin>>ch;
    system("clear");

    switch (ch) {
      case '1':
        cout<<"\n\n\tEnter student rollno"<<endl;
        cin>>roll_no;
        display_sp(roll_no);
        break;

      case '2':
        cout<<"\n\n\tEnter student rollno"<<endl;
        cin>>roll_no;
        modify_student(roll_no);
        break;

      case '3':
        cout<<"\n\n\tThank you for using student entry menu"<<endl;
        break;

      default:
        cout<<"\a";
    }
    cin.ignore();
    cin.get();

  } while(ch != '3');
  return 0;

}

/**
  function for displaying student entry
**/
void display_sp(int roll no){
  ifstream inFile;
  student st;
  
}
