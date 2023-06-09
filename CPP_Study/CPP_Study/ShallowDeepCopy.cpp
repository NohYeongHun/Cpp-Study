#include <iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사

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

	// 복사 생성자
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
	Knight knight; // 기본 생성자
	knight._hp = 200;
	knight._level = 99;
	knight._pet._hp -= 1;
	
	cout << "---------------- 복사 생성자 -----------" << endl;
	//Knight knight2 = knight; // 복사 생성자

	Knight knight3; // 기본 생성자

	cout << "---------------- 복사 대입 연산자 -----------" << endl;
	knight3 = knight; // 복사 대입 연산자

	 
	// 실험)
	// - 암시적 복사 생성자 Steps
	/*
	1. 부모 클래스의 복사 생성자 호출
	2. 멤버 클래스의 복사 생성자 호출
	3. 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
	*/


	// - 명시적 복사 생성자 Steps
	/*
	1. 부모 클래스의 기본 생성자 호출
	2. 멤버 클래스의 기본 생성자 호출
	*/

	return 0;
}