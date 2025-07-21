#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function to add student
void add_Student(vector<Student>& student) {
    string name;
    float marks;
    int roll_no;

    cout << " \n\tEnter Student details \n Press Enter twice to exit \n";
    while (true) {
        cout << endl;
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);
        if (name.empty())
            break;
        else {
            cout << "Enter marks for " << name << " : ";
            cin >> marks;
            cout << "Enter roll_no of " << name << " : ";
            cin >> roll_no;
        }
        
        // saving data to vector
        student.emplace_back(name, marks, roll_no);
    }
    cout << endl;
    cout << " Student details entered successful " << endl << endl;
}

// function to display data
void display(vector<Student> student) {
    int Size = student.size();
    cout << endl;
    cout << " \t== Student Details ==";
    cout << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < Size; i++) {
        cout << "\tStudent " << i + 1;
        student[i].display();
        cout << endl;
    }
    cout << "--------------------------" << endl;
    cout << endl;
}

// function to delete a data

void delete_student(vector<Student>& student) {
    int choice;
    char confirm;
    int Size = student.size();
    bool found = false;

    cout << endl;
    cout << "Delete student by \n";
    cout << "1. Name \n2. Roll Number \n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Are you sure you want to delete? (Y / N): ";
    cin >> confirm;
    cout << endl;

    if (tolower(confirm) == 'y') {
     // del by name
        if (choice == 1) {
            string name;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            for (int i = 0; i < Size; i++) {
                if (student[i].getName() == name) {
                    student.erase(student.begin() + i);
                    found = true;
                    cout << "Student deleted.\n";
                    break;
                }
            }
            
        } else if (choice == 2) {
          // del ny Roll No
            int roll_no;
            cout << "Enter Roll Number: ";
            cin >> roll_no;
            for (int i = 0; i < Size; i++) {
                if (student[i].getRollNo() == roll_no) {
                    student.erase(student.begin() + i);
                    found = true;
                    cout << "Student deleted.\n";
                    break;
                }
            }
        } else {
            cout << "Invalid choice.\n";
            return;
        }

        if (!found) {
            cout << "Student does not exist.\n";
        }
    } else {
        cout << "Deletion terminated.\n";
    }
    cout << endl;
}

// function to search fro a student

void search_student(vector<Student>& student) {
    int choice;
    int Size = student.size();
    bool found = false;

    cout << endl;
    cout << "Search student by \n";
    cout << "1. Name \n2. Roll Number \n";
    cout << "Enter your choice : ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {
       //search by name
        string name;
        cin.ignore();
        cout << " Enter Name : ";
        cin >> name;
        for (int i = 0; i < Size; i++) {
            if (student[i].getName() == name) {
                student[i].display();
                found = true;
                break;
            }
        }
    } 
    else if (choice == 2) {
        // search ny roll number
        int roll_no;
        cout << "Enter Roll Number : ";
        cin >> roll_no;
        for (int i = 0; i < Size; i++) {
            if (student[i].getRollNo() == roll_no) {
                student[i].display();
                found = true;
                break;
            }
        }
    } else {
        cout << " Invalid input " << endl;
    }
    cout << endl;
    if (!found)
        cout << " Student does not exist " << endl;
    cout << endl;
}

// function to del data from vector

void del_data(vector<Student>& student) {
    char confirm;
    cout << endl;
    cout << "Are you sure you want to delete data from temporary storage " << endl;
    cout << "( Y / N ) :  ";
    cin >> confirm;
    
    if (tolower(confirm) == 'y') {
        student.clear();
        cout << endl;
        cout << " Data deleted successful " << endl;
        cout << "( Note : Data remains in file until deleted explicitly ) " << endl;
    } 
    else
        cout << " Deletion termimated " << endl;
    cout << endl;
}

//function to save data to file

void save_data(vector<Student>& student) {
    if (student.empty()) {
        cout << "No student data to save.\n";
        return;
    }
    char confirm;
    cout << "\nWARNING: This will overwrite all existing data in the file.\n";
    cout << "If you haven’t loaded previous data into the system, it will be lost permanently.\n";
    cout << "Do you want to continue saving? (Y/N): ";
    cin >> confirm;
    
    if (tolower(confirm) != 'y') {
        cout << "Saving cancelled.\n\n";
        return;
    }
    
    ofstream file("Student.txt", ios::trunc);
    
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }
    
    for (Student& s : student) {
        file << s.getName() << " " << s.getRollNo() << " " << s.getMarks() << endl;
    }
    
    file.close();
    cout << "\nData saved to file successfully.\n\n";
    
}

// function to load from file

void load_from_file(vector<Student>& student, int mode) {
    ifstream file("Student.txt");
    if (!file.is_open()) {
        cout << " Could not open Student.txt\n\n";
        return;
    }
    
    string name;
    int roll_no;
    float marks;
    
    // display data from file
    if (mode == 1) {
        cout << "\n Displaying Data from File:\n";
        while (file >> name >> roll_no >> marks) {
            cout << "Name: " << name << ", Roll No: " << roll_no << ", Marks: " << marks << endl;
        }
    }
    // save from from file to vector
      else if (mode == 2) {
        if (!student.empty()) {
            cout << "\n Vector already contains data. Appending may create duplicates.\n";
            cout << "Do you want to continue loading into the vector? (Y/N): ";
            char confirm;
            cin >> confirm;
            
            if (tolower(confirm) != 'y') {
                cout << "Loading cancelled by user.\n\n";
                file.close();
                return;
            }
        }
        
        while (file >> name >> roll_no >> marks) {
            Student s(name, roll_no, marks);
            student.push_back(s);
        }
        cout << "\n Data successfully loaded into vector.\n";
    }
     else {
        cout << "Invalid choice passed to function.\n";
    }
    file.close();
    cout << endl;
}


// functiom to del data from file
void del_file() {
    ofstream file("Student.txt", ios::trunc);
    if (!file)
        cout << "Error opening file " << endl;
    else {
        cout << "Data removed from file successful " << endl;
        cout << "(Note : Data may still exist in temporary storage ) " << endl;
    }
    cout << endl;
}

// function to handle all inputs

void manage_inputs(vector<Student>& student) {
    cout << " ○○ Student Management ○○ " << endl << endl;
    while (true) {
        int choice;
        cout << " Enter function to perform " << endl << endl;
        cout << "1. Add Student " << endl;
        cout << "2. View all students" << endl;
        cout << "3. Search for a student " << endl;
        cout << "4. Delete a student" << endl;
        cout << "5. Delete data from temporary storage " << endl;
        cout << "6. Save data to a file " << endl;
        cout << "7. Display data from file " << endl;
        cout << "8. Save data from file to temporary storage " << endl;
        cout << "9. Delete data from file " << endl;
        cout << "10. Check the total number of students " << endl;
        cout << "0. Exit program" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            add_Student(student);
            break;
        case 2:
            display(student);
            break;
        case 3:
            search_student(student);
            break;
        case 4:
            delete_student(student);
            break;
        case 5:
            del_data(student);
            break;
        case 6:
            save_data(student);
            break;
        case 7:
            load_from_file(student, 1);
            break;
        case 8:
            load_from_file(student, 2);
            break;
        case 9:
            del_file();
            break;
        case 10:
            cout << endl << " The total number of students enrolled till now are : " << Student::count << endl;
            cout << " The current number of students is : " << student.size() << endl;
            cout << endl;
            break;
        }
        if (choice == 0)
            break;
    }
}
