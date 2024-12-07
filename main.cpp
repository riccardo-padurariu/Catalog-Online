#include <bits/stdc++.h>
using namespace std;

/*
    User class
*/
class User{
private:
    string Name,Surname,Gender,Password;
    int ID,Age;
public:
    //User constructor
    User(string name,string surname,string gender,string password,int id,int age){
        Name = name;
        Surname = surname;
        Gender = gender;
        Password = password;
        ID = id;
        Age = age;
    }
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setSurname(string surname){
        Surname = surname;
    }
    string getSurname(){
        return Surname;
    }
    void setGender(string gender){
        Gender = gender;
    }
    string getGender(){
        return Gender;
    }
    void setPassword(string password){
        Password = password;
    }
    string getPassword(){
        return Password;
    }
    void setId(int id){
        ID = id;
    }
    int getId(){
        return ID;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }
};

/*
    Creating the Student class using Inheritance
*/
class Student:public User {
private:
    double Grade;
    string Year,Status="";
public:
    //Student constructor
    Student(string name,string surname,string gender,string password,int id,int age,int grade,string year)
        :User(name,surname,gender,password,id,age){
            Grade = grade;
            Year = year;
        }
    void setGrade(int grade){
        Grade = grade;
    }
    double getGrade(){
        return Grade;
    }
    void setYear(string year){
        Year = year;
    }
    string getYear(){
        return Year;
    }
    void setStatus(){
        if(Grade>=5)
            Status = "Promoted";
        else
            Status = "Failed";
    }
    string getStatus(){
        return Status;
    }

    void display(){
        cout << getName() << " " << getSurname() << " ID: " << getId() << ", Grade: " << getGrade() << ", Year: " << getYear() << " Status: " << getStatus() << '\n';
    }
};

/*
    Creating the Teacher class using Inheritance
*/
class Teacher : public User {
private:
    string MainClass,Subject;
public:
    //Teacher constructor
    Teacher(string name,string surname,string gender,string password,int id,int age,string mainclass,string subject)
        :User(name,surname,gender,password,id,age){
            MainClass = mainclass;
            Subject = subject;
        }

    void setMainClass(string mainclass){
        MainClass = mainclass;
    }
    string getMainClass(){
        return MainClass;
    }
    void setSubject(string subject){
        Subject = subject;
    }
    string getSubject(){
        return Subject;
    }

    void display(){
        cout << getName() << " " << getSurname() << " ID: " << getId() << ", Main class: " << getMainClass() << ", Subject: " << getSubject() << '\n';
    }
};


// The students array
vector<Student> students;
// The classes array
vector<string> classes;
//The teachers array
vector<Teacher> teachers;

void displayStudents(){
    if(students.size() == 0)
        cout << "There is no student added" << '\n';
    for(int i=0;i<students.size();i++){
        cout << i+1 << ". ";
        students[i].display();
    }
}

bool exists(string val,vector<string> s){
    for(auto i : s){
        if(i == val)
            return true;
    }
    return false;
}

void addStudent(){
    cout << "How many students do you want to add?" << '\n';
    int number;
    cin >> number;
    for(int i=1;i<=number;i++){
        string name,surname,gender,password,year;
        int id,age;
        double grade;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter grade: ";
        cin >> grade;
        Student s = Student(name,surname,gender,password,id,age,grade,year);
        s.setStatus();
        students.push_back(s);
        if(!exists(s.getYear(),classes))
            classes.push_back(s.getYear());
        cout << "Student succesfully added" << '\n';
    }
}

void deleteStudent(){
    if(students.size() == 0)
        cout << "There is no student to delete" << '\n';
    else{
        cout << "Enter the id you want to delete: ";
        int id;
        bool ok = false;
        cin >> id;
        for(int i=0;i<students.size();i++){
            if(students[i].getId() == id){
                ok = true;
                for(int j=i;j<students.size()-1;j++)
                    students[j] = students[j+1];
            }
        }
        students.pop_back();
        if(ok)
            cout << "Student deleted succesfully" << '\n';
        else
            cout << "The ID doesn't exist" << '\n';
    }
}


void displayTeachers(){
    if(teachers.size() == 0)
        cout << "There is no teacher added" << '\n';
    for(int i=0;i<teachers.size();i++){
        cout << i+1 << ". ";
        teachers[i].display();
    }
}

/*Function to prevent adding two main teacher to the same class*/
bool existsTeacher(string val){
    for(auto i : teachers){
        if(i.getMainClass() == val)
            return true;
    }
    return false;
}


void addTeacher(){
    string name,surname,gender,password,mainclass,subject;
    int id,age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter main class: ";
    cin >> mainclass;
    while(existsTeacher(mainclass)){
        cout << "Main teacher to this class already exists.Please enter another class: ";
        cin >> mainclass;
    }
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter subject: ";
    cin >> subject;
    Teacher t = Teacher(name,surname,gender,password,id,age,mainclass,subject);
    teachers.push_back(t);
    cout << "Teacher succesfully added" << '\n';
}

void deleteTeacher(){
    if(teachers.size() == 0)
        cout << "There is no teacher to delete" << '\n';
    else{
        cout << "Enter the id you want to delete: ";
        int id;
        bool ok = false;
        cin >> id;
        for(int i=0;i<teachers.size();i++){
            if(teachers[i].getId() == id){
                ok = true;
                for(int j=i;j<teachers.size()-1;j++)
                    teachers[j] = teachers[j+1];
            }
        }
        teachers.pop_back();
        if(ok)
            cout << "Teacher deleted succesfully" << '\n';
        else
            cout << "The ID doesn't exist" << '\n';
    }
}

/*Function to find the main teacher of a class*/
string findTeacher(string mainclass){
    for(auto i : teachers){
        if(i.getMainClass() == mainclass)
            return i.getName() + " " + i.getSurname();
    }
    return "Doesn't exist";
}

void displayClasses(){
    for(auto i : classes){
        cout << i << ": " << '\n';
        cout << "Main teacher: " << findTeacher(i) << '\n';
        for(auto j : students){
            if(j.getYear() == i)
                j.display();
        }
    }
}

int main()
{
    cout << "Online Catalog Opened" << '\n';
    while(true){
        cout << "Enter your choice: " << '\n';
        cout << "1. Display students" << '\n';
        cout << "2. Add students" << '\n';
        cout << "3. Delete students" << '\n';
        cout << "4. Display teachers" << '\n';
        cout << "5. Add teachers" << '\n';
        cout << "6. Delete teachers" << '\n';
        cout << "7. Display classes" << '\n';
        cout << "8. Close Catalog" << '\n';
        int choice;
        cin >> choice;
        switch(choice){
        case 1:
            displayStudents();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            displayTeachers();
            break;
        case 5:
            addTeacher();
            break;
        case 6:
            deleteTeacher();
            break;
        case 7:
            displayClasses();
            break;
        case 8:
            cout << "Catalog Closed" << '\n';
            exit(0);
        }
    }
    return 0;
}
