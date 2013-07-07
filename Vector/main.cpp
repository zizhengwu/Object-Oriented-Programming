#include <iostream>
#include "Vector.h"
#include "IndexOutofBounds.h"
int main()
{
	Vector <int> a;
	Vector <double> b (10);

	try{
		cout << b[20];
	}catch (IndexOutofBounds &t){
		cout << t.hey();
		cout << endl;
	}

	b[8] = 9.0;
	b.inflate(10);
	
	try{
		cout << b[8] << endl;
		cout << b[15] << endl;
	}catch (IndexOutofBounds &t){
		cout << t.hey();
		cout << endl;
	}

}