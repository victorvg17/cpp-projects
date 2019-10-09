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

  void student::getdata(){
    cout<<"\nEnter student roll no: \n"<<endl;
    cin>>roll_no;
    cout<<"\nEnter student name : \n"<<endl;
    // cin>>name;
    cin.get(name, 20);
    cout<<"\nEnter marks in physics out of 100: \n"<<endl;
    cin>>p_mark;
    cout<<"\nEnter marks in chemistry out of 100: \n"<<endl;
    cin>>c_mark;
    cout<<"\nEnter marks in mathematics out of 100: \n"<<endl;
    cin>>m_mark;
    cout<<"\nEnter marks in english out of 100: \n"<<endl;
    cin>>e_mark;
    cout<<"\nEnter marks in computer science out of 100: \n"<<endl;
    cin>>cs_mark;
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

  }

  void student::show_tabular() const{
    cout<<roll_no<<setw(6)<<" "<<name<<setw(10)<<p_mark<<setw(5)<<c_mark<<setw(5)<<m_mark<<setw(5)<<e_mark<<setw(5)<<cs_mark<<setw(8)<<percentage<<setw(5)<<grade<<endl;
  }

  int student::ret_roll_number() const{
    return roll_no;
  }
} //  end namespace reportCard
