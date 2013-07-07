#ifndef ROOM_H_
#define ROOM_H_ value

class Room
{
public:
	Room():type(0){};
	~Room(){};
	inline void setType(int i) {type = i;}
	inline int getType() {return type;}
	inline void setX(int i) {x = i;}
	inline void setY(int i) {y = i;}
	inline int getX() {return x;}
	inline int getY() {return y;}
private:
	int type;
	int x;
	int y;
	
};

#endif