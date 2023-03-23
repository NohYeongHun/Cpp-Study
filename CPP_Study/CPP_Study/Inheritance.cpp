#include <iostream>
using namespace std;

// ������ ���� : ��Ӽ�

// ��ü���� (OOP Object Oriented Programming)

// class�� ������ ���赵

// �޸�

// [ [ Player ] ]
// [ Knight ]

// ������(N) / �Ҹ���(1)

// �����ڴ� ź���� ����ؼ� ȣ��Ǵ� �Լ�?

// - Knight�� �����ϸ� -> Player�� ������? Knight�� ������?
// -> �ַθ��� ���� ! �׳� �� �� ȣ������.

class Player
{

public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() �⺻ ������ ȣ��" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp)������ ȣ��" << endl;

	}

	~Player()
	{
		cout << "Player() �⺻ �Ҹ��� ȣ��" << endl;
	}

	void Move() { cout << "Move ȣ��" << endl; }
	void Attack() { cout << "Attack ȣ��" << endl; }
	void Die() { cout << "Die ȣ��" << endl; }
public:
	int _hp;
	int _attack;
	int _defence;
};



class Knight : public Player
{
public:
	Knight()
	{
		_stamina = 0;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		_stamina = stamina;
		cout << "Knight(int stamina) ������ ȣ��" << endl;
	}

	~Knight()
	{
		cout << "Knight() �⺻ �Ҹ��� ȣ��" << endl;
	}

	

	void Move() { cout << "Move ȣ�� ������" << endl; }

public:
	int _stamina;
};

int main()
{
	Knight k(100);
	/*k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;
	k.Move();
	k.Player::Move();
	k.Attack();
	k.Die();*/
}