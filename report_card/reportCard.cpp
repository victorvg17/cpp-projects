#include "reportCard.hpp"


namespace reportCard{
  using namespace std;
  /**
  reportCard class used in project
  **/
  void student::calculate(){
    percentage = (p_mark + c_mark + m_mark + e_mark + cs_mark)/5;
    if (percentage >= 90){
      grade = 'A';
    }
    else if (percentage >= 80){
      grade = 'B';
    }
    else if (percentage >= 70){
      grade = 'C';
    }
    else if (percentage >= 60){
      grade = 'D';
    }
    else if (percentage >= 50){
      grade = 'E';
    }
    else {
      grade = 'F';
    }
  }

  void student::get_data(){
    cout<<"\nEnter student roll no: "<<endl;
    cin>>roll_no;
    cout<<"\nEnter student name : \n"<<endl;
    // cin>>name;
    cin.ignore();
    cin.getline(name, 20);
    cout<<"\nEnter marks in physics out of 100: "<<endl;
    cin>>p_mark;
    cout<<"\nEnter marks in chemistry out of 100: "<<endl;
    cin>>c_mark;
    cout<<"\nEnter marks in mathematics out of 100: "<<endl;
    cin>>m_mark;
    cout<<"\nEnter marks in english out of 100: "<<endl;
    cin>>e_mark;
    cout<<"\nEnter marks in computer science out of 100: "<<endl;
    cin>>cs_mark;
    calculate();
    return;
  }

  void student::show_data() const{
    cout<<"\nRoll number of student: "<<roll_no<<endl;
    cout<<"\nName of student: "<<endl;
    cout<<name<<endl;
    cout<<"\nPhysics marks: "<<p_mark<<endl;
    cout<<"\nChemistry marks: "<<c_mark<<endl;
    cout<<"\nMathematics marks: "<<m_mark<<endl;
    cout<<"\nEnglish marks: "<<e_mark<<endl;
    cout<<"\nComputer Science marks: "<<cs_mark<<endl;
    // cout<<"\nPercentage: "<<percentage<<endl;
    // cout<<"\nGrade: "<<grade<<endl;

  }

  void student::modify_report(){
    cout<<"\nRoll number: "<<roll_no<<endl;
    cout<<"\nEdit Physics mark: "<<endl;
    cin>>p_mark;
    cout<<"\nEdit Chemistry mark: "<<endl;
    cin>>c_mark;
    cout<<"\nEdit Mathematics mark: "<<endl;
    cin>>m_mark;
    cout<<"\nEdit English mark: "<<endl;
    cin>>e_mark;
    cout<<"\nEdit Computer Science mark: "<<endl;
    cin>>cs_mark;
    calculate();
  }

  void student::show_tabular() const{
    cout<<roll_no<<setw(10)<<" "<<name<<setw(10)<<p_mark<<setw(12)<<c_mark<<setw(12)<<m_mark<<setw(12)<<e_mark<<setw(17)<<cs_mark<<setw(13)<<percentage<<setw(13)<<grade<<endl;
  }

  int student::ret_roll_number() const{
    return roll_no;
  }
} //  end namespace reportCard
