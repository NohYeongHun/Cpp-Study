#include "Player.h"
#include <iostream>

using std::cout;
using std::endl;

void Player::PrintInfo()
{
	cout << "--------------------------" << endl;
	cout << "[�÷��̾� ����]" << " HP : " << _hp << " ATT : " << _attack << " DEF : " << _defence << endl;
	cout << "--------------------------" << endl;
}