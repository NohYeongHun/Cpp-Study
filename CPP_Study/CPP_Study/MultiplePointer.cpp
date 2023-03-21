#include <iostream>
using namespace std;


// 오늘의 주제 : 다중 포인터
void SetNumber(int* a);
void SetMessage(const char* a);
void SetMessage(const char** a);
void SetMessage2(const char*& a);

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}
void SetMessage(const char** a)
{
	*a = "Bye";
}
void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);

	// .rdata Hello주소[H][e][l][l][o][\0]
	// msg [ Hello 주소 ] << 8바이트

	// msg[ 주소 ] << 8바이트
	const char* msg = "Hello";

	// [매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(Hello 주소))][RET][지역변수]
	SetMessage(msg);
	//cout << msg << endl; // Hello? Bye?

	// 주소2 [ ] << 1바이트
	// 주소1 [ 주소 2 ] << 8바이트
	// pp[ 주소1 ] << 8바이트
	const char** pp = &msg; 
	// => pp의 내용물은 무조건 const char* 타입이어야 함.
	// pp [ &msg ] << 8바이트
	// msg [ Hello 주소 ] << 8바이트

	// [매개변수][RET][지역변수(msg( Hello 주소 ))] [매개변수(a(&msg msg의 주소))][RET][지역변수]
	SetMessage(&msg);
	cout << msg << endl;
	// 값이 변경됨.

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}