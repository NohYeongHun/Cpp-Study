#include <iostream>
#include <bitset>
using namespace std;

// 오늘의 주제 : 데이터 연산
// 데이터를 가공하는 방법에 대해서 알아봅시다

unsigned char flag; // 부호를 없애야 >> 를 하더라도 부호비트가 딸려오지 않음.

int main()
{

// visual Studio 편집기
#pragma region 비트 연산
	// 언제 필요한가?
	// 비트 단위의 조작이 필요할 때
	// - 대표적으로 BitFlag

	// - bitwise not
	// 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로 뒤바뀜
	

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로, and를 한다.

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로, or을 한다.
	
	// ^ bitwise xor
	// 두 숫자의 모든 비트 쌍을 대상으로, xor을 한다.

	// << 비트 좌측 이동
	// 비트열을 N만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0
	// *2를 할 때 자주 보이는 패턴

	// >> 비트 우측 이동
	// 비트열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림.
	// 왼쪽 생성되는 N개의 비트는 
	// - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
	// - 아니면 0
	
	// 실습
	// 0b0000 [무적][변이][스턴][공중부양]

	// 무적 상태로 만든다
	flag = (1 << 3);
	// 변이 상태를 추가한다.(무적 + 변이).
	flag |= (1 << 2);

	// 스턴 상태를 추가한다.(무적 + 변이 + 스턴).
	// flag |= (1 << 1);
	 
	

	// 무적인지 확인하고 싶다? (다른상태는 관심 없음)
	// bitmask
	bool invincible = (flag & (1 << 3)) != 0; // flag & (1 << 3) => 1000 != 0 => 0이 아니므로 true

	unsigned int mask = (1 << 3) | (1 << 1);
	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool stunOrInvincible = ((flag & 0b1010) != 0);

	unsigned int x = (1 << 3) | (1 << 2);
	cout << bitset<4>(x) << endl;
	bool isBool = ((x & mask) != 0);
	cout << isBool << endl;



#pragma endregion

}
