#pragma once

//#include "M.h"

// ���� ����
class M;

class P
{
public:

	void KillMonster();

	/*void KillMonster2()
	{
		_target2->_hp = 0;
	}*/
public:
	int _hp;
	int _attack;

	//M _target;
	M* _target2;
};
