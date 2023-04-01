#include "Monster.h"
#include <iostream>

using std::cout;
using std::endl;

void Monster::PrintInfo()
{
	cout << "--------------------------" << endl;
	cout << "[몬스터 정보]" << " HP : " << _hp << " ATT : " << _attack << " DEF : " << _defence << endl;
	cout << "--------------------------" << endl;

}