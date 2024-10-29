#include <iostream>
using namespace std;

// Base class representing a generic department
class Department {
private:
    string departmentName = "N/A";
    int roomCount = 0;
    int facultyCount = 0;

public:
    // Method to take input for general department attributes
    void inputDetails() {
        cout << "Enter the department's name: ";
        getline(cin, departmentName);
        cout << "Enter the number of rooms: ";
        cin >> roomCount;
        cout << "Enter the number of faculty members: ";
        cin >> facultyCount;
    }

    // Method to display general department attributes
    void displayDetails() const {
        cout << "Department Name: " << departmentName 
             << "   Rooms: " << roomCount 
             << "   Faculty Members: " << facultyCount << endl;
    }
};

// Derived class for science department, adding specific attributes
class ScienceDepartment : public Department {
private:
    int labCount = 0;
    int researchCenters = 0;

public:
    // Method to take input for both general department and science-specific attributes
    void inputDetails() {
        cout << "- Science Department -" << endl;
        Department::inputDetails();
        cout << "Enter the number of labs: ";
        cin >> labCount;
        cout << "Enter the number of research centers: ";
        cin >> researchCenters;
        cin.ignore(); // Clear input buffer after integer input
        cout << endl;
    }

    // Method to display both general department and science-specific attributes
    void displayDetails() const {
        Department::displayDetails();
        cout << "Labs: " << labCount 
             << "   Research Centers: " << researchCenters << endl;
    }
};

// Derived class for arts department, adding specific attributes
class ArtsDepartment : public Department {
private:
    int studioCount = 0;
    int gallerySpace = 0;

public:
    // Method to take input for both general department and arts-specific attributes
    void inputDetails() {
        cout << "- Arts Department -" << endl;
        Department::inputDetails();
        cout << "Enter the number of studios: ";
        cin >> studioCount;
        cout << "Enter the gallery space (in square feet): ";
        cin >> gallerySpace;
        cin.ignore(); // Clear input buffer after integer input
        cout << endl;
    }

    // Method to display both general department and arts-specific attributes
    void displayDetails() const {
        Department::displayDetails();
        cout << "Studios: " << studioCount 
             << "   Gallery Space: " << gallerySpace << " sq ft" << endl;
    }
};

// Class representing a university that contains both science and arts departments
class University {
private:
    string universityName = "N/A";
    ScienceDepartment scienceDept;
    ArtsDepartment artsDept;

public:
    // Method to take input for the university and its departments
    void inputDetails() {
        cout << "Enter university name: ";
        getline(cin, universityName);
        scienceDept.inputDetails();
        artsDept.inputDetails();
    }

    // Method to display the university and its departments' details
    void displayDetails() const {
        cout << "University Name: " << universityName << endl;
        cout << "\n---- Science Department ----\n";
        scienceDept.displayDetails();
        cout << "\n---- Arts Department ----\n";
        artsDept.displayDetails();           
    }
};

int main() {
    University university;
    university.inputDetails();
    university.displayDetails();
    cout << "\n\n";
    return 0;
}
