#include "Student.h"
#include <iostream>
using namespace std;

int Student::count = 0;

Student::Student(string name, float marks, int roll_no) {
    this->name = name;
    this->marks = marks;
    this->roll_no = roll_no;

    count++;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setMarks(float marks) {
    this->marks = marks;
}

void Student::setRollNo(int roll_no) {
    this->roll_no = roll_no;
}

string Student::getName() {
    return name;
}

float Student::getMarks() {
    return marks;
}

int Student::getRollNo() {
    return roll_no;
}

void Student::display() {
    cout << endl;
    cout << "Name : " << name << endl;
    cout << "Roll Number : " << roll_no << endl;
    cout << "Marks : " << marks << endl;
}