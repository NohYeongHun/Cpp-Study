#pragma once

// ���� ����
class Player;

// is - a ������ �÷��̾��? ( X )
// has - a ������ �÷��̾ ������ �ֳ�? ( O )
class Game
{
public:
	Game();
	~Game();

private:

	// [4 ~ 8]  ----- >> [       ]
	Player* _player;
};

