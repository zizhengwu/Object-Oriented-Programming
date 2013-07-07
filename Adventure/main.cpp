#include "map.h"
#include "room.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	int level = 1;
	srand(time(NULL));
	cout << "The game will print map every time the map is generated." << endl;
	cout << "3 stands for lobby which is also the birthplace" << endl;
	cout << "2 stands for monster" << endl;
	cout << "1 stands for princess" << endl;
	cout << "Good luck and have a good time!" << endl;
	while(1)
	{
		level ++;
		cout << "===================" << endl;
		cout << "Level " << level << endl;
		Map game(level, level);
		game.setMap();
		game.printMap();
		game.playGame();
	}
}