#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "diary.h"
#include <fstream>
#include <stdlib.h>
#include "convert.h"

using namespace std;

void Diary::add(ifstream & input, ifstream & ainput)
{
	bool isInteger(const std::string & s);
	string line;
	vector <long> date;
	vector <string> content;
	vector <int> count;
	int temp;
	temp = -1;
	while(getline(input, line)){
		if (isInteger(line)==1)
		{
			date.push_back(convertToLong(line));
			if (temp!=-1)
			{
				count.push_back(temp);
			}
			temp = 0;
		}
		else
		{
			content.push_back(line);
			temp = temp + 1;
		}
	}
	count.push_back(temp);
	temp = -1;


	while(getline(ainput, line)){
		if (isInteger(line)==1)
		{
			date.push_back(convertToLong(line));
			if (temp!=-1)
			{
				count.push_back(temp);
			}
			temp=0;
		}
		else
		{
			content.push_back(line);
			temp = temp + 1;
		}
	}
	count.push_back(temp);


	ofstream output("diarytemp.txt");
	temp=0;
	for (int i = 0; i < date.size(); ++i)
	{
		output << date[i] << endl;
		for (int i1 = 0; i1 < count[i]; ++i1)
		{
			output << content[temp] << endl;
			temp++;
		}
	}
}

bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}