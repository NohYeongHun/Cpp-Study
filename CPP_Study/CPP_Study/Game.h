#pragma once
// ���� ����
class Player;
class Field;


// is - a ������ �÷��̾��? ( X )
// has - a ������ �÷��̾ ������ �ֳ�? ( O )
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void CreatePlayer();
	

private:

	// [4 ~ 8]  ----- >> [       ]
	Player* _player;
	Field* _field;
};

