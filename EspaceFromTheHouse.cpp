#include "Game.h"

int main()
{
	Game* game = new Game(); // creating a game pointer which game.cpp
	game->GameLoop(); // we call gameloop function from game cpp 

	delete game; // we need delete pointers before existing the programm otherwise we are gonna get memory leak

	return EXIT_SUCCESS;
}
