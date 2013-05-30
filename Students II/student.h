#ifndef STUDENT_H
#define STUDENT_H value
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "course.h"

using namespace std;

class Student
{
public:
	Student(){};
	~Student(){};
private:
	int no;
	string name;
	vector <Course> course;
};

#endif