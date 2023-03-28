#include <iostream>
using namespace std;

// ������ ���� : �ʱ�ȭ ����Ʈ

// ��� ���� �ʱ�ȭ? �پ��� ������ ����

// �ʱ�ȭ �� �ؾ��ұ�? ������
// - ���� ���濡 �߿�
// - ������ �� �ּҰ��� ����Ǿ� ���� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++11 ����

// �ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� ������ ȣ�� �� �ʿ��ϴ�.
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����.
// �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (���� Ÿ��, const Ÿ��)

class Inventory
{

public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; }

	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};

class Player
{

public:
	Player(){}
	Player(int id) {} 

};

// Is-A (Knight is-A player? ���� �÷��̾�� ) OK -> ��Ӱ���
// Is-A (Knight is-A Inventory? ���� �κ��丮��? ) X -> ��Ӱ����ΰ�? ���԰��� ����.
// 
// Has-A (Knight Has-A Inventory?); ���� �κ��丮�� �����ϰ� �ִ� O -> ���԰���

class Knight : public Player
{

public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		��ó�� ����

		Inventory()
		*/
	{
		 
	}

public:
	int _hp; // ������ ��
	Inventory _inventory;

	int& _hpRef;
	const int _hpConst;

};

int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
	{
		cout << "Knight Die" << endl;
	}

	return 0;

}