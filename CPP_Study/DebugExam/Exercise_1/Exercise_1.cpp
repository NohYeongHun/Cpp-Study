#include <iostream>
using namespace std;
#include "Knight.h"


// [사양서]
// 기사는 생명력(hp), 공격력(attack)을 갖고 있으며
// 기본값은 Hp = 100, Attack = 10입니다.
// 원활한 게임 진행을 위해 기사를 2개 생성하고,
// 1번 기사는 기본값으로,
// 2번 기사는 Hp를 200으로 올려서 설정합니다.

// [Bug Report #1]
// 2번 기사의 정보가 사양서와 일치하지 않습니다.
// 2번 기사의 공격력이 엉뚱한 값(음수)로 되어 있습니다.
// - 공격력이 음수로 설정된 원인을 찾아주세요
// - 2번 기사의 공격력이 기본값(10)으로 설정되길 희망합니다.

/*
	음수로 설정된 원인
	Knight의 기본 생성자에서는 _hp = 100, _attack = 10 으로 초기화를 수행한다.
	Knight(int hp) 생성자에서는 _hp 값만 인자값 int hp 값으로 설정하고
	_attack에 대해서는 초기화를 하지 않는다.
	그래서 _attack에는 초기화되지 않은 메모리의 쓰레기 값이 들어가 있기 때문에
	엉뚱한 값이 나온다.


*/
int main()
{
	Knight* k1 = new Knight();
	k1->PrintInfo();
	
	Knight* k2 = new Knight(200);
	k2->PrintInfo();

	delete k1;
	delete k2;
}
