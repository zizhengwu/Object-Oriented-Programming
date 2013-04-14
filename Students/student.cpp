#include "student.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Student::~Student()
{
}

float Student::GetAverage()
{
	return ((score1 + score2 + score3) / 3.0);
}

int Student::GetScore1()
{
	return score1;
}

int Student::GetScore2()
{
	return score2;
}

int Student::GetScore3()
{
	return score3;
}

Student::Student()
{
	score1=0;
	score2=0;
	score3=0;
}

void Student::Initial(string getname, int getscore1, int getscore2, int getscore3)
{	
	name = getname;
	score1 = getscore1;
	score2 = getscore2;
	score3 = getscore3;
}

string Student::GetName()
{
	return name;
}