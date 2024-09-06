#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    void print() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string studentId;
    bool hasBacklogs;

public:
    Student(string n, int a, string id, bool backlogs) 
        : Person(n, a), studentId(id), hasBacklogs(backlogs) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Student ID: " << studentId << "\n";
        if (hasBacklogs) {
            cout << "SORRY!!!...YOUR Not eligible for training due to backlogs." << endl;
        } else {
            cout << "CONGRATULATIONS!!!...YOUR Eligible for training." << endl;
        }
    }
};

class Teacher : public Person {
private:
    string employeeId;
    string subject;
    int yearsOfExperience;

public:
    Teacher(string n, int a, string id, string subj, int exp) 
        : Person(n, a), employeeId(id), subject(subj), yearsOfExperience(exp) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Employee ID: " << employeeId << "\nSubject: " << subject << endl;
        
        if (yearsOfExperience >= 20) {
            cout << "Category: Professor" << endl;
        } else if (yearsOfExperience >= 10) {
            cout << "Category: Associate Professor" << endl;
        } else if (yearsOfExperience >= 5) {
            cout << "Category: Assistant Professor" << endl;
        } else {
            cout << "Category: Lecturer" << endl;
        }
    }
};

int main() {
    int choice;
    string name;
    int age;
    string id;
    string subject;
    bool hasBacklogs;
    int yearsOfExperience;

    cout << "Select an option:\n";
    cout << "1. Enter student information\n";
    cout << "2. Enter teacher information\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        // Input for Student
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter student age: ";
        cin >> age;
        cin.ignore(); 
        cout << "Enter student ID: ";
        getline(cin, id);
        cout << "Does the student have any backlogs? (1 for Yes, 0 for No): ";
        cin >> hasBacklogs;
        cin.ignore();

        Student student(name, age, id, hasBacklogs);

        cout << "\nStudent Information:\n";
        student.displayInfo();

    } else if (choice == 2) {
        
        cout << "Enter teacher name: ";
        getline(cin, name);
        cout << "Enter teacher age: ";
        cin >> age;
        cin.ignore(); 
        cout << "Enter employee ID: ";
        getline(cin, id);
        cout << "Enter subject: ";
        getline(cin, subject);
        cout << "Enter years of experience: ";
        cin >> yearsOfExperience;
        cin.ignore();

        Teacher teacher(name, age, id, subject, yearsOfExperience);
        cout << "\nTeacher Information:\n";
        teacher.displayInfo();

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
