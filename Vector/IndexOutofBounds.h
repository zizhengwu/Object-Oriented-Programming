#ifndef INDEXOUTOFBOUNDS_H_
#define INDEXOUTOFBOUNDS_H_ value
#include <string>
using namespace std;

class IndexOutofBounds
{
public:
	inline IndexOutofBounds(string s){
		war = s;
	};
	~IndexOutofBounds() {};
	inline string hey() {return war;}
private:
	string war;
};

#endif