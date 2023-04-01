#include <iostream>
using namespace std;

class Player
{
	virtual ~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Knight : public Player
{
public:
	Knight();
};

class Archer : public Player
{
public:

};

class Dog
{

};

// ������ ���� : ĳ���� (Ÿ�� ��ȯ)
// 1) static cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ���
	// 1) int <-> float
	// 2) Player* -> Knight* (�ٿ�ĳ����)
	
	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;
	cout << ratio << endl;

	// �θ�->�ڽ� �ڽ�-> �θ�
	Player* p = new Player();
	Knight* k1 = static_cast<Knight*>(p);

	Knight* k = new Knight();
	Player* p2 = static_cast<Player*>(k);

	// dynamic_cast : ��� ���迡���� ������ �� ��ȯ ����
	// RTTI (RunTime Type Information)
	// virtual �Լ��� �ϳ��� �����, ��ü�� �޸𸮿� ���� �Լ� ���̺� (vftable) �ּҰ� ���Եȴ�.
	// �������� Ȱ��
	Knight* k2 = dynamic_cast<Knight*>(p);

	// const_cast : const�� ���̰ų� ���ų�~
	
	// const_cast�� ���ų�~.
	PrintName(const_cast<char*>("Rookis"));

	// reinterpret_cast
	// ���� �����ϰ� ������ ������ ĳ����
	// 're-interpret' : �ٽ�-�����ϴ�/�����ϴ�
	// -�����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	Dog* dog = reinterpret_cast<Dog*>(p);

}