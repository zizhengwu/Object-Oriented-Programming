#ifndef COURSE_H
#define COURSE_H value

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Course
{
public:
	Course(){};
	~Course(){};
private:
	string coursename;
	int coursescore;
};


#endif