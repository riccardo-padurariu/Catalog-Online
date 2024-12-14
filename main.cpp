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
    vector<pair<int,string>> Grades[1001];
public:
    //Student constructor
    Student(string name,string surname,string gender,string password,int id,int age,int grade,string year)
        :User(name,surname,gender,password,id,age){
            Grade = grade;
            Year = year;
        }
    void setYear(string year){
        Year = year;
    }
    string getYear(){
        return Year;
    }
    void setStatus(){
        if(Grade != 0){
            if(Grade>=5)
                Status = "Promoted";
            else
                Status = "Failded";
        }else
            Status = "Undefined";
    }
    string getStatus(){
        return Status;
    }

    double getGrade(){
        return Grade;
    }

    void setGrade(int grade,string date,int index){
        Grades[index].push_back({grade,date});
        cout << "Grade added" << '\n';
        for(auto x : Grades[index]){
            cout << x.first << " ";
        }
        cout << '\n';
    }

    void displayStatistics(){
        vector<string> subjects = {"Romanian","English","French","Religion","Math","Physics","History","Geography","Biology"};
        for(int i=0;i<9;i++){
            cout << subjects[i] << ": ";
            if(Grades[i].size() == 0)
                cout << "No grades" << '\n';
            else{
                for(auto j : Grades[i]){
                    cout << j.first << "/" << j.second << " ";
                }
                cout << '\n';
            }
        }
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
        double grade=0;
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

/* Functions for the student management*/

void findStudent(int id){
    for(auto i : students){
        if(i.getId() == id)
            i.display();
    }
}

void addGrade(int id){
    int grade;
    string date,subject;
    cout << "Enter grade: ";
    cin >> grade;
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter subject number: " << '\n';
    cout << "0. Romanian" << '\n';
    cout << "1. English" << '\n';
    cout << "2. French" << '\n';
    cout << "3. Religion" << '\n';
    cout << "4. Math" << '\n';
    cout << "5. Physics" << '\n';
    cout << "6. History" << '\n';
    cout << "7. Geography" << '\n';
    cout << "8. Biology" << '\n';
    int choice;
    cin >> choice;
    int index;
    for(int i=0;i<students.size();i++){
        if(students[i].getId() == id)
            index = i;
    }
    cout << index << '\n';
    students[index].setGrade(grade,date,choice);
}

void addAbsent(int id){

}

void displayStatisticsStudent(int id){
    int index;
    for(int i=0;i<students.size();i++){
        if(students[i].getId() == id)
            index = i;
    }
    students[index].displayStatistics();
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
        cout << "8. Find student" << '\n';
        cout << "9. Close Catalog" << '\n';
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
            int id;
            cout << "Enter the id of the student: " << '\n';
            cin >> id;
            findStudent(id);
            cout << "1. Add grade" << '\n';
            cout << "2. Add absent" << '\n';
            cout << "3. Display grades" << '\n';
            cout << "4. Go back to main menu" << '\n';
            int choice2;
            cin >> choice2;
            switch(choice2){
            case 1:
                addGrade(id);
                continue;
                break;
            case 2:
                addAbsent(id);
                continue;
                break;
            case 3:
                displayStatisticsStudent(id);
                continue;
                break;
            case 4:
                continue;
                break;
            }
        case 9:
            cout << "Catalog Closed" << '\n';
            exit(0);
        default:
            cout << "Invalid choice" << '\n';
        }
    }
    return 0;
}
