#include <iostream>
using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}

	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet&)" << endl;
		return *this;
	}

public:
	int _hp = 10;
};

class Player
{

public:
	Player()
	{
		cout << "Player()" << endl;
	}

	// ���� ������
	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}

	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		return *this;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		
	}

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		cout << "Knight(const Knight&)" << endl;
		_hp = knight._hp;
	}

	Knight& operator=(const Knight& knight)
	{
		cout << "opeartor=(const Knight&)" << endl;

		Player::operator=(knight);
		_pet = knight._pet;
		_hp = knight._hp;

		return *this;
	}

	~Knight()
	{
		
	}

public:
	int _hp = 100;
	Pet _pet;
};

int main()
{
	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._level = 99;
	knight._pet._hp -= 1;
	
	cout << "---------------- ���� ������ -----------" << endl;
	//Knight knight2 = knight; // ���� ������

	Knight knight3; // �⺻ ������

	cout << "---------------- ���� ���� ������ -----------" << endl;
	knight3 = knight; // ���� ���� ������


	// ����)
	// - �Ͻ��� ���� ������ Steps
	/*
	1. �θ� Ŭ������ ���� ������ ȣ��
	2. ��� Ŭ������ ���� ������ ȣ��
	3. ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	*/


	// - ����� ���� ������ Steps
	/*
	1. �θ� Ŭ������ �⺻ ������ ȣ��
	2. ��� Ŭ������ �⺻ ������ ȣ��
	*/

	return 0;
}