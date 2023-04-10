#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}

	// 이동 생성자
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;
		
		// 깊은 복사
		_hp = knight._hp;
		
		// 깊은 복사 => 공동 데이터가 되지 않는 대신에..
		// 복사에 많은 비용이 든다.
		if (knight._pet)
			_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// 얕은 복사를 하더라도? 공유 문제가 생기지 않음.
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}

	void PrintInfo()
	{

	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 200;
}

void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 200;
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	// 호환되지 않는 형식 지정자 const형 함수만 사용 가능.
	// knight.PrintInfo();
}


// 오른값 참조
void TestKnight_RValueRef(Knight&& knight) // 이동 대상 => 원본을 유지하지 않아도 된다.
{

}

// 오늘의 주제 : 오른값(rvalue) std::move
int main()
{
	// 왼값(lvalue) vs 오른 값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvaule가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

	int a = 3;

	Knight k1;

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);

	// 비 const 참조에 대한 초기값은 lvalue임
	// TestKnight_LValueRef(Knight());

	TestKnight_ConstLValueRef(k1);

	// rvalue 참조를 lvalue 바인딩 불가
	// TestKnight_RValueRef(k1);

	TestKnight_RValueRef(Knight());

	// 명시 변환해서 원본을 고칠 수 있게 k1 값을 보낸다. 
	TestKnight_RValueRef(static_cast<Knight&&>(k1));


	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다 << 는 Hint를 주는 쪽에 가까움.
	// 복사를 하지 않음 => 데이터를 이동함 => cost가 적게 듬.
	Knight k3;
	k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // 오른값 참조로 캐스팅
	// std::move의 본래 이름 후보 중 하나가 rvalue_cast

	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();

	// 불가능! => 포인터를 고유한 한개밖에 생성할수 없는 타입
	// std::unique_ptr<Knight> uptr2 = uptr;
	// 
	// 소유권 이전!
	std::unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}