#include<iostream>
#include<fstream>
#include<iomanip>

namespace reportCard{
  using namespace std;
  /**
  reportCard class used in project
  **/
  class student{
    int roll_no;
    char name[20];
    int p_mark, c_mark, m_mark, e_mark, cs_mark;
    double percentage;
    char grade[6];
    void calculate();

  public:
    void getdata();
    void show_data() const;
    void show_tabular() const;
    int ret_roll_number() const;
  };
} //  end namespace reportCard
