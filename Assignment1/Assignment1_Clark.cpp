#include <iostream>
#include <string>
using namespace std;

// Base class Person with common attributes
class Person {
protected:
    string name; // Stores the name of the person
    int age;     // Stores the age of the person

public:
    Person() : name(""), age(0) {} // Constructor initializes members to default values

    // Method to input details for the person
    void setDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(); // Clear the newline character from input buffer
    }

    // Method to display details of the person
    void displayDetails() {
        cout << "Name: " << name << endl; // Output name on a separate line
        cout << "Age: " << age << endl;  // Output age on a separate line
    }
};

// Derived class Student
class Student : public Person {
private:
    int student_ID;  // Stores the student's ID
    string major;    // Stores the student's major

public:
    Student() : student_ID(0), major("") {} // Constructor initializes members to default values

    // Method to input details specific to a student
    void setStudentDetails() {
        setDetails(); // Call base class method to set common details
        cout << "Enter Student ID: ";
        cin >> student_ID;
        cin.ignore(); // Clear the newline character from input buffer
        cout << "Enter Major: ";
        getline(cin, major);
    }

    // Method to display details specific to a student
    void displayStudentDetails() {
        displayDetails(); // Call base class method to display common details
        cout << "Student ID: " << student_ID << endl;
        cout << "Major: " << major << endl;
    }
};

// Derived class Instructor
class Instructor : public Person {
public:
    Instructor() {} // Default constructor

    // Method to input details for an instructor (name and age only)
    void setInstructorDetails() {
        setDetails(); // Call base class method to set common details
    }

    // Method to display details of the instructor (name and age only)
    void displayInstructorDetails() {
        displayDetails(); // Call base class method to display common details
    }
};

// Class representing a course
class Course {
private:
    string course_name; // Stores the name of the course

public:
    Course() : course_name("") {} // Constructor initializes members to default values

    // Method to input the course name
    void setCourseName() {
        cout << "Enter Course Name: ";
        getline(cin, course_name);
    }

    // Method to display the course name
    void displayCourseName() {
        cout << "Course Name: " << course_name << endl;
    }
};

int main() {
    // Create a Student object
    Student student;

    // Prompt user for student's details
    student.setStudentDetails();

    // Create a Course object and prompt for course details immediately after student's major
    Course course;
    course.setCourseName();

    // Create an Instructor object
    Instructor instructor;

    // Prompt user for instructor's details
    instructor.setInstructorDetails();

    // Display all outputs in the correct order
    student.displayStudentDetails();
    course.displayCourseName();
    instructor.displayInstructorDetails();

    return 0;
}
