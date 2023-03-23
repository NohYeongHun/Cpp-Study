#include <iostream>
using namespace std;

// ������ ���� : �����ڿ� �Ҹ���

// class�� ������ ���赵
// [������(Constructor)�� �Ҹ���(Destuctor)]
// Ŭ������ '�Ҽ�'�� �Լ����� ����Լ���� ��
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���
// - ����(ź��) -> ������ (������ ���� ����)
// - ��(�Ҹ�) -> �Ҹ��� ( ���� 1���� )


// [�Ͻ���(Implicit) ������]
// �����ڸ� ��������� ������ ������,
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������
// -> �׷��� �츮�� �����(Explicit)���� �ƹ� ������ �ϳ��� �����
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� ����.

class Knight
{

public:
	// [1] �⺻ ������ (���ڰ� ����)
	Knight()
	{
		cout << "Kngiht() �⺻ ������ ȣ��" << endl;

		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] ���� ������ (�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����)
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ���)
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._hp;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] ��Ÿ ������ �����ε� (���ڰ� ����)
	explicit Knight(int hp)
	{
		cout << "Kngiht() �⺻ ������ ȣ��" << endl;

		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// �Ҹ���
	~Knight()
	{
		cout << "Kngiht() �⺻ �Ҹ��� ȣ��" << endl;
	}


	// ��� �Լ�
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		this->_hp = 1; //����
		_hp = 0;
		_attack = 0;
		cout << "Die" << endl;
	};

public:
	// ��� ����
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "attack : " << _attack << endl;
}

void Move(Knight* knight, int y, int x)
{
	cout << "Move" << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// instantiate ��ü�� �����!
int main()
{
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1);
	
	// ������ ���ÿ� ���� => ���� ������
	Knight k3 = k1;

	Knight k4; // ������
	
	k4 = k1; // ����

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	Knight k5;
	//k5 = 1;

	//HelloKnight(5);

	return 0;


}