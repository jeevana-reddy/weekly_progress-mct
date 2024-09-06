#include <iostream>
#include <string>
using namespace std;
class Student {
public:

        Student(string name, int age,string studentID)
        : name(name), age(age), studentID(studentID) {}

        void printDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
    }

    string name;
    int age;
    string studentID;
};

int main() {
    Student student("JEEVANA", 19, "5D5");

    student.printDetails();
    
    student.name = "ABHIGNA";
    student.age = 36;
    student.studentID = "1000d5";

    student.printDetails();

    return 0;
}
