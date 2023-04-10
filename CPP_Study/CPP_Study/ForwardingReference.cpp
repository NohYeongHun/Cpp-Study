#include <iostream>
using namespace std;

// 오늘의 주제 : 전달 참조(forwarding reference)

class Knight
{
public:
	Knight() { cout << "기본 생성자" << endl; }
	Knight(const Knight&) { cout << "복사 생성자" << endl; }
	Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }
};


void Test_RValueRef(Knight&& k) // 오른값 참조
{

}

void Test_Copy(Knight k)
{

}

template<typename T>
void Test_ForwardingRef(T&& param)
{
	// TODO
	// 왼값이면 => move를 수행하면 안된다!.
	// std::move(param);
	// 
	// std::move(param)을 통해 다시 오른값으로 만들어야
	// 의도한대로 이동 생성자를 통한 데이터 이동을 수행할 것.
	//Test_Copy(std::move(param));

	// 왼값 참조라면 복사
	// 
	// 오른값 참조라면 이동
	// 둘의 문제를 해결해주는 문법 forward가 있음. 
	Test_Copy(std::forward<T>(param));
}


int main()
{

	// 보편 참조(universal reference)
	// 전달 참조(forwarding reference) C++ 17

	// && &를 두 번 -> 오른값 참조

	Knight k1;
	Test_RValueRef(std::move(k1)); // rvalue_cast

	Test_ForwardingRef(k1); // lvalue cast
	Test_ForwardingRef(std::move(k1));
	
	// 왼값 참조로 변경
	auto&& k2 = k1;
	auto&& k3 = std::move(k1);

	// 공통점 : 형식 연역 (type deduction)이 일어날 떄만 발생.
	// 왼값 참조로 넣으면 => 왼값 참조로 작동
	// 오른값 참조로 넣으면 => 오른값 참조로 작동
	// const를 붙이면? => 오른값 참조로만 작동한다.

	// 전달 참조를 구별하는 방법
	// ------------------------------

	Knight& k4 = k1; // 왼값 참조
	Knight&& k5 = std::move(k1); // 오른값 참조


	// 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용 불가능.
	// 오른값 참조 : 오른값만 참조할 수 있는 참조 타입. 
	// 오른값 참조는? => 단일식에서 벗어나도 사용 가능.
	// std::move(k5)를 통해 임시값을 매개변수로 넘겨준다.
	// Test_RValueRef(std::move(k5));

	Test_ForwardingRef(k1);
	Test_ForwardingRef(std::move(k1));

	return 0;
}