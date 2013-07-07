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
	inline Course(string name, int score){
		coursename = name;
		coursescore = score;
	}
private:
	friend class Stl;
	string coursename;
	int coursescore;
};


#endif