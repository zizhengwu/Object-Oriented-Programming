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
private:
	vector <Student> student;
};

#endif