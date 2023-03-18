#include <iostream>
using namespace std;

// 오늘의 주제 : 호출 스택

// 함수 선언
void Func1();
void Func2(int a, int b);
void Func3(float a);

// 구현부
void Func1()
{
	cout << "Func1" << endl;

	// push 1
	// push 2
	// call Func2 <= 어디로??
	// 미리 선언함으로써 해결.
	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

int main()
{
	cout << "main" << endl;
	Func1();
	cout << "Func 탈출" << endl;
}