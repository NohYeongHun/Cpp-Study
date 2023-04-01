#include "P.h"
#include "M.h"

void P::KillMonster()
{
	/*
		문법을 풀어써보자!
		(*_target2)._hp = 0;

		[ 주소 ] -> [ 주소 어딘가~~ _hp ]
		_hp가 시작 주소의 어디에 있는지는 어떻게 확인하는가?
		M의 설계도를 참고해야한다!.
		[ 주소 ] -> [ [monsterId] [hp] [defence] ]
		
	*/
	// _target2->_hp = 0;

	/*
		KillMe()를 호출하기위해서는?
		어떤 형태로 만들어 있는지 알아야 호출 가능!
		- 어떤 반환형태인가?
		- 어떤 인자값이 필요한가?
		무슨 형태로 동작하는지까지는 몰라도 상관 없음! => 접근해서 실행할 것이므로
	*/
	_target2->KillMe();
}