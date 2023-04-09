#include <iostream>
using namespace std;
#include<vector>
#include<map>

class Knight
{
public:
	int _ho;

	Knight()
	{

	}
	
	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	// 우선 순위가 제일 높음
	Knight(initializer_list<int> li)
	{
		cout << "Knight(initializer list)" << endl;
	}
};

int main()
{
	// 중괄호 초기화 { }

	int a = 0;
	int b{ 0 };
	int c{ 0 };

	Knight k1;
	k1._ho = 1;
	// 복사 생성자 => 생성과 동시에 초기화 (대입 연산자 X)
	Knight k2 = k1; 
	
	// 기본 생성자
	Knight k3; 
	// 복사 대입 연산자 => 생성 후 초기화
	k3 = k1; 

	Knight k4{ k2 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);
	int arr[] = { 1, 2, 3, 4 };
	
	
	// 중괄호 초기화
	// 1) vector 등 container와 잘 어울린다.
	vector<int> v3{ 1, 2, 3, 4 };

	// 2) 축소 변환 방지 => 데이터 손실 방지.
	int x = 0;
	// double y{ x };

	// 3) Bonus
	// k4는 문법적으로 Knight 타입 객체를 반환하는 함수이다.
	// Knight k4();
	// 온전한 기본 생성자로 생성.
	Knight k5{};

	/*
		initalize_list를 추가한다면
		같은 타입을 사용하는 
		다른 모든 버전보다 우선순위를 가진다.
	*/
	Knight k6{3, 3};

	// 괄호 초기화 ()를 기본으로 간다
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용

	// 중괄호 초기화 { }를 기본으로 간다.
	// - 초기화 문법의 일치화
	// - 축소 변환 방지

	return 0;

}