#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)

// class는 일종의 설계도

// 메모리

// [ [ Player ] ]
// [ Knight ]

// 생성자(N) / 소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?

// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택 ! 그냥 둘 다 호출하자.

class Player
{

public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp)생성자 호출" << endl;

	}

	~Player()
	{
		cout << "Player() 기본 소멸자 호출" << endl;
	}

	void Move() { cout << "Move 호출" << endl; }
	void Attack() { cout << "Attack 호출" << endl; }
	void Die() { cout << "Die 호출" << endl; }
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
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "Knight() 기본 소멸자 호출" << endl;
	}

	

	void Move() { cout << "Move 호출 재정의" << endl; }

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