#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
///----------/department
class Department{
private:
    string name;
    int capacity;
    double requiredGPA;
public:
    Department(){}
    Department(string n,int c,double gpa)
    {
        this-> name = n ;
        this-> capacity = c;
        this-> requiredGPA = gpa;
    }
    void set_name(string n)
    {
        this-> name = n ;
    }
    void set_capacity(int c)
    {
        this-> capacity = c ;
    }
     void set_gpa(double g)
    {
        this-> requiredGPA = g ;
    }
    string get_name()
    {
        return name;
    }
    int get_capacity()
    {
        return capacity;
    }
    double get_gpa()
    {
        return requiredGPA;
    }
};

//----------//
class Person {
private:
    int id;
    string name;
    int age;
    char gender;

public:
    // Default constructor
    Person()
     {}

    // Parameterized constructor
    Person(int _id,  string _name, int _age, char _gender)
        : id(_id), name(_name), age(_age), gender(_gender) {}

    // Setters
    void set_id(int _id) {
        id = _id;
    }

    void set_name( string _name) {
        name = _name;
    }

    void set_age(int _age) {
        age = _age;
    }

    void set_gender(char _gender) {
        gender = _gender;
    }

    // Getters
    int get_id() {
        return id;
    }

     string get_name()  {
        return name;
    }

    int get_age(){
        return age;
    }

    char get_gender() {
        return gender;
    }
};
///-------------/
///---student class////


class Student:public Person  {
  private:

  int level ;
  double gpa ;

  public:

  void set_level(int lev)
   {
       level=lev;
   }
  void set_gpa(double g){
      gpa=g;
  }
   int get_level()
   {
       return level ;
   }
  double get_gpa()
  {
      return gpa ;
  }


};
///------------//
class Professor: public Person
{
  private:
    double salary;
    string degree;

    public:
    Professor()
    {

    }
    Professor(double s , string d)
    {
        this-> salary = s;
        this-> degree = d ;
    }
    void set_salary(double s)
    {
        this-> salary = s;
    }
     void set_degree(string d)
    {
        this-> degree = d;
    }
    double get_salary()
    {
        return salary;
    }
    string get_degree()
    {
        return degree;
    }


};


//---------------//
/// class course
class Course
{
private:
    string courseName;
    string courseCode;
    int courseHours;
    vector<Course>prerequisites;
    vector<Student>students;
    Professor professor;

public:
    Course(string courseName,string courseCode)
    {
    this->courseName=courseName;
    this->courseCode=courseCode;
    }
    void set_courseName(string courseName)
    {
        this->courseName=courseName;
    }
    void set_courseCode(string courseCode)
    {
        this->courseCode=courseCode;
    }
    void set_courseHours(int courseHours)
    {
        this->courseHours=courseHours;
    }
    void set_prerequisites(vector <Course> prerequisites)
    {
        this->prerequisites=prerequisites;
    }
    void set_students(vector <Student> students)
    {
        this->students=students;
    }
  /* void set_professor()
    {
        professor=professor.set_name();
    }*/
    string get_courseName()
    {
        return courseName;
    }
    string get_courseCode()
    {
        return courseCode;
    }
    int get_courseHours()
    {
        return courseHours;
    }
    vector<Course> get_prerequisites()
    {
        return prerequisites;
    }
    vector<Student> get_students()
    {
        return students;
    }
    string get_professor()
    {
        return professor.get_name();
    }

};


//......//
class University{

private:
    static University* ptr;
    University(){
    }

public:
     University(const University& obj)=delete;

static University* getInstance()
{

    if(ptr==NULL){
        ptr = new University();
    }
    return ptr;
}


};
//............//
///////////---------------//
//-----------------------------//
 University* University::ptr = NULL;
int32_t main()
{
    Course ob1("cs","10e");
    return 0;
}
