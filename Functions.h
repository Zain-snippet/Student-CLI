#pragma once
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

// File-related functions
void save_data(vector<Student>& student);
void load_from_file(vector<Student>& student, int mode);
void del_file();

// Student operations
void add_Student(vector<Student>& student);
void delete_student(vector<Student>& student);
void display(vector<Student> student);
void del_data(vector<Student>& student);
void search_student(vector<Student>& student);

// Input management
void manage_inputs(vector<Student>& student);