#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "stl.h"

using namespace std;

void Stl::getinput (ifstream & input)
{
	string line;
	string buf;
	while(getline(input, line)){
		stringstream ss(line);
		student.push_back(const value_type &__x)
	}
}


// string str("Split me by whitespaces");
// string buf; // Have a buffer string
// stringstream ss(str); // Insert the string into a stream

// vector<string> tokens; // Create vector to hold our words

// while (ss >> buf)
//     tokens.push_back(buf);