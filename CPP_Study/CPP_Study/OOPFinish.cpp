#include <iostream>
using namespace std;

// ������ ���� : ��ü���� ������

// 1) struct vs class

// C++ ������ struct�� class�� ���� ���� ���̴�.

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};

// 2) static ����, static �Լ�, (static = ���� = ������)

class Marine
{

public:
	int _hp;

	// Ư�� ���� �ν��Ͻ��� hp���� �����.
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// ���������� ����.
	static void SetAttack(int damage)
	{
		s_attack += damage;
	}

	static int s_attack; // ���赵 �����θ� ����.
};

int Marine::s_attack = 6;

class Player
{

public:
	int _id;
};

int GenerateId()
{
	// �����ֱ� : ���α׷� ���� / ����;
	// ���ù���;
	
	// ���� ���� ��ü
	static int s_id = 1;

	return s_id++;
}



int main()
{
	TestStruct ts;
	ts._a = 1;

	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);
	
	Marine m2;
	m2._hp = 40;
	m2.TakeDamage(10);
	
	// ���� ���ݷ� ���׷��̵� �Ϸ�! 
	Marine::s_attack = 7;
	// ���� �⺻ ������ ���� �Ϸ�.
	Marine::SetAttack(10);

	// ���� �ƴ�. .data ����
	static int id = 10;
	int a = id;


	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
}



