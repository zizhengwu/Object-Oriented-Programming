#include "room.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

void Map::setMap()
{
	int generateRandom (int i);
	room.resize(row);
	for (int i = 0; i < row; ++i)
	{
		room[i].resize(column);
	}

	for (int i = 0; i < row; ++i)
	{
		for (int i1 = 0; i1 < column; ++i1)
		{
			room[i][i1].setX(i);
			room[i][i1].setY(i1);
		}
	}
// set princess
	while (1)
	{
		int temp1, temp2;
		temp1 = generateRandom(row);
		temp2 = generateRandom(column);
		if (room[temp1][temp2].getType() == 0)
		{
			room[temp1][temp2].setType(1);
			break;
		}
	}
// set monster
	while (1)
	{
		int temp1, temp2;
		temp1 = generateRandom(row);
		temp2 = generateRandom(column);
		if (room[temp1][temp2].getType() == 0)
		{
			room[temp1][temp2].setType(2);
			break;
		}
	}
// set lobby
	while (1)
	{
		int temp1, temp2;
		temp1 = generateRandom(row);
		temp2 = generateRandom(column);
		if (room[temp1][temp2].getType() == 0)
		{
			room[temp1][temp2].setType(3);
			y = temp1;
			x = temp2;
			break;
		}
	}
}

void Map::printMap()
{
	for (int i = 0; i < row; ++i)
	{
		for (int i1 = 0; i1 < column; ++i1)
		{
			cout << room[i][i1].getType() << " ";
		}
		cout << endl;
	}
}

void Map::playGame()
{
	int type;
	Player player(x, y, row, column);
	int offsetx, offsety;
	string go, command;
	cout << "GAME START" << endl;
	while(1)
	{
		type = room[player.getY()][player.getX()].getType();
		if (type == 0)
		{
			cout << "You enter a common room, nothing happened. " << endl;
		}
		if (type == 1)
		{
			if (player.getprincess() == 1)
			{
				cout << "You are already with the princess, find the lobby! " << endl;
			}
			else
			{
				player.setPrincess();
				player.showWelcome(1);
			}
		}
		if (type == 2)
		{
			player.showWelcome(2);
			break;
		}
		if (type == 3)
		{
			if (player.getprincess() == 0)
			{
				player.showWelcome(3);
				cout << "Find the princess and save her! " << endl;
			}
			else
			{
				player.showWelcome(3);
				cout << "CONGRATULATIONS! YOU SAVE THE PRINCESS!" << endl;
				break;
			}
		}
		player.checkDirection();
		cout << "Enter your command: " << endl;
		while(1)
		{
			cin >> go >> command;
			if (command == "left")
			{
				offsetx = -1;
				offsety = 0;
			}
			if (command == "right")
			{
				offsetx = 1;
				offsety = 0;
			}
			if (command == "up")
			{
				offsetx = 0;
				offsety = -1;
			}
			if (command == "down")
			{
				offsetx = 0;
				offsety = 1;
			}
			if (player.move(offsetx, offsety) == 1)
				break;
			else
			{
				cout << "Invalid input!" << endl;
				cout << "Enter your command: " << endl;
			}
		}

	}
}

int generateRandom (int i)
{
	return rand() % i;
}

