#include <iostream>
#include "fraction.h"
#include "convert.h"
using namespace std;


Fraction::Fraction(int whole_number){
	num = whole_number;
	den = 1;
}

Fraction::Fraction(int numerator, int denominator){
	num = numerator;
	den = denominator;
}

ostream& operator << (ostream& os, Fraction& fraction){
	os << fraction.GetNumerator();
	os << "/";
	os << fraction.GetDenominator();
	return os;
}

istream& operator >> (istream& is, Fraction& fraction){
	int numerator;
	int denominator;
	string line;
	string delimiter = "/";
	getline(is, line);
	numerator = convertToInt(line.substr(0, line.find(delimiter)));
	line.erase(0, line.find(delimiter) + delimiter.length());
	denominator = convertToInt(line.substr(0, line.find(delimiter)));
	fraction.SetDenominator(denominator);
	fraction.SetNumerator(numerator);	
	return is;
}