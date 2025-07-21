#pragma once
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    float marks;
    int roll_no;

public:
    static int count;

    Student(string name, float marks, int roll_no);

    // Setters
    void setName(string name);
    void setMarks(float marks);
    void setRollNo(int roll_no);

    // Getters
    string getName();
    float getMarks();
    int getRollNo();

    // Display function
    void display();
};