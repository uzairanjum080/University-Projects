#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

struct Student {
    int roll;
    string name;
    float marks;
};

Student students[MAX];
int countStudents = 0;

// Function Declarations
void loadFromFile();
void saveToFile();
void addStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayStudents();
int findStudent(int roll);

int main() {
    int choice;
    loadFromFile();

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: displayStudents(); break;
            case 6: saveToFile(); cout << "Data saved. Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// ---------- Functions ----------

void loadFromFile() {
    ifstream file("students.txt");
    if (!file) return;

    file >> countStudents;
    for (int i = 0; i < countStudents; i++) {
        file >> students[i].roll;
        file.ignore();
        getline(file, students[i].name);
        file >> students[i].marks;
    }
    file.close();
}

void saveToFile() {
    ofstream file("students.txt");
    file << countStudents << endl;
    for (int i = 0; i < countStudents; i++) {
        file << students[i].roll << endl;
        file << students[i].name << endl;
        file << students[i].marks << endl;
    }
    file.close();
}

void addStudent() {
    if (countStudents >= MAX) {
        cout << "Maximum limit reached!\n";
        return;
    }

    cout << "Enter Roll Number: ";
    cin >> students[countStudents].roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, students[countStudents].name);

    cout << "Enter Marks: ";
    cin >> students[countStudents].marks;

    countStudents++;
    cout << "Student added successfully!\n";
}

int findStudent(int roll) {
    for (int i = 0; i < countStudents; i++) {
        if (students[i].roll == roll)
            return i;
    }
    return -1;
}

void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    int index = findStudent(roll);
    if (index == -1) {
        cout << "Student not found!\n";
    } else {
        cout << "Roll: " << students[index].roll << endl;
        cout << "Name: " << students[index].name << endl;
        cout << "Marks: " << students[index].marks << endl;
    }
}

void updateStudent() {
    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;

    int index = findStudent(roll);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, students[index].name);

    cout << "Enter New Marks: ";
    cin >> students[index].marks;

    cout << "Record updated successfully!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    int index = findStudent(roll);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = index; i < countStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    countStudents--;

    cout << "Record deleted successfully!\n";
}

void displayStudents() {
    if (countStudents == 0) {
        cout << "No records available.\n";
        return;
    }

    for (int i = 0; i < countStudents; i++) {
        cout << "\nRoll: " << students[i].roll;
        cout << "\nName: " << students[i].name;
        cout << "\nMarks: " << students[i].marks << endl;
    }
}

