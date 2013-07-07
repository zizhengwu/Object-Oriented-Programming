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
	inline Student (int tempno, string tempname, vector <Course> tempcourse){
		no = tempno;
		name = tempname;
		course = tempcourse;
	}
private:
	friend class Stl;
	int no;
	string name;
	vector <Course> course;
};

#endif