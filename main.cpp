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
};

// The students array
vector<Student> students;

void displayStudents(){
    for(int i=0;i<students.size();i++)
        cout << i+1 << ". " << students[i].getName() << " " << students[i].getSurname() << " " << students[i].getId() << " " << students[i].getGrade() << " " << students[i].getYear() << " " << students[i].getStatus() << '\n';
}

void addStudent(){
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
    students.push_back(s);
    cout << "Student succesfully added" << '\n';
}

void deleteStudent(){
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
    if(ok)
        cout << "Student deleted succesfully" << '\n';
    else
        cout << "The ID doesn't exist" << '\n';
/* Tomorrow I have to sort the students in classes and then delete the respective id */
}

void displayTeachers(){

}

void addTeacher(){

}

void deleteTeacher(){

}

void displayClasses(){

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
