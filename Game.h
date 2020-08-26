#pragma once
#include "Rooms.h"

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

// a class where we drag the things we need in a game cpp file
class Game
{
public:
	void GameLoop();

private:

	void MainMenu();
	void Playing();
	void RoomLoop();
	void Room1();
	void Room2();
	void Room3();
	void RoomExit();
	float RandomNum(int num1, int num2);

	bool isGameStarted;
	bool isInput;
	bool isRoomLooped;
	bool isKeyFound;
	bool isExited;

	int scenes;
	int key;
	std::string input;

	Rooms room;
};

