﻿#include <iostream>
using namespace std;

// a [ 1 ]
// a라는 이름의 바구니를 할당하고 안에 1을 넣는다.
int a = 1;

// b [ 2 ]
// b라는 이름의 바구니를 할당하고 안에 2를 넣는다.
int b = 1;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isinvincible = true;

int main()
{

// visual Studio 편집기
#pragma region 비교 연산
	
	// 언제 필요한가?
	// ex) 체력이 0이 되면 사망
	// ex) 체력이 30% 이하이면 궁극기를 발동 ( 100 * hp / maxHp)
	// ex) 경험치가 100 이상이면 레벨업

	// a == b : a와 b의 값이 같은가?
	// 같으면 1, 다르면 0
	isSame = (a == b);

	// a != b : a와 b의 값이 다른가?
	isDifferent = (a != b);

	// a > b : a가 b보다 큰가?
	// a >= b : a가 b보다 크거나 같은가?
	// 1 아니면 0
	isGreater = (a > b);

	// a < b : a가 b보다 작은가?
	// a <= b : a가 b보다 작거나 같은가?
	// 1 아니면 0
	isSmaller = (a < b);


#pragma endregion

#pragma region 논리 연산
	// 언제 필요한가? 조건에 대한 논리적 사고가 필요할 때
	// ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다.
	// ex) 길드 마스터이거나 OR 운영자 계정이면 길드 해산 가능.

	// ! not
	// 0이면 1, 그 외 0
	test = !isSame; // 사실상 isDifferent의 의미

	// && AND
	// a && b -> 둘다 1이면 1, 그 외 0
	test = (hp <= 0 && isinvincible == false); // 죽음

	// || or 
	// a || b - > 둘중 하나라도 1이라면 1, 아니면 0
	test = (hp > 0 || isinvincible == true); // 살았음


#pragma endregion
}
