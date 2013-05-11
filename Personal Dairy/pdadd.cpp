#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "diary.h"
#include <stdio.h>

using namespace std;

int main()
{
	long date;
	ifstream ainput("add.txt");
	ifstream getdate("add.txt");
	Diary diary;
	diary.getdate(getdate);
	getdate.close();
	// get date in add.txt to remove form diary.txt
	ifstream datetoremove("getdate.txt");
	while(datetoremove >> date)
	{
		ifstream removeduplicate("diary.txt");
		cout << "duplicate date found " << date << endl;
		diary.remove(date, removeduplicate);
		rename("diarytemp.txt", "diary.txt");
		removeduplicate.close();
	}
	remove("getdate.txt");
	ifstream input("diary.txt");
	diary.add(input);
	diary.add(ainput);
	remove("diary.txt");
	remove("add.txt");
	rename("diarytemp.txt", "diary.txt");
	return 0;
}