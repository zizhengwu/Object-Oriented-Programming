#include <string>
#include <iostream>
#include "player.h"

using namespace std;

void Player::checkDirection()
{
	string choice;
	int count;
	if (x != 0)
	{
		count++;
		choice += "left ";
	}
	if (x != column - 1)
	{
		count++;
		choice += "right ";
	}
	if (y != 0)
	{
		count++;
		choice += "up ";
	}
	if (y != row - 1)
	{
		count++;
		choice += "down ";
	}	
	cout << "There are " << count << " exits as: " << choice << endl;
}

void Player::showWelcome(int i)
{
	switch(i)
	{
		case 1:
		cout << "You have the princess right now! " << endl;
		break;
		case 2:
		cout << "You meet the monster, GAME OVER! " << endl;
		break;
		case 3:
		cout << "Welcome to lobby. ";
		break;
	}
}

int Player::move(int offsetx, int offsety)
{
	if (x + offsetx < 0 || x + offsetx >= column || y + offsety < 0 || y + offsety >= row)
	{
		return 0;
	}
	else
	{
		x += offsetx;
		y += offsety;
		return 1;
	}
}