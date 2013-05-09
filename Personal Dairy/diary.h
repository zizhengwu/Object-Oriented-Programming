#ifndef DIARY_H_
#define DIARY_H_ value

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>


using namespace std;

class Diary
{
public:
	Diary(){};
	~Diary(){};
	void add(ifstream & input);

private:
	vector <long> date;
	vector <string> content;
	vector <int> order;
};



#endif