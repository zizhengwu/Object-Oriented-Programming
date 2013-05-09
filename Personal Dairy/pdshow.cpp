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
	ifstream ainput("pdshow.txt");
	ainput >> day;
	Diary diary;
	diary.show(day,input);
	return 0;
}