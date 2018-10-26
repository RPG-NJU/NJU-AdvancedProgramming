#include "Student.h"

Student::Student(int id, const char* name, int date, const char* department, const char* major):Member(id, name, date, department), Major(major) {}

