#ifndef STUDENT_H_
#define STUDENT_H_ value

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student
{
public:
	Student();
	~Student();
	string GetName();
	int GetScore1();
	int GetScore2();
	int GetScore3();
	float GetAverage();
	void Initial(string getname, int getscore1, int getscore2, int getscore3);
private:
	string name;
	int score1;
	int score2;
	int score3;
};

#endif