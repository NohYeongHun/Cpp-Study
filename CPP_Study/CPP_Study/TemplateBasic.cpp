#include <iostream>
using namespace std;

// ������ ���� : ���ø� ����

class Player
{
public:

public:
	int _hp = 100;
};

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}


template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// ������ �����ε� (�����Լ� ����)
ostream& operator<<(ostream& os, const Player& p)
{
	os << p._hp;
	return os;
}

// ���ø� Ư��ȭ
template<>
void Print(Player a)
{
	cout << "Player !!!!!!!!!!!!!" << endl;
	cout << a._hp << endl;
}

int main()
{
	// ���ø� : �Լ��� Ŭ������ ���� Ʋ
	Print<int>(50);
	Print(50.01f);
	Print(50.03);
	Print<const char*>("Hello World");

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.f, 2.5f);

	Player p;
	Print(p);
	

	return 0;
}