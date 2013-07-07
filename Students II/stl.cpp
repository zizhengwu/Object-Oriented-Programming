#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "stl.h"

using namespace std;

void Stl::getinput (ifstream & input)
{
	int no;
	string name;
	string line;
	string coursename;
	int coursescore;
	while(getline(input, line)){
		course.clear();
		stringstream ss(line);
		ss >> no;
		ss >> name;
		while(ss >> coursename){
			ss >> coursescore;
			Course tempcourse (coursename, coursescore);
			course.push_back(tempcourse);
		}
		Student tempstudent(no, name, course);
		student.push_back(tempstudent);
	}
}

void Stl::showvector()
{
	cout << "showvector" << endl;
	for (int i = 0; i < optimizedstudent.size(); i++)
	{
		cout << optimizedstudent[i].no << optimizedstudent[i].name << endl;
		for (int i1 = 0; i1 < optimizedstudent[i].course.size(); i1++)
		{
			cout << optimizedstudent[i].course[i1].coursename << optimizedstudent[i].course[i1].coursescore;
		}
		cout << endl;
	}
}

void Stl::analyse()
{
	string someCourse;
	for (int i = 0; i < student.size(); i++)
	{
		for (int i1 = 0; i1 < student[i].course.size(); i1++)
		{
			someCourse = student[i].course[i1].coursename;
			if (find(allcourse.begin(), allcourse.end(), someCourse) == allcourse.end()) {
				allcourse.push_back(someCourse);
			}
		}
	}
	sort (allcourse.begin(), allcourse.end());
}

void Stl::optimizestudent()
{
	for (int i1 = 0; i1 < student.size(); ++i1)
	{
		course.clear();
		for (int i2 = 0; i2 < allcourse.size(); ++i2)
		{
			int tempscore = -1;
			for (int i3 = 0; i3 < student[i1].course.size(); ++i3)
			{
				if (allcourse[i2] == student[i1].course[i3].coursename)
				{
					tempscore = student[i1].course[i3].coursescore;
				}
			}
			Course tempcourse (allcourse[i2], tempscore);
			course.push_back(tempcourse);
		}
		Student tempstudent(student[i1].no, student[i1].name, course);
		optimizedstudent.push_back(tempstudent);
	}
}

void Stl::printstudent()
{
	cout.setf(ios::left);
	cout.width(8);
	cout<<"no";
	cout.width(8);
	cout<<"name";
	for (int i = 0; i < allcourse.size(); ++i)
	{
		cout.width(8);
		cout << allcourse[i];
	}
	cout.width(8);
	cout<<"average"<<endl;
	for (int i = 0; i < optimizedstudent.size(); ++i)
	{
		int count = 0;
		float sum = 0;
		cout.width(8);
		cout << optimizedstudent[i].no;
		cout.width(8);
		cout << optimizedstudent[i].name;
		for (int i1 = 0; i1 < optimizedstudent[i].course.size(); ++i1)
		{
			if (optimizedstudent[i].course[i1].coursescore != -1)
			{
				cout.width(8);
				cout << optimizedstudent[i].course[i1].coursescore;
				sum += optimizedstudent[i].course[i1].coursescore;
				count++;
			}
			else
			{
				cout.width(8);
				cout << "";
			}
		}
		cout.width(8);
		cout << sum/count;
		cout << endl;
	}
}

void Stl::printcourse()
{
	vector <float> average;
	vector <int> min;
	vector <int> max;
	for (int i = 0; i < allcourse.size(); ++i)
	{
		float sum = 0;
		float count = 0;
		int tmin = 5;
		int tmax = 0;
		for (int i1 = 0; i1 < optimizedstudent.size(); ++i1)
		{
			if (optimizedstudent[i1].course[i].coursescore != -1)
			{
				sum += optimizedstudent[i1].course[i].coursescore;
				count++;
				if (optimizedstudent[i1].course[i].coursescore < tmin)
				{
					tmin = optimizedstudent[i1].course[i].coursescore;
				}
				if (optimizedstudent[i1].course[i].coursescore > tmax)
				{
					tmax = optimizedstudent[i1].course[i].coursescore;
				}
			}
		}
		average.push_back(sum / count);
		min.push_back(tmin);
		max.push_back(tmax);
	}
	cout.width(8);
	cout << "";
	cout.width(8);
	cout << "average";
	for (int i = 0; i < allcourse.size(); ++i)
	{
		cout.width(8);
		cout << average[i];
	}
	cout << endl;
	cout.width(8);
	cout << "";
	cout.width(8);
	cout << "min";
	for (int i = 0; i < allcourse.size(); ++i)
	{
		cout.width(8);
		cout << min[i];
	}
	cout << endl;
	cout.width(8);
	cout << "";
	cout.width(8);
	cout << "max";
	for (int i = 0; i < allcourse.size(); ++i)
	{
		cout.width(8);
		cout << max[i];
	}
	cout << endl;
}