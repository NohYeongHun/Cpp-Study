#include <iostream>
using namespace std;

// 오늘의 주제 : 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

unsigned char flag; // 부호를 없애야 >> 를 하더라도 부호비트가 딸려오지 않음.


// 전역변수

// [데이터 영역]
// .data (초기값 있는 경우)
int a = 2;

// .bss (초기값 없는 경우)
int b;

// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함.
// 상수는 대부분 대문자로 작성하는 코딩 컨벤션이 있음.
// const도 바뀌지 않는 읽기전용
// .rodata?
// C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 (VS) 마음
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;


int main()
{
	// [스택 영역]
	int c = 3;
	int v = 4;


#pragma region 비트연산
	// 실습
	// 0b0000 [무적][변이][스턴][공중부양]

	// 무적 상태로 만든다.
	flag = (1 << INVINCIBLE);

	// 변이 상태를 추가한다 (무적 + 변이)
	flag |= (1 << POLYMORPH);

	// 무적인지 확인하고 싶다? (다른 상태는 관심 없음)
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴상태인지 확인하고 싶다면?
	bool stunOrInvincible = ((flag & 0b1010) != 0);

#pragma endregion
}
