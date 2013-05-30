#ifndef FRACTION_H_
#define FRACTION_H_ value
#include <iostream>
using namespace std;
class Fraction
{
public:
	int num;
	int den;
public:
	Fraction(void):num(0), den(0){};
	Fraction(int whole_number);
	Fraction(int numerator, int denominator);
	~Fraction(void){};
	inline int GetNumerator(){return num;}
	inline int GetDenominator(){return den;}
};

ostream& operator << (ostream& os, Fraction& fraction);
istream& operator >> (istream& is, Fraction& fraction);
#endif