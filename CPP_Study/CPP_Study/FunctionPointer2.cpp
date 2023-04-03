#include <iostream>
using namespace std;

class Knight
{
public:
	// ��� �Լ�
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};

typedef int(*PFUNC)(int, int);
typedef int(Knight::*PMEMFUNC)(int, int); // ��� �Լ� ������

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
	// [���� �Լ� / ���� �Լ�]�� ���� �� �ִ�. (ȣ�� �Ծ�)
	PFUNC fn;
	

	fn = &HelloKnight;
	fn = &Test;

	Knight k;
	k.GetHp(1, 1);

	// ��� �Լ� ������
	PMEMFUNC mfn;
	mfn = &Knight::GetHp;

	(k.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;
}