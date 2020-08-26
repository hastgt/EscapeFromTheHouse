#include "Game.h"
//this code is very hardcoded one
//I'm not proud of what I've done here, but that's what I could make with a big lack of cpp knowledge
//I tried my best!

using namespace std;

void Game::GameLoop()
{
	isGameStarted = true; // we need to reset our booleans on every start to have a game loop
	isInput = false;
	isExited = false;
	isRoomLooped = false;
	isKeyFound = false;
	scenes = 0; // I didn't understand how you used Util.h to go through levels, so I made my junior thing to pass throught "level"

	while (isExited == false)
	{
		switch (scenes)
		{
		case 0:
			MainMenu();
			break;
		case 1:
			Playing();
			break;
		default:
			isExited = true; // once you pressed S in MainMenu() the scenes is gonna be = 3 which default switch case, the same way it works for other cases
			break;
		}
	}
	cout << "\n///You will never escape this room///" << endl;
}

void Game::MainMenu()
{
	cout << "\n///Press W To Start The Game///" << endl;
	cout << "\n///Press S To Exit///\n" << endl;

	do
	{
		cin >> input; // input from player
		if (input != "W" && input != "S")
		{
			cout << "\n///THERE IS NO SUCH A DECISION, MORTAL///\n" << endl;
		}
		else if (input == "W")
		{
			scenes = 1;
			break;
		}
		else if (input == "S")
		{
			scenes = 3;
			break;
		}

	} while (input != "W" || input != "S"); // this loop is endless until player presses W or S
}

void Game::Playing()
{
	key = RandomNum(1, 3); // here we "place" a key into one of 3 rooms

	cout << "\n///You woke up in a room you don't know///\n";
	cout << "///The incomprehensible sounds are coming from outside///\n";
	cout << "///You understand that you need to get out of here///\n";
	cout << "///You got up from the bed and openned the door///\n";
	cout << "///In the end of corridor you see the exit, but it's locked///\n";
	cout << "///You need to find a key otherwise something bad will happen///\n" << endl;
	cout << "///Press A to go left, W to go forward, D to go right///\n";
	cout << "///Press S to go to room where u woke up///\n" << endl;

	RoomLoop(); // we are going to hell
}

void Game::RoomLoop()
{
	if (isRoomLooped) // once this text was showed it won't show never again (unless you play another loop)
	{
		cout << "\n///You went back to corridor///\n" << endl;
		cout << "///Press A to go left, W to go forward, D to go right or S to go your room///\n" << endl;
	}

	isRoomLooped = true;

	Rooms rooms;

	while (!isInput) // in this loop we are going throught Rooms
	{
		cin >> input;

		if (input == "A")
		{
			rooms = Rooms::Room1; // this is gonna take one of cases in our switch loop (currently, it's a Room1 case)
			isInput = true; // we need this bool to leave the loop
		}
		else if (input == "D")
		{
			rooms = Rooms::Room2;
			isInput = true;
		}
		else if (input == "S")
		{
			rooms = Rooms::Room3;
			isInput = true;
		}
		else if (input == "W")
		{
			rooms = Rooms::Exit;
			isInput = true;
		}
		else
		{
			cout << "\nThere is no sucha direction, mortal\n" << endl;
		}
	}

	switch (rooms) // in while loop we were deciding which case we want to choose, once we choosed, we're gonna go throught here
	{
	case Rooms::Room1: // if A was pressed then we are gonna have this case which calls Room1(); function
		Room1();
		break;
	case Rooms::Room2:
		Room2();
		break;
	case Rooms::Room3:
		Room3();
		break;
	case Rooms::Exit:
		RoomExit();
		break;
	}
}

