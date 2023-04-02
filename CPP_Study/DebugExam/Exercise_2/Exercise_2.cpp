#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #2]
// Bug Report #1이 잘 해결 되었는지 확인하기 위해
// 기사 10명 생성해서 정보를 출력하고자 합니다.
// 그런데 정보를 출력하다 프로그램이 뻗는 문제가 발생하고 있습니다.
// 크래시 원인을 분석하고 알맞게 고쳐주세요!

/*
	1. KNIGHT_COUNT의 크기는 10이다.
	2. Knight* 타입 knights배열은 크기가 10으로 초기화된다.
	3. 통상적으로 배열은 마지막 인덱스는 사용할 수 없다.
	4. 2번째 for문에서는 10번째 인덱스에 접근하려고 해서 에러가 발생한다.
	5. 2번째 for문의 <= 기호를 < 로 바꾸면 정상적으로 동작한다.
*/

const int KNIGHT_COUNT = 10;

int main()
{
	Knight* knights[KNIGHT_COUNT];

	for (int i = 0; i < KNIGHT_COUNT; i++)
	{
		knights[i] = new Knight();
	}

	for (int i = 0; i < KNIGHT_COUNT; i++)
	{
		knights[i]->PrintInfo();
		delete knights[i];
	}
}
