#ifndef FRACTION_H_
#define FRACTION_H_ value
#include <iostream>
using namespace std;
class Fraction
{
private:
	int num;//fenzi
	int den;//fenmu
public:
	Fraction(void):num(0), den(0){};
	Fraction(int whole_number);
	Fraction(int numerator, int denominator);
	~Fraction(void){};
	inline const Fraction operator*(Fraction&i){return Fraction(num * i.num, den * i.den);}
	inline const Fraction operator/(Fraction&i){return Fraction(num * i.den, den * i.num);}
	inline const Fraction operator+(Fraction&i){
		return Fraction(num * i.den + den * i.num, den * i.den);
	}
	inline const Fraction operator-(Fraction&i){
		return Fraction(num * i.den - den * i.num, den * i.den);
	}
	inline bool operator<(Fraction&i){
		return (num*1.0/den < i.num*1.0/i.den);
	}
	inline bool operator<=(Fraction&i){
		return (num*1.0/den <= i.num*1.0/i.den);
	}
	inline bool operator>(Fraction&i){
		return (num*1.0/den > i.num*1.0/i.den);
	}
	inline bool operator>=(Fraction&i){
		return (num*1.0/den >= i.num*1.0/i.den);
	}
	inline bool operator==(Fraction&i){
		return (num*1.0/den == i.num*1.0/i.den);
	}
	inline bool operator!=(Fraction&i){
		return (num*1.0/den != i.num*1.0/i.den);
	}
	inline int GetNumerator(){return num;}
	inline int GetDenominator(){return den;}
	inline void SetDenominator(int i){den = i;}
	inline void SetNumerator(int i){num = i;}
	void normalize();
	inline operator double(){
		return (double)num/(double)den;
	}
	inline operator string(){
		string ret, tmp;
		int tnum = num;
		int tden = den;
		int f = 0;
		if(tnum < 0)
		{
			f = 1;
			tnum = -tnum;
		}
		while(tnum)
		{
			tmp = char((tnum % 10) + 48) + tmp;
			tnum = tnum / 10;
		}
		ret = tmp + '/';
		tmp = "";
		while(tden)
		{
			tmp = char((tden % 10) + 48) + tmp;
			tden = tden / 10;
		}
		ret = ret + tmp;
		if(f)
		{
			ret = '-' + ret;
		}
		return ret;
	}
};

ostream& operator << (ostream& os, Fraction& fraction);
istream& operator >> (istream& is, Fraction& fraction);
#endif



