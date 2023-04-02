#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #6]
// 반격 시스템이 도입되어,
// 기사는 자신을 공격한 대상을 똑같이 공격합니다.
// 기사 2을 생성해서 위 사양을 테스트하는데...
// 바로 크래시가 나고 있습니다.
// 또 뭐가 문제인지 원인을 찾아주세요!

/*
	OnDamaged(Knight* attacker)
	함수가 실행되면
	1. 현재 공격할 기사2의 주소를 전달한다.
	2. 해당 기사가 nullptr인지 확인
	3. 아니라면 해당 기사의 공격력을 가져온다.
	4. nullptr일때는 해당 함수를 탈출 할 수 있다.
	5. 하지만 공격과 데미지를 받는 조건만 있지 탈출 조건은 없다.
	6. 고로 탈출 조건을 추가해줘야 한다.
	7. 이 함수는 attacker와 내 주소가 인자값으로 무한히 반복되서
	함수에 대한 스택메모리가 넘치는 현상인 StackOverflow가 발생한다.

*/

int main()
{
	Knight* k1 = new Knight();
	k1->_hp = 100;
	k1->_maxHp = 100;
	k1->_attack = 100;

	Knight* k2 = new Knight();
	k2->_hp = 100;
	k2->_maxHp = 100;
	k2->_attack = 100;

	k1->OnDamaged(k2);

	delete k1;
	delete k2;
}
