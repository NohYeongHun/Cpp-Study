#pragma once

// 전방 선언
class Player;

// is - a 게임이 플레이어냐? ( X )
// has - a 게임은 플래이어를 가지고 있냐? ( O )
class Game
{
public:
	Game();
	~Game();

private:

	// [4 ~ 8]  ----- >> [       ]
	Player* _player;
};

