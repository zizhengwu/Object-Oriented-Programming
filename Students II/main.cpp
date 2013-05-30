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
	return 0;
}