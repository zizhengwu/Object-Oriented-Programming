#include "fraction.h"
#include <iostream>
int main()
{
	Fraction frac1;
	cout << "Enter a fraction like 3/4" << endl;
	cin >> frac1;
	Fraction frac2;
	cout << "Enter a fraction like 3/4" << endl;
	cin >> frac2;
	{
		cout << "operator +" << endl;
		Fraction frac(frac1 + frac2);
		frac.normalize();
		cout << frac << endl;
	}
	{
		cout << "operator -" << endl;
		Fraction frac(frac1 - frac2);
		frac.normalize();
		cout << frac << endl;
	}
	{
		cout << "operator *" << endl;
		Fraction frac(frac1 * frac2);
		frac.normalize();
		cout << frac << endl;
	}
	{
		cout << "operator /" << endl;
		Fraction frac(frac1 / frac2);
		frac.normalize();
		cout << frac << endl;
	}
	{
		cout << "operator <" << endl;
		bool frac (frac1 < frac2);
		cout << frac << endl;
	}
	{
		cout << "operator <=" << endl;
		bool frac (frac1 <= frac2);
		cout << frac << endl;
	}
	{
		cout << "operator ==" << endl;
		bool frac (frac1 == frac2);
		cout << frac << endl;
	}
	{
		cout << "operator !=" << endl;
		bool frac (frac1 != frac2);
		cout << frac << endl;
	}
	{
		cout << "operator >=" << endl;
		bool frac (frac1 >= frac2);
		cout << frac << endl;
	}
	{
		cout << "operator >" << endl;
		bool frac (frac1 > frac2);
		cout << frac << endl;
	}
}


/*
arithmetical operators: + - * /
relational operators: < <= == != >= >
*/