#include <iostream>
using namespace std;

// 오늘의 주제 : 연산자 오버로딩(Opeartor Overloading)

// 연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버함수 vs 전역함수가 존재하는 것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음 

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽 기준으로 실행됨
// -- 한계) a가 클래스가 아니면 사용 못함.

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자]에 대해 알아보자
// 용어가 좀 헷갈린다. [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 - 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것.

class Position
{

public:
		
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}
	
	
	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		// Position* this = 내 자신의 주소;
		return *this;
	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유
	// 말 그대로 객체가 '복사'되길 원하는 특징 때문
	// arg가 가리키는 내용물을 변경할 수 없음.
	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		// Position* this = 내 자신의 주소;
		return *this;
	}
	
	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;

};

Position operator+(int arg, const Position& b)
{
	Position ret;
	ret._x = b._x + arg;
	ret._y = b._y + arg;

	return ret;
}

int& test(const int& x)
{
	int ret = 1 + x;

	return ret;
}

int testLocalVariable()
{
	int x = 10;
	return x;
}

int main()
{
	int a = 1;
	int b = 2;

	int c = a + 3.0f;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos._x = 0;
	pos._y = 0;

	Position pos3 = pos + pos2; 
	Position pos4 = pos3 + 1;
	
	Position pos5;
	// 1. (pos5 = 5) return &pos5
	// 2. pos3 = &pos5;

	pos3 = (pos5 = 5);
	// (const Pos&)줘 ~ (Pos) 복사
	//
	pos5 = pos3++;

	pos3++;
	++(++pos3);

	cout << test(testLocalVariable());
	


	return 0;
}														