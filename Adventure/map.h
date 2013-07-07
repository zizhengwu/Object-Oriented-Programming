#ifndef MAP_H_
#define MAP_H_ value
#include "room.h"
#include <vector>
#include <iostream>
using namespace std;

class Map
{
public:
	Map(int a, int b):column(a), row(b){};
	~Map(){};
	void setMap();
	void printMap();
	void playGame();
private:
	vector < vector<Room> >room;
	int x;
	int y;
	int column;
	int row;
};

#endif