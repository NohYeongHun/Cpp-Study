#include <iostream>
using namespace std;

// 오늘의 주제 : 반복문
// 데이터를 메모리에 할당하고 가공하는 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?


int main()
{
	int round = 1;
	int hp = 100;
	int damage = 20;

	// 무한 루프 : 전투 시작
	while (true)
	{
		hp -= damage;
		if (hp < 0) 
		{
			hp = 0; // 음수 체력을 0으로 보정
		}

		// 시스템 메시지
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// 1 ~ 10 사이의 홀수만 출력하기
	for (int count = 1; count < 10; count++) {
		bool isEven = ((count % 2) == 0);
		if (isEven)
		{
			continue;
		}
		cout << count << endl;
	}
}