void Game::Room1()
{
	isInput = false; //reset the value to have a while loop in RoomLoop();
	bool isBackKeyPressed = false;

	cout << "\n///You entered the first room///\n";
	cout << "///You see the corpse///\n";
	cout << "///A lot of flies///\n";
	cout << "///Terrible stench all over the room///\n";

	cout << "\n///Press E to search this room///\n";
	cout << "\n///Press S to get back///\n" << endl;

	do
	{
		cin >> input;
		if (input == "S")
		{
			isBackKeyPressed = true;
			RoomLoop();
		}
		else if (input == "E")
		{
			if (key == 1) //in line code of 63 we decided where is gonna be our key, here we check if this key is here or not
			{
				cout << "\n///Great! You found the key! Now go to Exit!///\n" << endl;
				isKeyFound = true; // once we found a key we set this bool to true so we can actually win the game
			}
			else
			{
				cout << "\n///Nothing interesting here///\n" << endl; // if didn't find anything then we are gonna tell it to the player
			}
		}
		else
		{
			cout << "\n///There is no sucha a option///\n" << endl;
		}

	} while (isBackKeyPressed == false);

}

void Game::Room2()
{
	isInput = false;
	bool isBackKeyPressed = false;

	cout << "\n///You entered the second room///\n";
	cout << "///It's dark as an abyss here///\n";
	cout << "///I can barely see my hands///\n";
	cout << "///Something squeaks very hard///\n" << endl;

	cout << "\n///Press E to search this room///\n";
	cout << "\n///Press S to get back///\n" << endl;

	do
	{
		cin >> input;
		if (input == "S")
		{
			isBackKeyPressed = true;
			RoomLoop();
		}
		else if (input == "E")
		{
			if (key == 2)  //in line code of 63 we decided where is gonna be our key, here we check if this key is here or not
			{
				cout << "\n///Great! You found the key! Now go to Exit!///\n" << endl;
				isKeyFound = true; // once we found a key we set this bool to true so we can actually win the game
			}
			else
			{
				cout << "\n///Nothing interesting here///\n" << endl; // if didn't find anything then we are gonna tell it to the player
			}
		}
		else
		{
			cout << "\n///There is no sucha a option///\n" << endl;
		}

	} while (isBackKeyPressed == false);
}

void Game::Room3()
{
	isInput = false;
	bool isBackKeyPressed = false;

	cout << "\n///This is the room where you woke up///\n";
	cout << "///It smells really bad here///\n" << endl;

	cout << "\n///Press E to search this room///\n";
	cout << "\n///Press S to get back///\n" << endl;

	do
	{
		cin >> input;
		if (input == "S")
		{
			isBackKeyPressed = true;
			RoomLoop();
		}
		else if (input == "E")
		{
			if (key == 3) //in line code of 63 we decided where is gonna be our key, here we check if this key is here or not
			{
				cout << "\n///Great! You found the key! Now go to Exit!///\n" << endl;
				isKeyFound = true; // once we found a key we set this bool to true so we can actually win the game
			}
			else
			{
				cout << "\n///Nothing interesting here///\n" << endl; // if didn't find anything then we are gonna tell it to the player
			}
		}
		else
		{
			cout << "\n///There is no sucha a option///\n" << endl;
		}

	} while (isBackKeyPressed == false);
}

void Game::RoomExit()
{
	isInput = false;
	bool isBackKeyPressed = false;

	cout << "\n///This is the exist door!///\n";
	cout << "\n///Press to E to opean the door, S to get back///\n" << endl;

	do
	{
		cin >> input;
		if (input == "S")
		{
			isBackKeyPressed = true;
			RoomLoop();
		}
		else if (input == "E")
		{
			if (!isKeyFound) // if key wasn't found then we can't open the door
			{
				cout << "\n///Damn it! I can't open the door, still have to find that key!///\n" << endl;
				cout << "///Press S to get back\n" << endl;
			}
			else // if key was found we win the game and play it again or exit 
			{
				cout << "\n///You escaped from this cruel house!///\n" << endl;
				GameLoop();
			}
		}
		else
		{
			cout << "\n///There is no sucha a option///\n" << endl;
		}

	} while (!isBackKeyPressed);
}

float Game::RandomNum(int num1, int num2) // this is where magic happens, here we are generating random number between two ints
{
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random mean between num1 and num2
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(num1, num2);
	int mean = uniform_dist(e1);
	return mean;
}

