#include "Monster.h"
#include <iostream>

using std::cout;
using std::endl;

void Monster::PrintInfo()
{
	cout << "--------------------------" << endl;
	cout << "[���� ����]" << " HP : " << _hp << " ATT : " << _attack << " DEF : " << _defence << endl;
	cout << "--------------------------" << endl;

}