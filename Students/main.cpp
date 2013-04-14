#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "student.h"
using namespace std;

int main()
{
	int number;
	string name;
	int score1;
	int score2;
	int score3;
	int min[4];
	int max[4];
	float caverage[4];
	float saverage;

	ifstream cin("student.in");
	ofstream cout("student.out");


	cout.setf(ios::left);

	Student S[10];
	for (int i = 0; i < 4; ++i)
	{
		min[i] = 5;
		max[i] = 0;
		caverage [i] = 0;
	}
	// read
	for (int i = 0; i < 10; ++i)
	{
		cin>>name>>score1>>score2>>score3;
		S[i].Initial(name, score1, score2, score3);
	}
	
	// printhead
	cout.width(8);
	cout<<"no";
	cout.width(8);
	cout<<"name";
	cout.width(8);
	cout<<"score1";
	cout.width(8);
	cout<<"score2";
	cout.width(8);
	cout<<"score3";
	cout.width(8);
	cout<<"average"<<endl;

	
	// printscore for each student
	for (int i = 0; i < 10; ++i)
	{
		cout.width(8);
		cout<<i+1;
		cout.width(8);
		name = S[i].GetName();
		cout<<name;
		cout.width(8);
		score1 = S[i].GetScore1();
		cout<<score1;
		cout.width(8);
		score2 = S[i].GetScore2();
		cout<<score2;
		cout.width(8);
		score3 = S[i].GetScore3();
		cout<<score3;
		cout.width(8);
		saverage = (score1 + score2 + score3) / 3.0;
		cout<<saverage;
		cout<<'\n';
		if (score1 > max[1])
		{
			max [1] = score1;
		}
		if (score1 < min[1])
		{
			min [1] = score1;
		}
		caverage[1] += score1;


		if (score2 > max[2])
		{
			max [2] = score2;
		}
		if (score2 < min[2])
		{
			min [2] = score2;
		}
		caverage[2] += score2;


		if (score3 > max[3])
		{
			max [3] = score3;
		}
		if (score3 < min[3])
		{
			min [3] = score3;
		}
		caverage[3] += score3;
	}



	// print the rest
	cout.width(8);
	cout<<' ';
	cout.width(8);
	cout<<"average";
	for (int i = 0; i < 3; ++i)
	{
	cout.width(8);
	cout<<(caverage[i+1]) / 10;
	}
	cout<<'\n';
	cout.width(8);
	cout<<' ';
	cout.width(8);
	cout<<"min";
	for (int i = 0; i < 3; ++i)
	{
	cout.width(8);
	cout<<min[i+1];
	}
	cout<<'\n';
	cout.width(8);
	cout<<' ';
	cout.width(8);
	cout<<"max";
	for (int i = 0; i < 3; ++i)
	{
	cout.width(8);
	cout<<max[i+1];
	}
	cout<<'\n';
	return 0;
}
