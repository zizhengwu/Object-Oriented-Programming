#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "diary.h"
#include <stdio.h>

using namespace std;

int main()
{

	ifstream input("diary.txt");
	ifstream ainput("add.txt");
	Diary diary;
	diary.add(input, ainput);
	return 0;
}