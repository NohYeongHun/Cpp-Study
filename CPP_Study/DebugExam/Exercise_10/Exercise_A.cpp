#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"
#include "Arrow.h"

// [Bug Report #10]
// 궁수라며면 자고로 화살을 쏴야겠죠.
// Arrow는 자신을 목표 대상물을 target으로 관리하고
// Arrow를 만들 때 설정한 데미지 만큼 target의 체력을 깎습니다.
// 테스트를 위해 화살 10개를 생성해서 기사를 피격했는데...
// C++이 늘 그렇지만 되는 일이 없고 또 크래시가 납니다.
// 뭐가 문제일까요?

/*
	1. knight가 isDead()시 kngiht 메모리가 해제된다.
	2. 그리고 knight 인스턴스를 가리키는 포인터는 nullptr로 변환된다.
	3. 하지만 Arrow안에 들어있는 target(knight 인스턴스를 가리켰던 포인터)은 변하지 않는다.
	4. 이미 소멸된 객체를 가리켜서 작업을 수행하려하자 에러가 발생한다.
	5. Arrow 투사체는 들고 있는 메모리가 유효한지 모름!
	6. 왜 PrintInfo에서 에러가 발생할까?
	=> PrintInfo는 가상함수다.
	=> 해당 함수는 원본객체의 가상함수 테이블에 들어가 있다.
	=> AddHp는 엉뚱한 메모리를 고치기 때문에 crash가 발생하지않음
	=> PrintInfo함수가 실행될때 참조할 가상함수 테이블
	=> 소멸처리 된 메모리
	0x0087C910  dddddddd  ????
	0x0087C914  dddddddd  ????
	0x0087C918  dddddddd  ????
	0x0087C91C  dddddddd  ????
	0x0087C920  dddddddd  ????

*/

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Archer* archer = new Archer(new Pet());
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;

	Knight* knight = new Knight();	
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 10;
	
	Arrow* arrows[10] = {};
	for (int i = 0; i < 10; i++)
	{
		// 기사를 타겟으로, 궁수의 공격력을 지닌 상태
		Arrow* arrow = new Arrow(knight, archer->_attack);
		arrows[i] = arrow;
	}

	for (int i = 0; i < 10; i++)
	{
		arrows[i]->AttackTarget();

		// 기사가 죽었으면 소멸시켜준다
		// 소멸처리 부분 삭제!.
		delete arrows[i];
		arrows[i] = nullptr;
	}
}
