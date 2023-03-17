#include <iostream>
using std::cout;
using std::endl;

// 오늘의 주제 : 불리언(bool)과 실수

// 불리언(boolean) 참 / 거짓
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;


// [Note]
// 사실 bool은 그냥 1바이트 정수에 불과
// 왜 정수 시간에 언급하지 않았는가?
// -> 일리 있음. 어셈블리에서 bool이라는 것은 없음
// bool만 봐도 참/거짓 둘 중 하나라는 힌트를 줌. (가독성)
// 1이면 여자 0이면 남자.

// bool < 1바이트 정수

int isFemale = 1; 
int main()
{
	cout << isHighLevel << endl;
}
