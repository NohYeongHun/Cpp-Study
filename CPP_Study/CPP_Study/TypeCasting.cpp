#include <iostream>
using namespace std;

// 오늘의 주제 : 타입 변환

// malloc -> void*을 반환하고, 이를 우리가 (타입 변환)을 통해 사용

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog();

	// 타입 변환 생성자
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}

	// 타입 변환 연산자
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;
};

class BullDog : public Dog
{
public:
	bool _french; // 프렌치 불독
};

int main()
{
	// -------------------- 타입 변환 유형 (비트열 재구성 여부) ---------------

	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성

	{
		int a = 123456789; // 2의 보수
		float b = (float)a; //부동 소수점(지수 + 유효숫자)
		cout << b << endl;
	}
	
	// [2] 참조 타입 변환
	// 특징) 비트열을 재구성하지 않고, `관점`만 바꾸는 것
	{
		int a = 123456789; // 2의 보수
		float b = (float&)a; //부동 소수점(지수 + 유효숫자)
		cout << b << endl;
	}


	// 안전도 분류

	// 안전한 변환
	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	// 불안전한 변환
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// -------------------- 프로그래머 의도에 따라 분류 ----------------

	// [1] 암시적 변환
	
	{
		int a = 123456789;
		float b = a; //암시적으로
		cout << b << endl;
	}

	// [2] 명시적 변환
	{
		int a = 123456789;
		int* b = (int*)a; // 명시적으로
		cout << b << endl;
	}

	// ------------------- 아무런 연관 관계가 없는 클래스 사이의 변환 -----------------

	// [1] 연관없는 클래스 사이의 '값 타입' 변환
	// 특징) 일반적으로 안됨
	{
		Knight knight;
		Dog dog = (Dog)knight;

		//Knight knight2 = dog;
	}

	// [2] 연관없는 클래스 사이의 참조 타입 변환
	{
		Knight knight;
		Dog& dog = (Dog&)knight;
		dog._cuteness = 12;

	}

	// ----------------- 상속 관계에 있는 클래스 사이의 변환 ----------------

	// [1] 상속 관계 클래스의 값 타입 변환

	{
		//Dog dog;
		//BullDog bullDog;

		BullDog bullDog;
		Dog dog = bullDog;
	}
	
	//[2] 상속 관계 클래스의 참조 타입 변환
	// 특징) 자식 -> 부모 OK / 부모-> 자식 (암시적NO) (명시적 OK)
	{
		BullDog bullDog;

		Dog& dog = bullDog;
	}

}