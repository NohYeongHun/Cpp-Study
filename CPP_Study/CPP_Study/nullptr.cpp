#include <iostream>
using namespace std;

// 오늘의 주제 : nullptr

class Knight
{
public:
	void Test(){ } ;
};

Knight* FindKnight()
{
	// TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// NullPtr 구현

// 싱글톤 같은 느낌?
class
{
public:

	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const; // 주소값 &을 막는다.

} _nullptr;


int main()
{
	// 0 NULL
	int* ptr = nullptr;

	// 1) 오동작 방지
	// 둘 다 int 타입 매개변수인 함수가 호출된다!.
	Test(0);
	Test(NULL);

	// 포인터 타입이 매개변수인 함수가 호출된다!.
	Test(nullptr);
	Test(_nullptr);

	// 2) 가독성
	auto knight = FindKnight();
	if (knight == nullptr)
	{

	}

	Knight* kngiht2 = FindKnight();
	if (kngiht2 == _nullptr)
	{

	}

	void (Knight::* memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _nullptr)
	{

	}

	nullptr_t whoami = nullptr;
	

	return 0;
}