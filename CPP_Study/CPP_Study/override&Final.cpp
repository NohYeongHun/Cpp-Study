#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// ������ ���� : override, final

class Creature
{
	virtual void Attack()
	{

	}
};

class Player : public Creature
{

public:

	// �����Լ� : ���� ���� ��ü�� �Լ��� ȣ���Ѵ�!.
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	}

};

class Knight : public Player
{
public:

	// ������(override)
	

	// const�� �ٿ��� ��������? => �ٸ� �Լ��̴�.
	// virtual void Attack() const

	// ��������� override�� �Լ���� ���� �˷��ָ� ���ڴ�!.

	/*
		�ڽ� Ŭ������ Ȯ���ؼ��� virtual�� �θ� Ŭ������ ���ǵǾ����� Ȯ�� �Ұ���.
		override�� ���̸�!
		Player���� Attack() �Լ��� ���ǵǾ� �ִٴ� ���� �� �� �ִ�.

		final��? => �ڽ� Ŭ�������� �ش� �Լ��� override�� ���´�.
	*/
	virtual void Attack() override final
	{
		cout << "Knight!" << endl;
	}
	

	// �����ε�(overloading) : �Լ� �̸��� ����
	/*
	* void Attack(int a)
	{
		cout << "Attack! (int a)" << endl;
	}
	*/

private:
	int _stamina = 100;
	
};


class Test : public Knight
{
	virtual void Attack() override;
};

int main()
{
	// �Ұ���! => �θ� Creature���� virtual�� ����Ǿ� ���� ����
	// Creature* creature = new Knight()
	Player* player = new Knight();

	player->Attack();

	delete player;
	return 0;
}