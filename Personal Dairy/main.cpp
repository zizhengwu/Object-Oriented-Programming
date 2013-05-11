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
	long mode;
	string line;
	int analysis(string & thisline);
	remove("result.txt");
	ifstream input("INSTRUCTIONS.txt");
	ofstream output("temp.txt");
	while(getline(input, line)){
		if (analysis(line)==1)
		{
			break;
		}
	}
	mode = convertToLong(line);
	cout << "WHAT YOU ENTERED:" << endl;
	while(getline(input, line)){
		cout << line <<endl;
		output << line << endl;
	}
	remove("result.txt");
	switch(mode)
	{
		case 1:
			rename("temp.txt", "add.txt");
			system("./pdadd");
			remove("add.txt");
			cout << "Function PDADD DONE" << endl;
			cout << "New entity added, see what's new in diary.txt :)" << endl;
			break;
		case 2:
			rename("temp.txt", "remove.txt");
			system("./pdremove");
			remove("remove.txt");
			cout << "Function PDREMOVE DONE" << endl;
			cout << "Specific entity removed, see what's new in diary.txt :)" << endl;
			break;
		case 3:
			rename("temp.txt", "pdshow.txt");
			system("./pdshow");
			remove("pdshow.txt");
			rename("show.txt", "result.txt");
			cout << "Function PDSHOW DONE" << endl;
			cout << "Specific entity showed in result.txt" << endl;
			break;
		case 4:
			rename("temp.txt", "pdlist.txt");
			system("./pdlist");
			remove("pdlist.txt");
			rename("show.txt", "result.txt");
			cout << "Function PDLIST DONE" << endl;
			cout << "Listed in result.txt" << endl;
			break;
	}
	return 0;
}


int analysis(string & thisline)
{
	char firstletter;
	firstletter = thisline[0];
	if (firstletter == '*')
	{
		return 0;
	}
	return 1;
}
