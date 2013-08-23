//Enter you code here.
//Please indent properly.

#include <iostream>

#include <Windows.h>

using namespace std;



struct Player

{

	int x, y;

	Player()

	{

		x = 4;

		y = 1;

	}

};







const char SYMBOL_EMPTY = ' ';

const char SYMBOL_PLAYER = '@';



const char SYMBOL_WALL = '#';

const char SYMBOL_PELLET ='.';

const int Xlim = 10;

const int Ylim = 29;

const int GameSpeed = 100;

const int LEFT = 1;

const int RIGHT = 2;

const int UP = 3;

const int DOWN = 4;

int direction = RIGHT;



char map[29][29] =

{

	"############################",

	"#...........####...........#",

	"#.###.#####.####.#####.###.#",

	"#.###.#####.####.#####.###.#",

	"#                          #",

	"#                          #",

	"#                          #",

	"#                          #",

	"############################"

};



bool isValidPos(int x, int y)

{

	return (x >= 0 && x < Xlim && y >= 0 && y < Ylim);

}





bool movePlayer(Player &player, int x, int y,int direction)

{



	char ch;

	if (!isValidPos(x, y))

	{

		return false;

	}



	switch (direction)

	{

	case RIGHT:

		ch=map[x + 1][y];

		break;

	case LEFT:

		ch=map[x-1][y];

		break;

	case UP:

		ch=map[x][y-1];

		break;

	case DOWN:

		ch=map[x][y+1];

		break;

	}



	if(ch != SYMBOL_WALL)

	{

		map[player.x][player.y] = SYMBOL_EMPTY;

		player.x = x; player.y = y;

		map[player.x][player.y] = SYMBOL_PLAYER;

		return true;	}



	else

		return false;





}









void showMap()

{

	for (int x = 0; x < Xlim; x  )

	{

		cout << map[x] << endl;

	}

}



void showPlayer(Player &player)

{

	cout << "\nPlayerX: " << player.x << endl;

	cout << "PlayerY: " << player.y << endl;

}



void gameLoop()

{

	Player player;



	movePlayer(player, 1, 2, direction);



	while (true)

	{

		system("cls");

		showMap();

		showPlayer(player);

		if (GetAsyncKeyState(VK_UP))

		{

			direction = UP;

		}

		else if (GetAsyncKeyState(VK_DOWN))

		{

			direction = DOWN;
		}
	}
}
