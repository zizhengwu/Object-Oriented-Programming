#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "diary.h"
#include <fstream>
#include <stdlib.h>
#include "convert.h"

using namespace std;

void Diary::add(ifstream & input)
{
	date.clear();
	content.clear();
	count.clear();
	ofstream output;
	bool isInteger(const std::string & s);
	string line;
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
	output.open("diarytemp.txt",ios::app);
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
	output.close();
}

void Diary::show(long & day,ifstream &input)
{
	long getday;
	date.clear();
	content.clear();
	count.clear();
	ofstream output;
	bool isInteger(const std::string & s);
	string line;
	int temp;
	temp = 0;
	output.open("show.txt");
	

	while(getline(input, line)){
		if (isInteger(line)==1)
		{
			getday = convertToLong(line);
			if (getday == day)
			{
				temp = 1;
				output << getday << endl;
				while(getline(input, line)&&isInteger(line)!=1){
					output << line << endl;
				}
			}
		}
	}

	if (temp == 0)
	{
		output << "NOT FOUND" << endl;
	}
}

bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}