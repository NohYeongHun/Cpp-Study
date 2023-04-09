#include <iostream>
using namespace std;

// 오늘의 주제 : delete (삭제된 함수)

class Knight
{
public:

private:
	// 정의되지 않은 비공개(private 함수)
	// 외부에서는 사용불가하지만?? => 내부적으로는 사용가능.
	// void operator=(const Knight& k);

	// delete 사용시? => 삭제된 함수! 사용이 불가하다.
	void operator=(const Knight& k) = delete;
	

	// friend class를 사용한다면 Admin에게 prviate 부분을 제공한다.
	friend class Admin;

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산 => delete 사용시 불가능.
		// k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// 복사 연산자를 막고싶다면?
	// 복사 연산자 예시
	// k1 = k2;
	Admin admin;


	return 0;
}