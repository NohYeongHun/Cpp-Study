#include<iostream>
using namespace std;
#include"Game.h"

// UPGrade TEXTRPG
int main()
{
	srand((unsigned int) time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}
}