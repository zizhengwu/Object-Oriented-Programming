#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "stl.h"
using namespace std;

int main()
{
	Stl hack;
	ifstream input("input.txt");
	hack.getinput(input);
	hack.analyse();
	hack.optimizestudent();
	hack.printstudent();
	hack.printcourse();
	return 0;
}