#include <iostream>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자

// class는 일종의 설계도
// [생성자(Constructor)와 소멸자(Destuctor)]
// 클래스에 '소속'된 함수들을 멤버함수라고 함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// - 끝(소멸) -> 소멸자 ( 오직 1개만 )


// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나를 만들면
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음.

class Knight
{

public:
	// [1] 기본 생성자 (인자가 없음)
	Knight()
	{
		cout << "Kngiht() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대)
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._hp;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] 기타 생성자 오버로딩 (인자가 있음)
	explicit Knight(int hp)
	{
		cout << "Kngiht() 기본 생성자 호출" << endl;

		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// 소멸자
	~Knight()
	{
		cout << "Kngiht() 기본 소멸자 호출" << endl;
	}


	// 멤버 함수
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		this->_hp = 1; //생략
		_hp = 0;
		_attack = 0;
		cout << "Die" << endl;
	};

public:
	// 멤버 변수
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

// instantiate 객체를 만든다!
int main()
{
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1);
	
	// 생성과 동시에 복사 => 복사 생성자
	Knight k3 = k1;

	Knight k4; // 생성자
	
	k4 = k1; // 복사

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	Knight k5;
	//k5 = 1;

	//HelloKnight(5);

	return 0;


}