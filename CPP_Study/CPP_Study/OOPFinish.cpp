#include <iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class

// C++ 에서는 struct나 class나 종이 한장 차이다.

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

// 2) static 변수, static 함수, (static = 정적 = 고정된)

class Marine
{

public:
	int _hp;

	// 특정 마린 인스턴스의 hp값만 변경됨.
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 독립적으로 동작.
	static void SetAttack(int damage)
	{
		s_attack += damage;
	}

	static int s_attack; // 설계도 상으로만 존재.
};

int Marine::s_attack = 6;

class Player
{

public:
	int _id;
};

int GenerateId()
{
	// 생명주기 : 프로그램 시작 / 종료;
	// 가시범위;
	
	// 정적 지역 객체
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
	
	// 마린 공격력 업그레이드 완료! 
	Marine::s_attack = 7;
	// 마린 기본 데미지 설정 완료.
	Marine::SetAttack(10);

	// 스택 아님. .data 영역
	static int id = 10;
	int a = id;


	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
}



