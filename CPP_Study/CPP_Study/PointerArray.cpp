#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 배열

void Test(int a)
{
	a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다.
// 즉 배열의 내용 전체를 넘긴게 아니라, 시작 주소(포인터)만 넘긴것.
void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// .data 주소 [H][e][l][l][o][][W][o][r][l][d][\0]
	// test1[ 주소 ] << 8바이트
	const char* test1 = "Hello World"; // => test1 => ["Hello World"의 주소값] 크기는 8byte
	// test[1] = 'R';

	// .data 주소 [H][e][l][l][o][][W][o][r][l][d][\0]
	// [H][e][l][l][o][][W][o][r][l][d][\0]
	// test2[ 주소 ] (X)
	char test2[12] = "Hello World"; // =>  test2의 크기 => 12(배열의크기) * 1(자료형 type 크기)

	cout << test2 << endl;

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소]

	int a = 0;
	// [매개변수][RET][지역변수(a=0)] [매개변수(a=0)][RET][지역변수]
	Test(a);
	cout << a << endl;

	// 배열을 함수의 인자로 넘기게 된다면?
	// 변화가 일어난다.
	// 배열 타입의 변수이름은 배열의 시작주소임 
	// 이를 복사해서 함수에 넘겨준다면 배열의 시작주소를 넘겨주는 것과 같다.
	Test(test2);
	cout << test2 << endl;
	
	


}