#ifndef PLAYER_H_
#define PLAYER_H_ value
#include "room.h"
class Player
{
public:
	Player(){};
	Player(int a, int b, int c, int d) : x(a), y(b), row(c), column(d), princess(0){};
	~Player(){};
	void checkDirection();
	void showWelcome(int i);
	inline void setX(int i) {x = i;}
	inline void setY(int i) {y = i;}
	inline int getX() {return x;}
	inline int getY() {return y;}
	inline int getprincess() {return princess;}
	int move(int offsetx, int offsety);
	inline void setPrincess() {princess = 1;}
private:
	int x, y;
	int row, column;
	int princess;
};
#endif