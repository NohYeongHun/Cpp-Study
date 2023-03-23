#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 마무리

// 1) 포인터 vs 배열 2탄
// 2) 주의사항 (마음가짐?)

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
 }

int main()
{
	// 주소를 담는 바구니
	// 진퉁은 저~ 멀리 어딘가에 있음
	// P는 단지 그 곳으로 워프하는 포탈
	int* p;

	// 진짜배기! 원조 데이터
	// 닭장처럼 데이터의 묶음 (엄청 많고 거대함)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	// 그런데 상당히 많은 사람들이 [배열 = 포인터]라 착각.
	// - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능.
	p = arr;

	// - [TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다.
	cout << p[0] << endl;
	cout << arr[0] << endl;
	cout << p[5] << endl;
	cout << arr[5 ] << endl;

	cout << *p << endl;
	cout << *arr << endl;
	cout << *(p + 3) << endl;
	cout << *(arr + 3) << endl;

	// 지옥을 보여드린다.. (2차원 배열 vs 다중 포인터)
	// [1][2][3][4]
	int arr2[2][2] = { {1, 2}, {3, 4} };

	// pp [ 주소1 ] => pp는 2중 포인터이므로 주소1은 주소를 담고 있다고 가정함.
	// 주소1 [ 주소2 (값 1) ] => 주소 1로 이동해보니 또다른 주소값을 가지고 있는 것이 아닌 arr[0][1] 값인 1이 있음.
	// 주소2[ ] << 4바이트
	// int** pp = arr2; 
	
	// TYPE name[개수]
	
	// 주소1 => [1][2] (값)
	// pp [ 주소1 ]
	int(*p2)[2] = arr2;
	

	cout << (*p2)[0] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << p2[0][0] << endl;
	cout << p2[1][0] << endl;
	
	// [매개변수][RET][지역변수] / [매개변수][RET][지역변수]
	int* pointer = TestPointer();

	TestWrong(pointer);

	return 0;

}