#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
///----------/department
class Department
{
private:
    string name;
    int capacity;
    double requiredGPA;

public:
    Department() {}
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
    ~Department() {}
};

//----------//
class Person
{
protected:
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
    void set_id(int _id)
    {
        id = _id;
    }

    void set_name( string _name)
    {
        name = _name;
    }

    void set_age(int _age)
    {
        age = _age;
    }

    void set_gender(char _gender)
    {
        gender = _gender;
    }

    // Getters
    int get_id()
    {
        return id;
    }

    string get_name()
    {
        return name;
    }

    int get_age()
    {
        return age;
    }

    char get_gender()
    {
        return gender;
    }
    ~Person() {}
};
///-------------/
///---student class////


class Student:public Person
{
private:

    int level ;
    double gpa ;

public:
    Student(int id, string name,int age,char gender,int l,double g)
    {
        this->id=id;
        this->name=name;
        this->age=age;
        this->gender=gender;
        level=l;
        gpa=g;
    }
    void set_level(int lev)
    {
        level=lev;
    }
    void set_gpa(double g)
    {
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
    ~Student() {}

};
///------------//
class Professor: public Person
{
private:
    double salary;
    string degree;
    Department *department;
public:
    Professor(int id,string n,int age,Department *department,char g,double s, string d)
    {
        this -> id = id;
        this -> name = n ;
        this -> age = age;
        this -> salary = s;
        this -> degree = d ;
        this->department=department;

    }
    void set_salary(double s)
    {
        this-> salary = s;
    }
    void set_degree(string d)
    {
        this-> degree = d;
    }
    void set_department( Department *department)
    {
        this-> department = department;
    }
    double get_salary()
    {
        return salary;
    }
    string get_degree()
    {
        return degree;
    }
    Department* get_department()
    {
        return department;
    }

    ~Professor() {}
};


//---------------//
/// class course
class Course
{
private:
    string courseName;
    string courseCode;
    int courseHours;
    vector<Course*>prerequisites;
    vector<Student*>students;
    Professor *professor;

public:
    Course(string courseName,string courseCode,int courseHours,vector<Course*>pre,vector <Student*> s, Professor *professor)
    {
        this->courseName=courseName;
        this->courseCode=courseCode;
        this->courseHours=courseHours;
        this->prerequisites=pre;
        this->students=s;
        this->professor=professor;
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
    void set_prerequisites(vector <Course*> prerequisites)
    {
        this->prerequisites=prerequisites;
    }
    void set_students(vector <Student*> students)
    {
        this->students=students;
    }
    void set_professor(Professor *professor)
    {
        this->professor=professor;
    }
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
    vector<Course*> get_prerequisites()
    {
        return prerequisites;
    }
    vector<Student*> get_students()
    {
        return students;
    }
    Professor* get_professor()
    {
        return professor;
    }

    ~Course() {};
};


//......//
class University
{

private:
    vector<Department*>departments;
    vector<Student*>students;
    vector<Course*>courses;
    vector<Professor*>professors;
    static University* ptr;
    University()
    {
        addData();
    }

public:

    University(const University& obj)=delete;

    static University* getInstance()
    {

        if(ptr==NULL)
        {
            ptr = new University();
        }
        return ptr;
    }
    ///--------------------/
    void add_courses(string courseName,string courseCode,int courseHours,vector<Course*>pre,vector <Student*> s, Professor *professor)
    {

        Course ob1(courseName,courseCode,courseHours,pre,s,professor);
        courses.push_back(&ob1);
    }
    void update_courseHours(string CODE,int h)
    {

        for(auto i:courses)
        {
            if(i->get_courseCode()==CODE)
            {
                i->set_courseHours(h);
                return;
            }
        }
    }
    void delete_course(string code)
    {
        for(int i=0; i<courses.size(); i++)
        {
            if (courses[i]->get_courseCode() == code)
            {
                courses.erase(courses.begin() + i );
                return;
            }
        }

    }
    ///----------------------------/
    void add_student(int id,string name,int age,char gender,int level,double gpa)

    {

        Student obj2(id,name,age,gender,level,gpa);

        students.push_back(&obj2);

    }
    void update_level(int id,int level)
    {
        for (auto i:students)
        {
            if(i->get_id()==id)
            {
                i->set_level(level);
                return;
            }
        }
    }

    void delete_student(int id)
    {

        for(int i=0; i<students.size(); i++)
        {
            if (students[i]->get_id() == id)
            {
                students.erase(students.begin() + i );
                return;
            }
        }
    }



    ///-------------/
    void add_department(string name,int capacity,double gpa)
    {
        Department ob3(name,capacity,gpa);
        departments.push_back(&ob3);
    }
    void add_profesor(int id,string n,int age,Department *department,char g,double s, string d)
    {
        Professor p( id, n, age,department, g, s,d);
        professors.push_back(&p);
    }
    /****** delete*/
    void delete_Department(string name)
    {

        for(int i=0; i<departments.size(); i++)
        {
            if (departments[i]->get_name() == name)
            {
                departments.erase(departments.begin() + i );
                return;
            }
        }
    }

    void delete_Profesor(int id)
    {
        for(int i=0; i<professors.size(); i++)
        {
            if (professors[i]->get_id() == id)
            {
                professors.erase(professors.begin() + i );
                return;
            }
        }
    }
    /***   update*/
    void update_department(string n,int c)
    {

        for(auto i:departments)
        {
            if (i->get_name()==n)
            {
                i->set_capacity(c);
            }
        }
    }
    void update_profesor(int id,double s)
    {

        for(auto i:professors)
        {
            if (i->get_id()==id)
            {
                i->set_salary(s);
            }
        }
    }
    ///-----------///
    void addData()
    {
        Department d1("Web_Development", 50, 3.2);
        departments.push_back(&d1);
        Department d2("Cyber_Security", 33, 3.5);
        departments.push_back(&d2);
        Department d3("cs", 20, 3.0);
        departments.push_back(&d3);
        Department d4("Information_Systems", 125, 2.5);
        departments.push_back(&d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(&s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(&s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(&s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(&s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(&s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(&s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(&s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(&s8);



        Professor p1(1,"Mohamed Ali", 56, &d1,'M', 12000, "Masters");
        professors.push_back(&p1);
        Professor p2(2,"Ehsan Ahmed", 43, &d2,'M',  8500, "Masters");
        professors.push_back(&p2);
        Professor p3(3,"Ahmed Mohsen", 68, &d3,'M',  19380, "Masters");
        professors.push_back(&p3);
        Professor p4(4,"Abdelhady", 61, &d4,'M', 22728, "Masters");
        professors.push_back(&p4);
        Professor p5(5,"Taghreed Mohsen", 49 ,&d2,'F', 11068, "Masters");
        professors.push_back(&p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), st1, &p1);
        courses.push_back(&c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1, st2,&p3);
        courses.push_back(&c2);
        Course c3("Networks", "Net521", 18, crs1, st2,&p5);
        courses.push_back(&c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i]->get_name()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i]->get_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i]->get_name()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i]->get_courseName()<<endl;
        }
    }

};
///............//
///---------------//
///-----------------------------//
University* University::ptr = NULL;
///----------------/

int main()
{

    University *object=University::getInstance();
    object->printAll();
    object->delete_course("HTML123");
        object->printAll();


    return 0;
}
