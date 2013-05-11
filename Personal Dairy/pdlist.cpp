#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "diary.h"
#include <stdio.h>
#include "convert.h"
using namespace std;

int main()
{
	bool is_empty(std::ifstream& pFile);
	long startdate;
	long enddate;
	long tempdate;
	Diary diary;
	string thisdate;
	vector <long> date;
	ifstream checkempty("pdlist.txt");
	ifstream ainput("pdlist.txt");
	ifstream inputdate("diary.txt");
	if(is_empty(checkempty))
	{
		cout << "All entities listed" << endl;
		diary.getdate(inputdate);
		inputdate.close();
		ifstream alldate("getdate.txt");
		while(alldate >> thisdate)
		{
			date.push_back(convertToLong(thisdate));
		}
		sort(date.begin(), date.end());
		for (int i = 0; i < date.size(); i++)
		{
			ifstream inputdate("diary.txt");
			tempdate = date[i];
			diary.show(tempdate, inputdate);
		}
		remove("getdate.txt");
	}
	else
	{
		ainput >> startdate >> enddate;
		Diary diary;
		for (long i = startdate; i <= enddate; i++)
		{
			ifstream input("diary.txt");
			diary.show(i, input);
		}
	}
	

	return 0;
}

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}