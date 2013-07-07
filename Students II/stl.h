#ifndef STL_H
#define STL_H value

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "student.h"

using namespace std;

class Stl
{
public:
	Stl(){};
	~Stl(){};
	void getinput (ifstream & input);
	void showvector();
	void analyse();
	void optimizestudent();
	void printstudent();
	void printcourse();
private:
	vector <Student> student;
	vector <Course> course;
	vector <string> allcourse;
	vector <Student> optimizedstudent;
};

#endif