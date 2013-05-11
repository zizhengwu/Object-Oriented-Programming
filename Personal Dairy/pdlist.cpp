#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "diary.h"
#include <stdio.h>

using namespace std;

int main()
{
	long startdate;
	long enddate;
	ifstream ainput("pdlist.txt");
	if(ainput.peek())
	{
		cout << "All entities listed" << endl;
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