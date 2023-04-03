#include <iostream>
using namespace std;

class Knight
{
public:
	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};

typedef int(*PFUNC)(int, int);
typedef int(Knight::*PMEMFUNC)(int, int); // 멤버 함수 포인터

static int HelloKnight(int x, int y)
{
	return 1;
}

int Test(int a, int b)
{
	return a + b;
}

int main()
{
	// [전역 함수 / 정적 함수]만 담을 수 있다. (호출 규약)
	PFUNC fn;
	

	fn = &HelloKnight;
	fn = &Test;

	Knight k;
	k.GetHp(1, 1);

	// 멤버 함수 포인터
	PMEMFUNC mfn;
	mfn = &Knight::GetHp;

	(k.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;
}