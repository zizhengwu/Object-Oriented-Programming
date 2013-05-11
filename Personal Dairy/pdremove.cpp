#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "diary.h"
#include <stdio.h>

using namespace std;

int main()
{
	long day;
	ifstream input("diary.txt");
	ifstream ainput("remove.txt");
	Diary diary;
	ainput >> day;
	diary.remove(day, input);
	remove("diary.txt");
	rename("diarytemp.txt", "diary.txt");
	return 0;
}