#include <iostream>
#include <string>
using namespace std;

class Person {
        protected:
        string name;
        int age;

public:
    Person(string name = "Unkown", int age = 0) : name(name), age(age) {}

    void printInfo() const {
        cout << "Name: " << name << ", Age: " << age <<endl;
    }
};

class Student : public Person {
    private:
        string studentID;
        string major;
    public:
        Student(string name, int age,string studentID, string major)
            : Person (name, age), studentID(studentID), major(major) {}

        void printStudentInfo() const {
            printInfo();
            cout << "Student ID: " << studentID << ", Major: " << major << endl;
        }
};

class Course {
    private:
        string courseName;
        Person instructor;

    public:
        Course(string courseName, const Person & instructor)
            : courseName(courseName), instructor(instructor) {}

        void printCourseDetails() const {
            cout << "Course Name: " << courseName << endl;
            cout << "Instructor Details: ";
            instructor.printInfo();
        }
};

int main() {
    Person instructor("Professor Burgala", 28);

    Student student("Michael Clark", 21, "1129721", "Computer Science");

    Course course("Computer Science II", instructor);

    cout << "Student Details (Inheritance):" << endl;
    student.printStudentInfo();

    cout << endl;

    cout << "Course Details (Composition):" << endl;
    course.printCourseDetails();

    return 0;
}
