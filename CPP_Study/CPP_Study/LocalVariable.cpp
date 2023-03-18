#include <iostream>
using namespace std;

// 오늘의 주제 : 지역변수와 값 전달

// 전역 변수
// 참고) 초기화 여부, const 등 .rodata, .data, .bss
// 메모리의 데이터 영역에 들어감.
void increaseHp(int hp)
{
	hp = hp + 1;
}

// [매개변수][RET][지역변수]
int main()
{
	int hp = 1;

	// 1
	cout << "Increase 호출 전 : " << hp << endl;
	increaseHp(hp);
	// 1
	cout << "Increase 호출 후 : " << hp << endl;

}